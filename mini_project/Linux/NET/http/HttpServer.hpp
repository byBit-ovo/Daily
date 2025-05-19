#include "TcpServer.hpp"
#include "Http_Protocol.hpp"

class HttpServer
{
public:
    HttpServer(int port) : _port(port),
                           _tcp(std::make_unique<TcpServer>(_port))
    {
        _tcp->Init();
        _tcp->set_handler([this](SockPtr sockfd, netAddr client)
                          { Http_Handler(sockfd, client); });
    }

    void Start()
    {
        _tcp->Loop();
    }

    void Http_Handler(SockPtr sockfd, netAddr client)
    {
        LOG(logLevel::INFO) << "Http_Handler Module";
        while (true)
        {
            std::string package;
            sockfd->Recv(package);
            HttpRequest req(package);
            req.DeserializeAndSave();
            req.Debug();
            HttpResponse res(req);
            res.Build();
            std::string message;
            res.Serialize(&message);
            // LOG(logLevel::DEBUG) << message;
            sockfd->Send(message);
        }
    }

private:
    int _port;
    std::unique_ptr<TcpServer> _tcp;
};


