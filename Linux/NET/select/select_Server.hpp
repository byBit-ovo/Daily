#include "socket.hpp"
#include <sys/select.h>
const int gDefaultSize = 1024;
const int gDefaultVal = -1;

class select_Server
{
private:
    int _fd_array[gDefaultSize];
    SockPtr _listen_fd;
    bool _isrunning;
    uint16_t _port;

public:
    select_Server() : _listen_fd(std::make_shared<TcpSocket>()),
                      _isrunning(false) {}
    ~select_Server() {}

    void init(uint16_t port)
    {
        _port = port;
        _listen_fd->Build_Socket(port);
        for (int i = 0; i < gDefaultSize; ++i)
            _fd_array[i] = gDefaultVal;
        _fd_array[0] = _listen_fd->Fd();
    }

    void Loop()
    {
        _isrunning = true;
        fd_set rfds;
        while (_isrunning)
        {
            FD_ZERO(&rfds);
            int fmax = 0;
            for (int i = 0; i < gDefaultSize; ++i)
            {
                if (_fd_array[i] == gDefaultVal)
                    continue;
                FD_SET(_fd_array[i], &rfds);
                if (_fd_array[i] > fmax)
                {
                    fmax = _fd_array[i];
                }
            }
            struct timeval timeout = {10, 0};
            int n = select(fmax + 1, &rfds, nullptr, nullptr, &timeout);
            switch (n)
            {
            case -1:
                LOG(logLevel::DEBUG) << "select error";
                exit(1);
                break;
            case 0:
                LOG(logLevel::DEBUG) << "No fd is ready...";
                break;
            default:
                LOG(logLevel::DEBUG) << timeout.tv_sec << "." << timeout.tv_usec << "left...";

                Dispatcher(rfds);
                break;
            }
        }
    }

private:
    void Dispatcher(fd_set &rfds)
    {
        for (int i = 0; i < gDefaultSize; ++i)
        {
            if (_fd_array[i] == gDefaultVal)
            {
                continue;
            }

            if (FD_ISSET(_fd_array[i], &rfds))
            {
                if (_fd_array[i] == _listen_fd->Fd())
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
            if (_fd_array[i] == gDefaultVal)
            {
                _fd_array[i] = newfd;
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
        int n = recv(_fd_array[i], buffer, sizeof(buffer), 0);
        if (n < 0)
        {
            LOG(logLevel::ERROR) << "read from fd(" << _fd_array[i] << ")error";
            ::close(_fd_array[i]);
            _fd_array[i] = gDefaultVal;
        }
        else if (n == 0)
        {
            LOG(logLevel::INFO) << "client is quited!";
            ::close(_fd_array[i]);
            _fd_array[i] = gDefaultVal;
        }
        else
        {
            buffer[n] = 0;
            std::cout << "get:: " << buffer;
            std::string message = "Server reply: ";
            message += buffer;
            int n = send(_fd_array[i], message.c_str(), message.size(), 0);
            if (n < 0)
            {
                LOG(logLevel::INFO) << "send error";
            }
        }
    }
};