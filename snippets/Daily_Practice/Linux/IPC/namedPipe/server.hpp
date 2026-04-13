#include "common.hpp"

void creatPipe()
{
    umask(0);
    int sig = ::mkfifo(gpipeName.c_str(), gmode);
    if (sig == -1)
    {
        std::cerr << "open fifo fail " << std::endl;
        exit(-2);
    }
    std::cout << "pipe created!" << std::endl;
}

void releasePipe()
{
    int sig = ::unlink(gpipeName.c_str());
    if (sig == -1)
    {
        std::cerr << "unlink fifo fail " << std::endl;
        return;
    }
    std::cout << "fifo has closed" << std::endl;
}

class server
{
private:
    int _fd = -1;

public:
    void openForRead()
    {
        std::cout << "waiting for client to open pipe..." << std::endl;
        int fd = open(gpipeName.c_str(), _openForRead, gmode);
        if (fd == -1)
        {
            std::cerr << "open fail" << std::endl;
            return;
        }
        _fd = fd;
        std::cout << "server open the pipe!" << std::endl;
    }
    int recMessage(std::string &message)
    {
        char buffer[gsize];
        int n = ::read(_fd, buffer, sizeof(buffer));
        if (n > 0)
        {
            buffer[n] = 0;
            message = buffer;
        }
        return n;
    }
    void Close()
    {
        if (_fd >= 0)
            ::close(_fd);
    }
};