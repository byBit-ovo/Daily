#include "TcpServer.hpp"
#include "service.hpp"
#include "daemon.hpp"
uint16_t gport = 6060;

int main(int args, char *arg[])
{
    TOFILE();
    ::Daemon(false, false);
    if (args == 2)
    {
        gport = std::stoi(arg[1]);
    }
    Service calculator;
    std::unique_ptr<TcpServer> server = std::make_unique<TcpServer>(gport,[&calculator](std::string& package)
    {
        return calculator.parse(package);
    });
    server->start();
    return 0;
}