#include "socket.hpp"
#include <sys/wait.h>
#include <functional>

using tcp_handler_t = std::function<void(SockPtr, netAddr)>;

class TcpServer
{
public:
    TcpServer(int port) : _port(port),
                         _listen_sock(std::make_unique<TcpSocket>()),
                         _isrunning(false)
    {
    }
    void Init()
    {
        _listen_sock->Build_Socket(_port);
    }

    void set_handler(tcp_handler_t handler)
    {
        _handler = handler;
    }
    void Loop()
    {
        if (_isrunning == false)
        {
            _isrunning = true;
            while (_isrunning)
            {
                netAddr client;
                SockPtr newsockfd = _listen_sock->Accept(client);
                if (newsockfd.get() == nullptr)
                    continue;
                LOG(logLevel::INFO) << "get a new client: " << client.name();
                int pid = fork();
                if (pid == 0)
                {
                    _listen_sock->Close();
                    if (fork() > 0)
                        exit(0);
                    LOG(logLevel::DEBUG) << "fork succ";
                    _handler(newsockfd, client);
                    exit(0);
                }
                newsockfd->Close();
                int n = ::waitpid(pid, nullptr, 0);
            }
            _isrunning = false;
        }
    }

private:
    int _port;
    std::unique_ptr<Socket> _listen_sock;
    bool _isrunning;
    tcp_handler_t _handler;
};