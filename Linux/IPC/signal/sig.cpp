#include <signal.h>
#include <iostream>
void go(){
    sleep(3);
    exit(0);
}
void handler1(int sig){
    std::cout << "I receive " << sig << " signal" << std::endl;
    exit(0);
}

void handler2(int sig){
    while(true){
        std::cout << "handler2" << std::endl;
    }
}
void handler3(int sig){
    while(true){
        std::cout << "handler3" << std::endl;
    }
}
void fpe(int sig){
    std::cout << "receive " << sig << " signal" << std::endl;
}
int main()
{
    signal(SIGALRM, handler1);
    signal(SIGFPE, fpe);
    int a = 1 / 0;
    while (true)
    {
    }

    // std::cout << "hello" << std::endl;

    // signal(SIGCHLD,SIG_IGN);
    // for(int i=0;i<3;++i){
    //     int pid = fork();
    //     if(pid==0){
    //         go();
    //     }
    // }
    // std::cout << "hello" << std::endl;
    // sleep(5);
    return 0;
}