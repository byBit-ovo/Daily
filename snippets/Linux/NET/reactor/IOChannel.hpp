#pragma once
#include "connector.hpp"
#include <string>
#include <functional>
#include <sys/epoll.h>
#include "Common.hpp"
#include "log.hpp"
#include "Reactor.hpp"
#include "service.hpp"

using func_t = std::function<std::string(std::string &)>;

class IO_Channel : public Connector
{
private:
    func_t _req_Handler;

public:
    void Register_Service(func_t handler)
    {
        _req_Handler = handler;
    }
    IO_Channel(int fd)
    {
        SetFd(fd);
        SetCare(EPOLLIN | EPOLLET);
        SetNoBlock(fd);
    }
    virtual ~IO_Channel() override
    {
        // IO_channel need to be closed manually,so it's destruction is not needed...
        // but what if it just keeps connected without sending messages?
        // we need to add a member of timestamp to record it's live time so decide to close it.
    }
    virtual void Read() override
    {
        errno = 0;
        char inbuffer[1024];
        while (true) // ensure we read the entire packet
        {
            int n = read(_fd, inbuffer, 1023);
            if (n < 0)
            {
                if (errno == EAGAIN || errno == EWOULDBLOCK)
                {
                    LOG(logLevel::ERROR) << "Read to the end,break...";
                    break;
                }
                else if (errno == EINTR)
                {
                    LOG(logLevel::ERROR) << "Interupted by signal,come again...";
                    continue;
                }
                else
                {
                    LOG(logLevel::ERROR) << "Read error...";
                    break;
                }
            }
            else if (n == 0)
            {
                LOG(logLevel::ERROR) << "Client quit...";
                // pending
                Except();
            }
            else
            {
                inbuffer[n] = 0;
                std::cout << inbuffer;
                _inBuffer += inbuffer;
            }
        }
        if (_req_Handler)
        {
            _outBuffer += _req_Handler(_inBuffer);
        }
        if (!_outBuffer.empty())
        {
            Send();
            // or enable send care,as shown below...
            // Master()->EnableReadAndWrite(_fd, true, true);
        }
    }
    virtual void Send() override
    {
        while (true)
        {
            int n = send(_fd, _outBuffer.c_str(), _outBuffer.size(), 0);
            if (n < 0)
            {
                if (errno == EAGAIN || errno == EWOULDBLOCK)
                {
                    LOG(logLevel::WARNING) << "Send cache is full,break...";
                    break;
                }
                else if (errno == EINTR)
                {
                    LOG(logLevel::ERROR) << "Interupted by signal,come again...";
                    continue;
                }
                else
                {
                    LOG(logLevel::ERROR) << "Send error...";
                    Except();
                    return;
                }
            }
            else if (n == 0)
            {
                break;
            }
            else
            {
                _outBuffer.erase(0, n);
            }
        }

        //write condition is ready by default, enable it when write_cache is full,so be told when it has room
        if(_outBuffer.size() > 0)
        {
            Master()->EnableReadAndWrite(_fd, true, true); //write condition is not ready,enable writer... 
        }
        else   //when control reaches this line, indicates that _outBuffer has been sent over,writer notification
        {      // is no longer needed !
            Master()->EnableReadAndWrite(_fd, true, false); //disable write notification
        }
        // So,we get that,in epoll mode,read notification is always to be enabled,
        // but write notificaton is enable when needed!
    }
    virtual void Except() override
    {
        //gather exceptions to this one point
        Master()->Delete_Connector(_fd);
    }
};