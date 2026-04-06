//读写锁
#include "Linux/BlockQueue/mutex.hpp"
#include <string>
#include <iostream>
std::string data;
bool isReading = false;
bool isWriting = false;
int read_num=0;
int write_num =0;
LockModule::Mutex _mutex;

pthread_mutex_t read_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t write_lock = PTHREAD_MUTEX_INITIALIZER;

void *Read(void* args){
    while(true)
    {
        pthread_mutex_lock(&read_lock);      
        //第一个读者进来才要加 写锁，后续读者才不会被锁阻塞  
        if(read_num == 0){
            pthread_mutex_lock(&write_lock);   
        }
        ++read_num;
        pthread_mutex_unlock(&read_lock);        

        sleep(1);
        std::cout<<pthread_self()<<" 读者在读数据："<<"data="<<data<<std::endl;

        pthread_mutex_lock(&read_lock);      
        --read_num;
        if(read_num==0){
            pthread_mutex_unlock(&write_lock);        
        }
        pthread_mutex_unlock(&read_lock);      
    }
}

void *Writer(void *args){
    while(true)
    {
        pthread_mutex_lock(&write_lock);        
        data +='a';
        std::cout<<pthread_self()<<" 写者在写数据："<<"data="<<data<<std::endl;
        sleep(1);
        pthread_mutex_unlock(&write_lock);        
    }
}


int main(){
    pthread_t threads[10];
    int readers = 2;
    int writers = 8;
    int i =0;
    for(;i<readers;++i)
    {
        pthread_create(&threads[i],nullptr,Read,&readers);
    }
    for(;i<10;i++){
        pthread_create(&threads[i],nullptr,Writer,&writers);
    }

    while(1){
        sleep(10);
    }
    return 0;
}