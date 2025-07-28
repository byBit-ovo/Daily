#include "udpClient.hpp"
#include "log.hpp"
#include <signal.h>
netAddr addrOfServer(8080);
int sockfd = -1;

void quit(int sig)
{
    std::string message = "QUIT";
    ::sendto(sockfd, message.c_str(), message.size(), 0, &addrOfServer, addrOfServer.size());
    exit(0);//   debug
}

void* recieve(void* args)
{
    while (true)
    {
        char buffer[1024];
        struct sockaddr_in server;
        socklen_t len = sizeof(server);
        int n = recvfrom(sockfd, buffer, 1023, 0, CONV(&server), &len);
        if(n > 0)
        {
            buffer[n] = 0;
            std::cout << buffer << std::endl;
        }
    }
    return nullptr;
}
int main(int argc,char* args[]){
    if(argc!=3)
    {
        LOG(logLevel::ERROR)<<"./udp-clien--ip--port";
        exit(1);
    }

    signal(2, quit);
    std::string ip = args[1];
    uint16_t port = std::stoi(args[2]);
    sockfd = ::socket(AF_INET, SOCK_DGRAM, 0);
    //收消息的线程，防止阻塞
    pthread_t tid;
    int n = pthread_create(&tid, nullptr, recieve, &sockfd);
    // struct sockaddr_in server;
    // server.sin_family = AF_INET;
    // server.sin_addr.s_addr = inet_addr(ip.c_str());
    // server.sin_port = htons(port);
    netAddr copy(ip, port);//客户端自动完成绑定bind
    addrOfServer = copy;
    while (true)
    {
        std::string message;
        getline(std::cin, message);
        if(message.size()==0)
        {
            LOG(logLevel::WARNING) << "不能发送空消息！";
            continue;
        }
        ::sendto(sockfd, message.c_str(), message.size(), 0, &addrOfServer,addrOfServer.size());
    }

    return 0;
}