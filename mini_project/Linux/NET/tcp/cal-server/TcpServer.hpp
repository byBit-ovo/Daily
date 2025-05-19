#include "inet_addr.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>
#include "log.hpp"
#include <memory>
#include "Protocol.hpp" //两端达成协议
#define BACKLOG 8

using task_t = std::function<std::string(std::string&)>;

class TcpServer
{
public:
    TcpServer(uint16_t port, task_t task) : _port(port), _isrunning(false), _task(task)
    {
        _listen_socket = ::socket(AF_INET, SOCK_STREAM, 0);
        if (_listen_socket < 0)
        {
            LOG(logLevel::ERROR) << "socket error";
            DIE(SOCKERROR);
        }
        LOG(logLevel::INFO) << "_listen_socket is " << _listen_socket;
        netAddr self(_port);
        if (::bind(_listen_socket, &self, self.size()) != 0)
        {
            LOG(logLevel::ERROR) << "bind error";
            DIE(BINDERROR);
        }
        if (::listen(_listen_socket, BACKLOG) != 0)
        {
            LOG(logLevel::ERROR) << "listen error :" << strerror(errno);
            DIE(LISTENERROR);
        }
        LOG(logLevel::INFO) << "listen status set successfully";
    }

    void start()
    {
        if (_isrunning == false)
        {
            while (true)
            {
                struct sockaddr_in peer;
                socklen_t len = sizeof(peer);
                int sockfd = ::accept(_listen_socket, CONV(&peer), &len);
                if (sockfd < 0)
                {
                    LOG(logLevel::ERROR) << "accept error";
                    continue;
                }
                netAddr peerInfo(peer);
                LOG(logLevel::INFO) << "新客户端连接 : " << "ip: " << peerInfo.getIp() << " port: " << peerInfo.getPort();
                // 多线程模式
                pthread_t tid;
                threadData *dataforthread = new threadData(sockfd, this);
                int n = ::pthread_create(&tid, nullptr, threadEntry, dataforthread);
                if (n != 0)
                {
                    LOG(logLevel::ERROR) << "pthread_create error";
                }
            }
        }
    }

    class threadData
    {
    public:
        threadData(int sockfd, TcpServer *ptr) : _sockfd(sockfd), _ptr(ptr) {}
        uint16_t _sockfd;
        TcpServer *_ptr;
    };
    static void *threadEntry(void *arg)
    {
        pthread_detach(pthread_self());
        threadData *data = (threadData *)arg;
        data->_ptr->Handler_Task(data->_sockfd);
        return nullptr;
    }
    void Handler_Task(int sockfd) // tcp连接后，不需要客户端ip和port,只需要拿着socket做消息传递
    {
        LOG(logLevel::INFO) << "Handler_Task,sockfd is " << sockfd;
        char buffer[1024];
        std::string package;
        while (true)
        {
            int n = ::recv(sockfd, buffer, sizeof(buffer) - 1, 0);
            if (n > 0)
            {
                // 业务处理，回调函数
                LOG(logLevel::INFO) << "server recv: " << buffer;
                package += buffer;
                std::string ret = _task(package);
                if (ret.empty())
                    continue;
                LOG(logLevel::INFO) << "server send: " << ret;
                int n = ::send(sockfd, ret.c_str(), ret.size(), 0);
                if (n < 0)
                {
                    LOG(logLevel::ERROR) << "send error :" << strerror(errno);
                }
            }
            else if (n == 0)
            {
                LOG(logLevel::WARNING) << "客户端已经退出...";
                std::cout << "客户端已经退出..." << std::endl;
                break;
            }
            else
            {
                LOG(logLevel::ERROR) << "recv error :" << ::strerror(errno);
                break;
            }
        }

        ::close(sockfd);
        LOG(logLevel::INFO) << sockfd << "closed";
    }

private:
    int _listen_socket;
    uint16_t _port;
    bool _isrunning;
    task_t _task;
};