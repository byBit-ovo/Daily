#include <thread>
#include <stdio.h>
#include <vector>
#include <mutex>
#include <iostream>
#include <chrono>
int i = 0;
std::mutex lock;
void threadEntry(int i){
    // std::lock_guard<std::mutex> guard(lock);
    // for(int j = 0;j<90000000;++j){
    //     ++i;
    // }
    std::cout<<i<<std::endl;
}

int main()
{
    std::mutex lock;
    std::unique_lock<std::mutex> guard(lock,std::defer_lock);
    return 0;
}