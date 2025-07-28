#include "TcpClient.hpp"

int main(int argc,char* args[])
{
    if(argc!=3)
    {
        LOG(logLevel::FATAL) << "You should input like: ./client-tcp \"ip\" \"port\" ";
        return 1;
    }
    uint16_t port = std::stoi(args[2]);
    std::unique_ptr<TcpClient> client = std::make_unique<TcpClient>(args[1], port);
    client->start();
    
    return 0;
}
