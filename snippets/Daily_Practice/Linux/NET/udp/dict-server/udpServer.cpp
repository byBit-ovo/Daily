#include "udpServer.hpp"
int main(int argc, char *args[])
{
    if (argc != 2)
    {
        LOG(logLevel::ERROR) << "udp-server port";
        exit(1);
    }
    TOCONSOLE();
    uint16_t port = std::stoi(args[1]);
    std::shared_ptr dict_ptr = std::make_shared<dictionary>();
    //version 1
    // auto fs = std::bind(&dictionary::find,dict_ptr.get(), std::placeholders::_1);
    //version 2
    std::unique_ptr<udp_server<dict_t>> server = 
    std::make_unique<udp_server<dict_t>>([&dict_ptr](const std::string &message)
                                        { return dict_ptr->find(message); }, port);
    server->initServer();
    server->start();
    return 0;
}