#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>

int main(){
    int listen_fd = socket(AF_INET,SOCK_STREAM,0);
    if(listen_fd < 0){
        std::cout<<"listen error"<<std::endl;
        return 1;
    }
    struct sockaddr_in peer;
    struct sockaddr_in _addr;
    _addr.sin_family = AF_INET;
    _addr.sin_addr.s_addr = INADDR_ANY;
    _addr.sin_port = htons(9000);
    int ret = bind(listen_fd,reinterpret_cast<const sockaddr*>(&_addr),sizeof(struct sockaddr_in));
    int ret2 = listen(listen_fd,8);
    int optval = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    if(ret !=0){
        std::cout<<"bind error"<<std::endl;
        std::cout<<strerror(errno)<<std::endl;
        return 2;
    }
    socklen_t len = sizeof(sockaddr_in);
    int sockfd = accept(listen_fd,reinterpret_cast<sockaddr*>(&peer),&len);
    fork();

    char buffer[1024];
    while(true){

        int n = recv(sockfd,buffer,1023,0);
        if(n<=0){
            std::cout<<"server quit"<<std::endl;
            break;
        }
        buffer[n]=0;
        send(sockfd,buffer,n,0);
        std::cout<<buffer<<std::endl;
    }
    return 0;
}