#include "threadpool.hpp"
#include <functional>
#include "task.hpp"
#define TASK_COUNT  20
// mutex _lock;
// void testThread(std::string name)
// {
//     lockGuard lock(_lock);
//     int cnt = 10;
//     while (cnt--)
//     {
//         std::cout << "I am " << name << std::endl;
//         sleep(1);
//     }
// }
using task_t = std::function<void()>;
std::vector<task_t> tasks = {net_ask, log_push, data_parse, game};

int main()
{

    srand(time(nullptr));
    threadPool<task_t>::getInstance()->start();

    for (int i = 0; i < TASK_COUNT; ++i)
    {
        threadPool<task_t>::getInstance()->enQueue(tasks[rand() % tasks.size()]);
        sleep(1);
    }

    threadPool<task_t>::getInstance()->stop();
    threadPool<task_t>::getInstance()->wait();

    threadPool<task_t>::destroy_sig();
    // std::unique_ptr<threadPool<task_t>> threadpool = std::make_unique<threadPool<task_t>>(6);
    // threadpool->start();
    // srand(time(nullptr));
    // for (int i = 0; i < 20; ++i)
    // {
    //     sleep(1);
    //     threadpool->enQueue(tasks[rand()%tasks.size()]);
    // }
    // threadpool->stop();
    // threadpool->wait();

    // std::vector<myThread> threads;
    // for (int i = 0; i < 10; ++i)
    //     threads.emplace_back(testThread);
    // LOG(logLevel::INFO) << "threads ready...";

    // for (int i = 0; i < 10; ++i)
    //     threads[i].start();
    // LOG(logLevel::INFO) << "threads start...";

    // for (int i = 0; i < 10; ++i)
    //     threads[i].join();
    // LOG(logLevel::INFO) << "threads joined...";

    // myThread thread1(testThread);
    // thread1.start();
    return 0;
}