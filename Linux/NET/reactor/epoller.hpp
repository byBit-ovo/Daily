
#include "log.hpp"
#include <sys/epoll.h>

class Epoller
{
private:
    int _epfd;
    // struct epoll_event _revs[1024];

public:
    Epoller() : _epfd(-1)
    {
    }
    ~Epoller()
    {
        if (_epfd > 0)
            close(_epfd);
    }
    int Wait(struct epoll_event *revs, int num, int timeout)
    {
        int n = epoll_wait(_epfd, revs, num, timeout);
        if (n < 0)
        {
            LOG(logLevel::ERROR) << "Epoll_Wait error";
        }
        return n;
    }
    void Init()
    {
        _epfd = epoll_create(6);
        if (_epfd < 0)
        {
            LOG(logLevel::FATAL) << "Epoll_Create error";
            exit(0);
        }
    }
    // bool Modify(int fd, uint32_t care)
    // {
    //     struct epoll_event ev;
    //     ev.data.fd = fd;
    //     ev.events = care;
    //     int n = epoll_ctl(_epfd, EPOLL_CTL_MOD, fd, &ev);
    //     if (n < 0)
    //     {
    //         LOG(logLevel::ERROR) << "Epoll_ctl error";
    //         return false;
    //     }
    //     return true;
    // }
    // bool Delete(int fd)
    // {
    //     // struct epoll_event ev;
    //     // ev.data.fd = fd;
    //     int n = epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, nullptr);
    //     if (n < 0)
    //     {
    //         LOG(logLevel::ERROR) << "Epoll_ctl error";
    //         return false;
    //     }
    //     return true;
    // }
    // bool Add(int fd, uint32_t care)
    // {
    //     struct epoll_event ev;
    //     ev.data.fd = fd;
    //     ev.events = care;
    //     int n = epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &ev);
    //     if (n < 0)
    //     {
    //         LOG(logLevel::ERROR) << "Epoll_ctl error";
    //         return false;
    //     }
    //     return true;
    // }
    bool Add(int fd, uint32_t care)
    {
        return Ctl_Center(fd, EPOLL_CTL_ADD, care);
    }
    bool Delete(int fd)
    {
        return Ctl_Center(fd, EPOLL_CTL_DEL, 0);
    }
    bool Modify(int fd, uint32_t care)
    {
        return Ctl_Center(fd, EPOLL_CTL_MOD, care);
    }

private:
    bool Ctl_Center(int fd, int way, uint32_t care)
    {
        struct epoll_event ev;
        ev.data.fd = fd;
        ev.events = care;
        int n = epoll_ctl(_epfd, way, fd, &ev);
        if (n < 0)
        {
            LOG(logLevel::ERROR) << "Epoll_ctl error";
            return false;
        }
        return true;
    }
};
