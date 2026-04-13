#include "msg.hpp"
void* rece(void* arg){
    Client client;
    std::string message;
    while(true){
        client.rec(SD1,message);
        if(message=="exit"){
            break;
        }
        std::cout << message << std::endl;
    }
    return nullptr;
}
int main(){
    pthread_t  tid = -1;
    int n = pthread_create(&tid, nullptr, rece, nullptr);
    if(n!=0){
        std::cout << "thread fail!" << std::endl;
        exit(0);
    }
    Client client;
    std::string message;

    while(true){
        std::getline(std::cin, message);
        client.send(RC1,message);
        if(message=="exit"){
            break;
        }
    }
    pthread_join(tid, nullptr);

    //chat by fork
    // Client client;
    // std::string message;
    // int id = fork();
    // if(id==0){
    //     //子进程收消息
    //     while(true){
    //         // std::getline(std::cin,message);
    //         // server.send(message);
    //         client.rec(message);
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
    //         client.send(message);
    //         if(message == "exit"){
    //             break;
    //         }
    //     }
    // }
    // while(true){
    //     std::getline(std::cin,message);
    //     client.send(message);
    //     if(message == "exit"){
    //         break;
    //     }
    //     // client.rec(message);
    //     // std::cout<<message<<std::endl;
    // }
    return 0;
}