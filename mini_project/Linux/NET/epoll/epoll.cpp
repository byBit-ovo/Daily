#include "epoll_Server.hpp"

int main(int argc,char* args[])
{
    if(argc != 2)
    {
        exit(0);
    }

    uint16_t port = std::stoi(args[1]);
    std::unique_ptr<epoll_Server> server = std::make_unique<epoll_Server>();
    server->init(port);
    server->Loop();
    return 0;
}