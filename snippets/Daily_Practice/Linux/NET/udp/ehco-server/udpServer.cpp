#include "udpServer.hpp"
int main(int argc, char *args[])
{
    if(argc != 2)
    {
        LOG(logLevel::ERROR) << "udp-server port";
        exit(1);
    }
    TOFILE();
    uint16_t port = std::stoi(args[1]);

    std::unique_ptr<udp_server> server = std::make_unique<udp_server>(port);
    server->initServer();
    server->start();
    return 0;
}