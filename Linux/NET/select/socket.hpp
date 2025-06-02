#include "inet_addr.hpp"
#include "log.hpp"
#include <memory>

#define BACKLOG 10

class Socket;
using SockPtr = std::shared_ptr<Socket>;

class Socket
{
public:
    virtual ~Socket(){}
    virtual void Creat_Socket() = 0;
    virtual void Bind_Socket(int) = 0;
    virtual void Set() = 0;
    virtual void Listen() = 0;
    virtual int Accept(netAddr &client) = 0;
    virtual int Recv(std::string &out) = 0;
    virtual int Send(const std::string &in) = 0;
    virtual void Close() = 0;
    virtual int Fd()= 0;
    void Build_Socket(int port)
    {
        Creat_Socket();
        Bind_Socket(port);
        Set();
        Listen();
    }

private:
};


class TcpSocket : public Socket
{
public:
    virtual ~TcpSocket() override {}
    TcpSocket(int sockfd) : _sockfd(sockfd) {}
    TcpSocket() {}
    virtual int Fd()override { return _sockfd; }
    virtual void Set()override
    {
        int opt = 1;
        int n = ::setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR,  &opt, sizeof(opt));
    }
    void Close()
    {
        ::close(_sockfd);
    }
    virtual void Creat_Socket() override
    {
        _sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
        if (_sockfd < 0)
        {
            LOG(logLevel::ERROR) << "socket error, sockfd is " << _sockfd;
            DIE(SOCKERROR);
        }
        LOG(logLevel::INFO) << "socket success, sockfd is " << _sockfd;
    }

    virtual void Bind_Socket(int port) override
    {
        netAddr addr(port);
        int n = ::bind(_sockfd, &addr, addr.size());
        if (n < 0)
        {
            LOG(logLevel::ERROR) << "bind error";
            DIE(BINDERROR);
        }
        LOG(logLevel::INFO) << "bind success";
    }

    virtual void Listen() override
    {
        int n = ::listen(_sockfd, BACKLOG);
        if (n < 0)
        {
            LOG(logLevel::ERROR) << "listen error";
            DIE(LISTENERROR);
        }
        LOG(logLevel::INFO) << "listen success";
    }

    virtual int Accept(netAddr &client)
    {
        socklen_t len = client.size();
        int conn_sock = ::accept(_sockfd, &client, &len);
        if (conn_sock < 0)
        {
            LOG(logLevel::ERROR) << "accept error";
        }
        LOG(logLevel::INFO) << "accept succ";
        return conn_sock;
    }
    virtual int Recv(std::string &out)
    {
        char buffer[1024 * 6];
        int n = ::recv(_sockfd, buffer, sizeof(buffer) - 1, 0);
        if (n == 0)
        {
            LOG(logLevel::WARNING) << "客户端已经退出...";
        }
        else if (n < 0)
        {
            LOG(logLevel::ERROR) << "read error";
        }
        else
        {
            buffer[n] = 0;
            out = buffer;
        }
        return n;
    }
    virtual int Send(const std::string &in)
    {
        int n = ::send(_sockfd, in.c_str(), in.size(), 0);
        if (n<0)
        {
            LOG(logLevel::ERROR) << "send error";
        }
        return n;
    }

private:
    int _sockfd;
};