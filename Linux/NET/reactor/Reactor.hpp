#pragma once
#include "epoller.hpp"
#include <unordered_map>
#include "connector.hpp"
class Listener;
const int gDefaultSize = 1024;
using Connector_t = std::shared_ptr<Connector>;

class Reactor
{
private:
    // Epoller _epoller;
    int _event_num;
    std::unique_ptr<Epoller> _epoller;
    std::unordered_map<int, Connector_t> _connectors;
    struct epoll_event _revs[1024];
    bool _isRunning;

public:
    Reactor() : _epoller(std::make_unique<Epoller>()),
                _isRunning(false),
                _event_num(gDefaultSize)
    {
    }
    void EnableReadAndWrite(int fd, bool readable, bool writable)
    {
        if (ConnectorHas(fd))
        {
            uint32_t event = (readable ? EPOLLIN : 0) | (writable ? EPOLLOUT : 0) | EPOLLET;
            _epoller->Modify(fd, event);
        }
    }
    bool Insert_Connector(Connector_t link)
    {
        if (!ConnectorHas(link->Fd()))
        {
            _connectors[link->Fd()] = link;
            link->SetMaster(this);
            _epoller->Add(link->Fd(), link->GetCare());
            return true;
        }
        return false;
    }
    bool Delete_Connector(int fd)
    {
        if (ConnectorHas(fd))
        {
            if (!_epoller->Delete(fd))
            {
                LOG(logLevel::ERROR) << "Epoll delete fd: " << fd << " error...";
                return false;
            }
            _connectors[fd]->Close();            //IO_channel need to be closed manually,so it's destruction is not needed
            _connectors.erase(fd);
            return true;
        }
        return false;
    }
    void init()
    {
        _epoller->Init();
        // Connector_t listener = std::make_shared<Listener>(port);
        // if (!Insert_Connector(listener))
        // {
        //     LOG(logLevel::FATAL) << "Listening socket inserted fail";
        //     exit(1);
        // }
        // listener->SetMaster(this); // need to insert back to connectors
    }

    void Loop()
    {
        _isRunning = true;
        int timeout = 10000;
        while (_isRunning)
        {
            int n = _epoller->Wait(_revs, _event_num, timeout);
            if (n > 0)
            {
                Dispatcher(n);
            }
            else if (n == 0)
            {
                LOG(logLevel::INFO) << "Time out...";
            }
        }
        _isRunning = false;
    }

    ~Reactor()
    {
    }

private:
    void Dispatcher(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            int fd = _revs[i].data.fd;
            uint32_t care = _revs[i].events;
            if((care & EPOLLERR) || (care & EPOLLHUP))
            {
                care |= (EPOLLIN | EPOLLOUT);         //convert the exceptions to one point... 
            }
            if ((care & EPOLLIN) && ConnectorHas(fd))
            {
                _connectors[fd]->Read();
            }
            if ((care & EPOLLOUT) && ConnectorHas(fd))
            {
                _connectors[fd]->Send();
            }
        }
    }
    bool ConnectorHas(int fd)
    {
        return _connectors.count(fd);
    }
};
