#include "Protocol.hpp" //两端达成协议
#include "inet_addr.hpp"
#include "service.hpp"
#include "log.hpp"

class TcpClient
{
public:
    TcpClient(std::string ip, uint16_t port) : _server(ip, port)
    {
        _sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
        if(_sockfd < 0)
        {
            DIE(SOCKERROR);
        }
    }
    ~TcpClient()
    {
        ::close(_sockfd);
    }
    void start()
    {
        if (::connect(_sockfd, &_server, _server.size()) != 0)
        {
            LOG(logLevel::ERROR) << "connect error: " << strerror(errno);
            DIE(CONNECTERROR);
        }
        while (true)
        {
            int x, y;
            char op;
            std::cout << "Input x:" << std::endl;
            while(!(std::cin>>x))
            {
                 std::cout << "Input x:" << std::endl;
                 std::cin.clear();
                 std::cin.ignore(10000,'\n');
            }

            std::cout << "Input y:" << std::endl;
            while(!(std::cin>>y))
            {
                 std::cout << "Input y:" << std::endl;
                 std::cin.clear();
                 std::cin.ignore(10000,'\n');
            }
            
            std::cout << "Input operator:" << std::endl;
            while(!(std::cin>>op))
            {
                 std::cout << "Input operator:" << std::endl;
                 std::cin.clear();
                 std::cin.ignore(10000,'\n');
            }
            Request req(x, y, op);
            std::string package;
            req.Serialize(package);
            Encrypton::Encode(package);
            int n = send(_sockfd, package.c_str(), package.size(), 0);
            if (n > 0)
            {
                char retbuffer[1024];
                int n = recv(_sockfd, retbuffer, sizeof(retbuffer) - 1, 0);
                std::string retPackage = retbuffer;
                std::string ans;
                if (!Encrypton::Decode(retPackage, ans))
                {
                    LOG(logLevel::ERROR) << "Decode error";
                    continue;
                }
                Response res;
                if(!res.Deserialize(ans))
                {
                    LOG(logLevel::ERROR) << "DeSerialize error";
                    continue;
                }
                std::cout << "Code: " << res.Code() << std::endl;
                std::cout << "Result: " << res.Result() << std::endl;
            }
            else
            {
                LOG(logLevel::ERROR) << "send error: " << strerror(errno);
            }
        }
    }

private:
    int _sockfd;
    netAddr _server;
};
