
#include "RingBuffer.hpp"


void *produce(void *blockQueue)
{
    RingModule::RingBuffer<int> *tasks = reinterpret_cast<RingModule::RingBuffer<int>*>(blockQueue);
    int data = 0;
    while(true)
    {
        //获取数据...
        tasks->push(data);
        std::cout<<"生产了一个数据: "<<data<<std::endl;
        ++data;
        // sleep(1);

    }

}
void *consume(void *blockQueue)
{
    RingModule::RingBuffer<int> *tasks = reinterpret_cast<RingModule::RingBuffer<int>*>(blockQueue);
    int data = 0;
    while(true)
    {
        int data;
        tasks->pop(&data);
        std::cout<<"消费一个数据："<<data<<std::endl;
        sleep(1);
        // 处理数据/执行任务
    }

}
int main()
{
    RingModule::RingBuffer<int> buffer(10);
    pthread_t tid1,tid2;
    pthread_create(&tid1,nullptr,produce,reinterpret_cast<void*>(&buffer));
    pthread_create(&tid1,nullptr,produce,reinterpret_cast<void*>(&buffer));
    pthread_create(&tid1,nullptr,produce,reinterpret_cast<void*>(&buffer));
    pthread_create(&tid1,nullptr,consume,reinterpret_cast<void*>(&buffer));
    pthread_create(&tid1,nullptr,consume,reinterpret_cast<void*>(&buffer));
    pthread_create(&tid2,nullptr,consume,reinterpret_cast<void*>(&buffer));

    // std::vector<std::thread> consumers;
    // std::vector<std::thread> produceres;
    // for(int i=0;i<10;++i)
    // {
    //     consumers.emplace_back(consume,&queue);
    // }
    // for(int i=0;i<10;++i)
    // {
    //     produceres.emplace_back(produce,&queue);
    // }
    sleep(20000);
    return 0;
}