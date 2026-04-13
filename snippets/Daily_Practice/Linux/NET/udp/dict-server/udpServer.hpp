#include "inet_addr.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>
#include "log.hpp"
#include "dictionary.hpp"
uint16_t dftport = 8080;
using dict_t = std::function<std::string(const std::string &message)>;

template <typename T>
class udp_server
{
public:
    udp_server(T func,uint16_t port = 8080) :_socket(-1), _addr(port),_func(func) {}

    void initServer()
    {
        _socket = socket(AF_INET, SOCK_DGRAM, 0);
        if (_socket < 0)
        {
            LOG(logLevel::FATAL) << "socket creat fail";
            DIE(1);
        }
        LOG(logLevel::FATAL) << "socket is " << _socket;
        int n = bind(_socket, &_addr, _addr.size());
        if (n != 0)
        {
            LOG(logLevel::WARNING) << "Error : bind";
            DIE(2);
        }
        LOG(logLevel::INFO) << "bind success";
    }

    void start()
    {

        while (true)
        {
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            char buffer[1024];
            int n = recvfrom(_socket, buffer, 1023, 0, CONV(&peer), &len);

            if (n > 0)
            {
                buffer[n] = 0;
                netAddr clientInfo(peer);
                // std::cout << "client say : " << buffer << std::endl;
                // std::string echo_str = "your ip: " + clientInfo.getIp() + ",your port: " + std::to_string(clientInfo.getPort());
                std::string ans = _func(buffer);
                ::sendto(_socket, ans.c_str(), ans.size(), 0, &clientInfo, clientInfo.size());
            }
        }
    }

    ~udp_server()
    {
        ::close(_socket);
    }

private:
    int _socket;
    netAddr _addr;
    T _func;
};