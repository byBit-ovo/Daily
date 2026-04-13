
#include "listener.hpp"

int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        LOG(logLevel::ERROR) << "Format error";
        exit(1);
    }
    int port = std::stoi(argv[1]);

    std::unique_ptr<Reactor> eServer = std::make_unique<Reactor>();
    eServer->init();
    Connector_t listener = std::make_shared<Listener>(port);

    eServer->Insert_Connector(listener);
    eServer->Loop();
    
    return 0;
}