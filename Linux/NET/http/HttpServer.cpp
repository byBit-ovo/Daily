#include "HttpServer.hpp"

int main(int argc,char* args[])
{
    TOCONSOLE();
    if (argc != 2)
    {
        LOG(logLevel::FATAL) << "You should input like: ./http_server port";
        exit(0);
    }
    auto http_server = std::make_unique<HttpServer>(std::stoi(args[1]));
    http_server->Start();

    return 0;
}