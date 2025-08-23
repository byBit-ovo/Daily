#include "inet_addr.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>
#include "threadpool.hpp"
#include "Users.hpp"

uint16_t dftport = 8080;

using dlt_user_t = std::function<bool(const User &)>;
using add_user_t = std::function<bool(const User &)>;
using bc_t = std::function<void(int socket, const std::string &messgae, const User &self)>;
using task_t = std::function<void()>;

class nocopy
{
public:
    nocopy(){}
    virtual ~nocopy(){}
    nocopy(const nocopy& other) = delete;
    const nocopy& operator=(const nocopy& other) = delete;
};

class udp_server :public nocopy
{
public:
    udp_server(uint16_t port = 8080) : _addr(port) {}

    void initServer()
    {
        _socket = socket(AF_INET, SOCK_DGRAM, 0);
        if (_socket < 0)
        {
            LOG(logLevel::FATAL) << "socket creat fail";
            DIE(1);
        }
        LOG(logLevel::FATAL) << "socket is " << _socket;
        int n = bind(_socket, &_addr, _addr.size());
        if (n != 0)
        {
            LOG(logLevel::WARNING) << "Error : bind";
            DIE(2);
        }
        LOG(logLevel::INFO) << "bind success";
    }

    void resigter(dlt_user_t del, bc_t broad_cast, add_user_t add)
    {
        _del = del;
        _broad_cast = broad_cast;
        _add = add;
    }
    void start()
    {

        while (true)
        {
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            char buffer[1024];
            int n = recvfrom(_socket, buffer, 1023, 0, CONV(&peer), &len);
            if (n > 0)
            {
                buffer[n] = 0;
                std::string message;
                netAddr clientInfo(peer);
                if (strcmp(buffer, "QUIT") == 0)
                {
                    if (_del(User(clientInfo)))
                    {
                        message = clientInfo.name() + "离开了";
                    }
                    // if(_add(User(clientInfo)))
                    // {
                    //     std::string notice = clientInfo.name() + "来啦";
                    //     task_t notify = std::bind(udp_server::_broad_cast, _socket, notice, User(clientInfo));
                    //     threadPool<task_t>::getInstance()->enQueue(notify);
                    // }
                }
                else
                {
                    if (_add(User(clientInfo)))
                    {
                        message = clientInfo.name() + "来啦\n";
                    }
                    // 入线程池
                    message += clientInfo.name() +": "+ std::string(buffer);
                }

                task_t broad_cast = std::bind(udp_server::_broad_cast, _socket, message, User(clientInfo));
                threadPool<task_t>::getInstance()->enQueue(broad_cast);
            }
        }
    }

    ~udp_server()
    {
        ::close(_socket);
    }

private:
    int _socket;
    netAddr _addr;
    dlt_user_t _del;
    bc_t _broad_cast;
    add_user_t _add;
};