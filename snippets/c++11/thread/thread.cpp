#include <thread>
#include <stdio.h>
#include <vector>
#include <mutex>
#include <iostream>
#include <chrono>
#include <condition_variable>
std::mutex lock;
void threadEntry(int i){
    std::cout<<i<<std::endl;
}


int main()
{
    std::mutex mutex;
    std::condition_variable condition;
    bool myTurn = true;
    auto Func1 =[&](){
        for(int i=0;i<=100;i+=2){
            std::unique_lock<std::mutex> guard(mutex);
            while(myTurn == false){
                condition.wait(guard);
            }
            std::cout<<i<<" "<<std::endl;
            myTurn = false;
            condition.notify_one();
        }        
    };
    auto Func2 =[&](){
        for(int i=1;i<100;i+=2){
            std::unique_lock<std::mutex> guard(mutex);
            while(myTurn == true){
                condition.wait(guard);
            }
            std::cout<<i<<" "<<std::endl;
            myTurn = true;
            condition.notify_one();
        }        
    };
    std::thread t1(Func1);
    std::thread t2(Func2);
    t1.join();
    t2.join();
    return 0;
}