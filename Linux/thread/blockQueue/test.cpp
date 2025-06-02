#include "blockQueue.hpp"

// int data = 1;
void *producer(void *arg)
{
    blockQueue<int> *con = (blockQueue<int> *)arg;
    int data = 1;

    while(true)
    {
        sleep(1);
        con->push(data);
        // std::cout << "producer produced " << data++ << std::endl;
        ++data;
    }
    std::cout << "producer over" << std::endl;
    return nullptr;
}

void* consumer(void* arg)
{
    blockQueue<int> *con = (blockQueue<int> *)arg;
    int data = -1;
    std::cout << "consumer ready to consume..." << std::endl;
    while (true)
    {
        con->pop(&data);
        std::cout << "consumer consumed " << data << std::endl;
    }
    std::cout << "consumer over" << std::endl;
    return nullptr;
}
int main()
{
    blockQueue<int> *con = new blockQueue<int>();
    int npro = 1, ncon = 1 ;
    std::vector<myThread<blockQueue<int> *>> producers, consumers;

    for (int i = 0; i < npro;++i) producers.emplace_back(producer,con);
    for (int i = 0; i < ncon;++i) consumers.emplace_back(consumer,con);
    
    for (int i = 0; i < npro;++i) producers[i].start();
    for (int i = 0; i < ncon;++i) consumers[i].start();
    
    for (int i = 0; i < npro;++i) producers[i].join();
    for (int i = 0; i < ncon;++i) consumers[i].join();
    
    // std::vector<pthread_t> threads_pro, threads_con;
    // for (int i = 0; i < 1; ++i)
    // {
    //     pthread_t tid;
    //     pthread_create(&tid, nullptr, producer, (void*)con);
    //     threads_pro.emplace_back(tid);
    // }

    // for (int i = 0; i < 3;++i)
    // {
    //     pthread_t tid;
    //     pthread_create(&tid, nullptr, consumer, (void*)con);
    //     threads_con.emplace_back(tid);
    // }

    // for (auto e:threads_con)
    // {
    //     pthread_join(e,nullptr);
    // }
    // for (auto e:threads_pro)
    // {
    //     pthread_join(e,nullptr);
    // }
    delete con;
    return 0;
}