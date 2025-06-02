#include "udpClient.hpp"
#include "log.hpp"

int main(int argc,char* args[]){
    if(argc!=3)
    {
        LOG(logLevel::ERROR)<<"./udp-clien--ip--port";
        exit(1);
    }
    std::string ip = args[1];
    uint16_t port = std::stoi(args[2]);
    int socket = ::socket(AF_INET, SOCK_DGRAM, 0);
    // struct sockaddr_in server;
    // server.sin_family = AF_INET;
    // server.sin_addr.s_addr = inet_addr(ip.c_str());
    // server.sin_port = htons(port);
    netAddr addrOfServer(ip, port);//客户端自动完成绑定bind
    while (true)
    {
        std::string message;
        getline(std::cin, message);
        if(message.size()==0)
        {
            LOG(logLevel::WARNING) << "不能发送空消息！";
            continue;
        }
        ::sendto(socket, message.c_str(), message.size(), 0, &addrOfServer,addrOfServer.size());

        char buffer[1024];
        struct sockaddr_in server;
        socklen_t len = sizeof(server);
        int n = recvfrom(socket, buffer, 1023, 0, CONV(&server), &len);
        if(n > 0)
        {
            buffer[n] = 0;
            std::cout << "server reply : " << buffer << std::endl;
        }
    }

    return 0;
}