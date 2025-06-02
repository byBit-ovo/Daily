#include "thread.hpp"
void *routine1()
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "I am new thread" << std::endl;
    }

    return nullptr;
}

// pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
mutex gmtx;
int tickets = 800;
pthread_cond_t bell = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void ticket()
{
    while (true)
    {
        // gmtx.lock();
        pthread_mutex_lock(&mtx);
        // lockGuard guard(gmtx);
        if (tickets > 0)
        {
            ::usleep(2000);
            printf("%s gets-the %d ticket\n", nameMap[pthread_self()].c_str(), tickets--);
            pthread_mutex_unlock(&mtx);
            // gmtx.unlock();

        }
        else
        {
            // pthread_mutex_unlock(&mtx);
            // continue;
            // gmtx.unlock();
            pthread_cond_wait(&bell, &mtx);// 释放锁，去等待条件变量，醒来重新申请锁
            pthread_mutex_unlock(&mtx);
        }
    }
}

int main()
{
    int n = 5;
    std::vector<myThread> threads;
    for (int i = 0; i < n; ++i)
    {
        threads.emplace_back(ticket);
    }

    for (int i = 0; i < n; ++i)
    {
        threads[i].start();
        nameMap[threads[i].getTid()] = threads[i].getName();
    }

    while(true)
    {
        if (tickets == 0)
        {
            std::cout << "--------ready to put tickets...----------" << std::endl;
            sleep(5);
            tickets += 2000;
            std::cout << "--------has put tickets...----------" << std::endl;
            sleep(1);
            pthread_cond_signal(&bell);
        }
    }


    for (int i = 0; i < threads.size(); ++i)
    {
        threads[i].join();
    }

    return 0;
}