#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <vector>
// __thread int ga = 0;
int ga = 0;
std::string toHex(pthread_t tid){
    char buffer[30];
    ::snprintf(buffer, 30, "%lx", tid);
    return buffer;
}
void *routine1(void *arg)
{
    std::cout <<"thread-1     "<< toHex(pthread_self()) << std::endl;

    for (int i = 0; i < 10; ++i){
        sleep(1);
        ++ga;
    }
    return nullptr;
}

void * routine2(void* arg){
    std::cout <<"thread-2     "<< toHex(pthread_self()) << std::endl;

    for (int i = 0; i < 10;++i){
        std::cout << ga << std::endl;
        ::sleep(1);
    }
    return nullptr;

}
void *threadEntry(void *arg){

    // while(true){
    //     sleep(1);
    // }
    int a = 1;
    return (void*)&a;
}
int main(){
    pthread_t id;
    int ret = pthread_create(&id,nullptr,threadEntry,nullptr);
    void* arg;
    pthread_join(id,&arg);
    std::cout<<arg<<std::endl;
    return 0;
}
