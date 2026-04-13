#include "select_Server.hpp"

int main(int argc,char* args[])
{
    if(argc != 2)
    {
        exit(0);
    }

    uint16_t port = std::stoi(args[1]);
    std::unique_ptr<select_Server> server = std::make_unique<select_Server>();
    server->init(port);
    server->Loop();
    return 0;
}