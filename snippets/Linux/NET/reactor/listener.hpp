#pragma once
#include "socket.hpp"
#include "IOChannel.hpp"
#include "Reactor.hpp"
// class Reactor;
using Connector_t = std::shared_ptr<Connector>;

class Listener : public Connector
{
private:
    Sock_t _listen_sock;
    int _port;

public:
    Listener(int port) : _listen_sock(std::make_shared<TcpSocket>()),
                         _port(port)
    {
        _listen_sock->Build_Socket(_port);
        SetFd(_listen_sock->Fd());
        SetNoBlock(_listen_sock->Fd());
        SetCare(EPOLLIN | EPOLLET);
    }
    virtual ~Listener() override
    {
        if (_fd > 0)
            close(_fd);
    }
    virtual int Fd() override
    {
        return _listen_sock->Fd();
    }

    virtual void Read() override
    {
        // under ET mode,you will only be noticed one time when IO is ready,
        // so ensure all of clients are accepted here...
        int myErrno = 0;
        while (true)
        {
            int newfd = _listen_sock->Accept(Connector::_peer, &myErrno);
            if (newfd > 0)
            {
                LOG(logLevel::INFO) << "Newfd: " << newfd << "  Client: " << Connector::_peer.Name();
                std::shared_ptr<IO_Channel> link = std::make_shared<IO_Channel>(newfd);
                link->Register_Service(Service::parse);              // bussiness 
                if (!(Connector::Master()->Insert_Connector(link)))
                {
                    LOG(logLevel::ERROR) << "Fail to insert IOChannnel to reactor...";
                }
            }
            else
            {
                // Not real error,but read over...
                if (myErrno == EAGAIN || myErrno == EWOULDBLOCK)
                {
                    LOG(logLevel::ERROR) << "Accept completed,break...";

                    break;
                }
                else if (myErrno == EINTR)
                {
                    LOG(logLevel::INFO) << "Interupted by siganl,restart...";
                    continue;
                }
                else
                {
                    LOG(logLevel::ERROR) << "Accept error...";
                    break;
                }
            }
        }
    }
    virtual void Send() override
    {
    }
    virtual void Except() override
    {

    }
};