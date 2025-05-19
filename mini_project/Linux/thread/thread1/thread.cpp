#include <pthread.h>
#include <iostream>
#include <unistd.h>
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

int main(){
    std::cout <<"main thread     "<< toHex(pthread_self()) << std::endl;
    pthread_t tid1, tid2;
    // pthread_create(&tid1, nullptr, routine1, nullptr);
    // pthread_create(&tid2, nullptr, routine2, nullptr);
    // std::cout << "tid1: " << toHex(tid1) << std::endl;
    // std::cout <<"tid2: "<< toHex(tid2) << std::endl;
    // pthread_join(tid1, nullptr);
    // pthread_join(tid2, nullptr);
    sleep(5);
    return 0;
}