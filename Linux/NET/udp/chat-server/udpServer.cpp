#include "udpServer.hpp"
int main(int argc, char *args[])
{
    if (argc != 2)
    {
        LOG(logLevel::ERROR) << "udp-server port";
        exit(1);
    }
    uint16_t port = std::stoi(args[1]);
    std::unique_ptr<udp_server> server = std::make_unique<udp_server>(port);
    std::shared_ptr<UserManager> Usr = std::make_shared<UserManager>();
    // version 1

    auto bc = std::bind(&UserManager::BroadCast, Usr.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    server->resigter([&Usr](const User &usr)
                     { return Usr->DelUser(usr); }, bc,
                     [&Usr](const User &usr)
                     { return Usr->AddUser(usr); });

    // auto del = std::bind(&UserManager::DelUser, Usr.get(), std::placeholders::_1);
    // auto add = std::bind(&UserManager::AddUser, Usr.get(), std::placeholders::_1);
    // server->resigter(del, bc, add);
    server->initServer();
    server->start();
    return 0;
}