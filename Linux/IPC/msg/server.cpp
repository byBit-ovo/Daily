#include "msg.hpp"
void* rece(void* arg){
    std::string message;
    Client client;
    while(true){
        client.rec(RC1,message);
        if(message == "exit"){
            break;
        }
        std::cout<<message<<std::endl;
    }
    return nullptr;
}

int main(){
    pthread_t tid=-1;
    int n = pthread_create(&tid,nullptr,rece,nullptr);
    if(n!=0){
        std::cerr << "Error: pthread_create failed" << std::endl;
        exit(1);
    }
    std::string message;
    Server server;
    while(true){
        std::getline(std::cin,message);
        server.send(SD1,message);
        if(message == "exit"){
            break;
        }
    }

    pthread_join(tid, nullptr);

    //chat by fork
    // Server server;
    // std::string message;
    // int id = fork();
    // if(id==0){
    //     //子进程收消息
    //     while(true){
    //         // std::getline(std::cin,message);
    //         // server.send(message);
    //         server.rec(message);
    //         if(message == "exit"){
    //             exit(0);
    //         }
    //         std::cout<<message<<std::endl;
    //     }
    // }
    // else{
    //     //父进程发消息
    //     signal(SIGCHLD,signalHandler);
    //     while(true){
    //         std::getline(std::cin,message);
    //         server.send(message);
    //         if(message == "exit"){
    //             break;
    //         }
    //     }
    // }
    return 0;
}