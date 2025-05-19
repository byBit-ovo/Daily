#include "socket.hpp"
#include <sys/poll.h>
#include <sys/select.h>
#define gDefaultSize 1024

const int gDefaultVal = -1;

class poll_Server
{
private:
    struct pollfd _fds[gDefaultSize];
    SockPtr _listen_fd;
    bool _isrunning;
    uint16_t _port;
public:
    poll_Server() : _listen_fd(std::make_shared<TcpSocket>()),
                      _isrunning(false) {}
    ~poll_Server() {}

    void init(uint16_t port)
    {
        _port = port;
        _listen_fd->Build_Socket(port);
        for (int i = 0; i < gDefaultSize;++i)
        {
            _fds[i].fd = gDefaultVal;
            _fds[i].events = 0;
            _fds[i].revents = 0;
        }
        _fds[0].fd = _listen_fd->Fd();
        _fds[0].events = POLLIN;
    }

    void Loop()
    {
        _isrunning = true;
        int timeout = 10000;
        while (_isrunning)
        {

            int n = poll(_fds, gDefaultSize, timeout);
            switch (n)
            {
            case -1:
                LOG(logLevel::DEBUG) << "poll error";
                exit(1);
                break;
            case 0:
                LOG(logLevel::DEBUG) << "No fd is ready...";
                break;
            default:
                LOG(logLevel::INFO) << n << " fd" << (n > 1 ? "s are" : " is") << "ready";
                Dispatcher();
                break;
            }
        }
    }

private:
    void Dispatcher()
    {
        for (int i = 0; i < gDefaultSize; ++i)
        {
            if (_fds[i].fd == gDefaultVal)
            {
                continue;
            }

            if(_fds[i].revents & POLLIN)
            {
                if(_fds[i].fd == _listen_fd->Fd())
                {
                    Accepter();
                }
                else
                {
                    Recv(i);
                }
            }
        }
    }
    void Accepter()
    {
        netAddr client;
        int newfd = _listen_fd->Accept(client);
        if (newfd < 0)
        {
            return;
        }
        LOG(logLevel::INFO) << "new client " << "is connected";
        LOG(logLevel::INFO) << "newfd: " << newfd;
        int i = 0;
        for (; i < gDefaultSize; ++i)
        {
            if (_fds[i].fd == gDefaultVal)
            {
                _fds[i].fd = newfd;
                _fds[i].events = POLLIN;
                break;
            }
        }
        if (i == gDefaultSize)
        {
            LOG(logLevel::WARNING) << "server is full... abandon a newfd...";
        }
    }
    void Recv(int i)
    {
        char buffer[1024];
        int n = recv(_fds[i].fd, buffer, sizeof(buffer), 0);
        if (n < 0)
        {
            LOG(logLevel::ERROR) << "read from fd(" << _fds[i].fd << ")error";
            ::close(_fds[i].fd);
            _fds[i].fd = gDefaultVal;
            _fds[i].events = _fds[i].revents = 0;
        }
        else if (n == 0)
        {
            LOG(logLevel::INFO) << "client is quited!";
            ::close(_fds[i].fd);
            _fds[i].fd = gDefaultVal;
            _fds[i].events = _fds[i].revents = 0;

        }
        else
        {
            buffer[n] = 0;
            std::cout << "get: " << buffer;
            std::string message = "Server reply: ";
            message += buffer;
            int n = send(_fds[i].fd, message.c_str(), message.size(), 0);
            if (n < 0)
            {
                LOG(logLevel::INFO) << "send error";
            }
        }
    }
};