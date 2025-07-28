#pragma once
#include <unistd.h>
#include <fcntl.h>
#include "inet_addr.hpp"

class Reactor;

class Connector
{
private:
    Reactor *_master;

protected:
    int _fd;
    netAddr _peer;
    uint32_t _care;
    std::string _inBuffer;
    std::string _outBuffer;

public:
    Connector(int fd = -1)
        : _fd(fd),
          _master(nullptr)
    {
    }
    virtual ~Connector()
    {
    }
    void Close()
    {
        if (_fd > 0)
            close(_fd);
    }
    void SetCare(uint32_t care) { _care = care; }
    uint32_t GetCare() { return _care; }

    void SetFd(int fd)
    {
        if (fd > 0)
        {
            _fd = fd;
        }
    }
    void SetMaster(Reactor *master) { _master = master; }
    Reactor *Master() { return _master; }

    // The completeness of read packet is uncertain
    virtual void Read() = 0;
    virtual void Send() = 0;
    virtual void Except() = 0;
    virtual int Fd()
    {
        return _fd;
    }
};