#include "common.hpp"

class Client
{
private:
    int _fd = -1;

public:
    void sendMessage(std::string message){
        int sig = write(_fd, message.c_str(), message.size());
        if(sig==-1){
            std::cerr << "write error" << std::endl;
            return;
        }
    }
    void openForWrite()
    {
        int fd = open(gpipeName.c_str(), _openForWrite, gmode);
        if (fd == -1)
        {
            std::cerr << "open fail,pipe hasn't be created,you should run server first " << std::endl;
            exit(-1);
        }
        _fd = fd;
        std::cout << "client open the pipe !" << std::endl;
    }
    void Close(){
        ::close(_fd);
    }
};