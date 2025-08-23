#include "socket.hpp"
#include <sys/epoll.h>
#include <sys/poll.h>
#include <sys/select.h>

#define gDefaultSize 1024

const int gDefaultVal = -1;

class epoll_Server
{
private:
    struct epoll_event _revs[1024];
    int _epfd = -1;
    SockPtr _listen_fd;
    bool _isrunning;
    uint16_t _port;

public:
    epoll_Server() : _listen_fd(std::make_shared<TcpSocket>()),
                     _isrunning(false) {}
    ~epoll_Server() {}

    void init(uint16_t port)
    {
        _port = port;
        _listen_fd->Build_Socket(port);
        // 创建epoll实例，在内核中维护红黑树和就绪队列
        _epfd = epoll_create(1);
        if (_epfd < 0)
        {
            LOG(logLevel::FATAL) << "Epoll_create error!";
            exit(1);
        }
        // 将监听描述符加入epoll模型
        struct epoll_event ev;
        ev.events = EPOLLIN;
        ev.data.fd = _listen_fd->Fd();
        int n = epoll_ctl(_epfd, EPOLL_CTL_ADD, _listen_fd->Fd(), &ev);
        if(n<0)
        {
            LOG(logLevel::ERROR) << "Epoll_ctl adding listen socket error!";
            exit(1);
        }
    }

    void Loop()
    {
        _isrunning = true;
        int timeout = 10000;
        while (_isrunning)
        {

            int n = epoll_wait(_epfd, _revs,1024, timeout);

            switch (n)
            {
            case -1:
                LOG(logLevel::DEBUG) << "Poll error";
                exit(1);
                break;
            case 0:
                LOG(logLevel::DEBUG) << "No fd is ready...";
                break;
            default:
                LOG(logLevel::INFO) << n << " Fd" << (n > 1 ? "s are" : " is") << "ready";
                Dispatcher(n);
                break;
            }
        }
    }

private:
    void Dispatcher(int fdNum)
    {
        for (int i = 0; i < fdNum; ++i)
        {
            int fd = _revs[i].data.fd;
            auto event = _revs[i].events;
            if (event & EPOLLIN)
            {
                if (fd == _listen_fd->Fd())
                    Accepter();
                else
                    Recv(fd);
            }
        }
    }
    void Accepter()
    {
        // EAGAIN;
        // EWOULDBLOCK;
        LOG(logLevel::INFO) << "Listen fd is ready!";
        netAddr client;
        int newfd = _listen_fd->Accept(client);
        if (newfd < 0)
        {
            return;
        }
        struct epoll_event ev;
        ev.events = EPOLLIN;
        ev.data.fd = newfd;
        int n = epoll_ctl(_epfd, EPOLL_CTL_ADD, newfd, &ev);
        if (n < 0)
        {
            LOG(logLevel::WARNING) << "Epoll_ctl error!";
            close(newfd);
            return;
        }
        LOG(logLevel::INFO) << "New client " << "is connected!";
        LOG(logLevel::INFO) << "Newfd is : " << newfd;
        // int i = 0;
        // for (; i < gDefaultSize; ++i)
        // {
        //     if (_fds[i].fd == gDefaultVal)
        //     {
        //         _fds[i].fd = newfd;
        //         _fds[i].events = POLLIN;
        //         break;
        //     }
        // }
        // if (i == gDefaultSize)
        // {
        //     LOG(logLevel::WARNING) << "server is full... abandon a newfd...";
        // }
    }
    void Recv(int fd)
    {
        LOG(logLevel::INFO) << "Normal read fd is ready!";
        char buffer[1024];
        int n = recv(fd, buffer, sizeof(buffer), 0);
        if (n < 0)
        {
            LOG(logLevel::ERROR) << "Read from fd(" <<fd<< ")error";
            ::close(fd);
        }
        else if (n == 0)
        {
            LOG(logLevel::INFO) << "Client is quited!";
            ::close(fd);
            // _fds[i].fd = gDefaultVal;
            // _fds[i].events = _fds[i].revents = 0;
        }
        else
        {
            buffer[n] = 0;
            std::cout << "Get: " << buffer;
            std::string message = "Server reply: ";
            message += buffer;
            int n = send(fd, message.c_str(), message.size(), 0);
            if (n < 0)
            {
                LOG(logLevel::INFO) << "Send error";
            }
        }
    }
};
