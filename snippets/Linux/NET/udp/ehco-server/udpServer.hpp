#include "inet_addr.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>
#include "log.hpp"

uint16_t dftport = 8080;

class udp_server
{
public:
    udp_server(uint16_t port = 8080) : _addr(port) {}

    void initServer()
    {
        _socket = socket(AF_INET, SOCK_DGRAM, 0);
        if (_socket < 0)
        {
            LOG(logLevel::FATAL) << "socket creat fail";
            DIE(1);
        }
        int opt = 1;
        _socket2 = socket(AF_INET, SOCK_DGRAM, 0);
        setsockopt(_socket,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
        setsockopt(_socket2,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
        LOG(logLevel::FATAL) << "socket is " << _socket;
        int n = bind(_socket, &_addr, _addr.size());
        int n2 = bind(_socket2, &_addr, _addr.size());
        if (n != 0 || n2 != 0)
        {
            LOG(logLevel::WARNING) << "Error : bind";
            DIE(2);
        }
        LOG(logLevel::INFO) << "bind success";
    }

    void start()
    {
        if(fork() >0){
            while (true)
            {
                struct sockaddr_in peer;
                socklen_t len = sizeof(peer);
                char buffer[1024];
                int n = recvfrom(_socket2, buffer, 1023, 0, CONV(&peer), &len);
                std::cout<<"This is child ,server socket: "<<_socket2<<std::endl;
                if (n > 0)
                {
                    netAddr clientInfo(peer);
                    buffer[n] = 0;
                    std::cout << "client say : " << buffer << std::endl;
                    std::string echo_str = "your ip: " + clientInfo.getIp() + ",your port: " + std::to_string(clientInfo.getPort());
                    ::sendto(_socket2, echo_str.c_str(), echo_str.size(), 0, &clientInfo, clientInfo.size());
                }
            }
        }
        while (true)
        {
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            char buffer[1024];
            int n = recvfrom(_socket, buffer, 1023, 0, CONV(&peer), &len);
            std::cout<<"This is parent,server socket: "<<_socket<<std::endl;

            if (n > 0)
            {
                netAddr clientInfo(peer);
                buffer[n] = 0;
                std::cout << "client say : " << buffer << std::endl;
                std::string echo_str = "your ip: " + clientInfo.getIp() + ",your port: " + std::to_string(clientInfo.getPort());
                ::sendto(_socket, echo_str.c_str(), echo_str.size(), 0, &clientInfo, clientInfo.size());
            }
        }
    }

    ~udp_server()
    {
        ::close(_socket);
    }

private:
    int _socket;
    int _socket2;
    netAddr _addr;
};