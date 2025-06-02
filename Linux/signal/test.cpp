#include <signal.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
void handler(int sig){
    int cnt = 10;
    while(cnt--)
    {
        std::cout<<cnt<<std::endl;
    }
}

void * func(void* args)
{
    while(true)
    {
        sleep(1);
        std::cout<<"子线程"<<std::endl;
    }
    return nullptr;
}

int main()
{
    pthread_t tid;
    signal(2,handler);
    int n = 10;
    while(true)
    {
        sleep(1);
        std::cout<<"主线程  "<<getpid()<<std::endl;
    }
    return 0;
}
