#include "thread.hpp"
#include "mutex.hpp"
#include "condition.hpp"
#include "BlockQueue.hpp"
#include <iostream>
int tickets = 0;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
void routine1(int a)
{
    printf("tid: %0lx,recieve: %d\n", pthread_self(),a);
    sleep(3);

}
void buy_tickets(LockModule::Mutex* mutex){
    while(true)
    {
        mutex->lock();
        if(tickets > 0){
            usleep(200);
            --tickets;
            mutex->unlock();

        }
        else
        {

            printf("没票了,等主线程放票...\n");
            //释放锁，等条件变量
            pthread_cond_wait(&condition,mutex->getRaw());
            //被条件变量唤醒，获取锁         
            //再释放锁
            mutex->unlock();
        }
        // mutex->unlock();
        printf("还有%d张票\n",tickets);
    }
}
void task1(){
    std::cout<<"消费者执行 Task1..."<<std::endl;
}
void task2(){
    std::cout<<"消费者执行 Task2..."<<std::endl;
}
void task3(){
    std::cout<<"消费者执行 Task3..."<<std::endl;
}

void produce(LockModule::Thread_Safe_Queue<std::function<void()>> *blockQueue)
{
    int i=0;
    while(true)
    {
        blockQueue->push(task1);
        std::cout<<"生产Task1"<<std::endl;
        sleep(3);
        blockQueue->push(task2);
        std::cout<<"生产Task2"<<std::endl;
        sleep(3);
        blockQueue->push(task3);
        std::cout<<"生产Task3"<<std::endl;
        sleep(3);
    }
}
void consume(LockModule::Thread_Safe_Queue<std::function<void()>> *blockQueue)
{

    while(true)
    {
        // sleep(3);
        auto t = blockQueue->pop();
        t();
    }
}
using myThread = LockModule::Thread<LockModule::Thread_Safe_Queue<std::function<void()>> *>;
int main()
{

    LockModule::Thread_Safe_Queue<std::function<void()>> blockQueue;
    LockModule::Thread<LockModule::Thread_Safe_Queue<std::function<void()>> *> producer1(produce,&blockQueue);
    LockModule::Thread<LockModule::Thread_Safe_Queue<std::function<void()>> *> producer2(produce,&blockQueue);
    LockModule::Thread<LockModule::Thread_Safe_Queue<std::function<void()>> *> consumer1(consume,&blockQueue);
    LockModule::Thread<LockModule::Thread_Safe_Queue<std::function<void()>> *> consumer2(consume,&blockQueue);
    std::vector<myThread> threads;
    for(int i=0;i<1;i++){
        threads.emplace_back(consume,&blockQueue);
        threads[i].start();
    }

    for(int i=1;i<2;i++){
        threads.emplace_back(produce,&blockQueue);
        threads[i].start();
    }


    sleep(20000);

    // LockModule::Mutex mutex;

    // std::vector<LockModule::Thread<LockModule::Mutex*>> _threads;
    // for(int i=0;i<5;++i)
    // {
    //     _threads.emplace_back(buy_tickets,&mutex);
    // }
    // for(int i=0;i<5;++i)
    // {
    //     _threads[i].start();
    // }
    // for(int i=0;i<10;++i){
    //     sleep(5);
    //     printf("开始放票...");
    //     tickets += 2000;
    //     pthread_cond_broadcast(&condition);
    // }
    // for(int i=0;i<5;++i)
    // {
    //     _threads[i].join();
    // }
    return 0;
}