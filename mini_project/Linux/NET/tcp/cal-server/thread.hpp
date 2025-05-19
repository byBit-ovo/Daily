#pragma once
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <functional>
#include <vector>
#include <unordered_map>
#include <map>
#include <memory>
#include <queue>
enum threadStatus
{
    RUNNING,
    CANCELED,
    NEW,
    JOINED,
    DETACHED,
};

class myThread
{
public:
    using func_t = std::function<void(std::string)>;
    // static 修饰配合void*(ptr)(void*)
    // 参数传this
    static void *routine(void *arg)
    {
        myThread *This = (myThread *)arg;
        This->_func(This->_name);
        return nullptr;
    }
    myThread(func_t func) : _func(func), _sta(NEW)
    {
        _name = "thread-" + std::to_string(countName++);
        _pid = ::getpid();
    }
    bool start()
    {
        if (_sta == NEW)
        {
            int n = ::pthread_create(&_tid, nullptr, routine, this);
            if (n == 0)
            {
                _sta = RUNNING;
                // std::cout << _name << " start!" << std::endl;
                return true;
            }
        }
        return false;
    }
    void *join()
    {
        void *rt = nullptr;
        if (_sta == RUNNING)
        {
            int n = pthread_join(_tid, &rt);
            if (n == 0)
            {
                // std::cout << _name << " has joined !" << std::endl;
                _sta = JOINED;
            }
        }
        return rt;
    }
    bool cancel()
    {
        if (_sta == RUNNING)
        {
            int n = pthread_cancel(_tid);
            if (n == 0)
            {
                _sta = CANCELED;
                return true;
            }
        }
        return false;
    }
    bool detach()
    {
        if (_sta == RUNNING)
        {
            int n = pthread_detach(_tid);
            if (n == 0)
            {
                _sta = DETACHED;
                return true;
            }
        }
        return false;
    }
    std::string getName()
    {
        return _name;
    }
    static int getCount()
    {
        return countName;
    }
    pthread_t getTid()
    {
        return _tid;
    }
    // myThread(const myThread &other) = delete;
private:
    threadStatus _sta;
    std::string _name;
    static int countName;
    pthread_t _tid;
    pid_t _pid;
    func_t _func;
};

int myThread::countName = 1;

class mutex
{
public:
    mutex()
    {
        int n = pthread_mutex_init(&_lock, nullptr);
        if (n != 0)
        {
            std::cerr << "mutex_init_error" << std::endl;
        }
    }
    ~mutex()
    {
        int n = pthread_mutex_destroy(&_lock);
        if (n != 0)
        {
            std::cerr << "mutex_destroy_error" << std::endl;
        }
    }
    pthread_mutex_t *getLockPtr() { return &_lock; }
    void lock()
    {
        int n = pthread_mutex_lock(&_lock);
        if (n != 0)
        {
            std::cerr << "mutex_lock_error" << std::endl;
        }
    }

    void unlock()
    {
        int n = pthread_mutex_unlock(&_lock);
        if (n != 0)
        {
            std::cerr << "mutex_unlock_error" << std::endl;
        }
    }

    mutex(const mutex &other) = delete;
    const mutex &operator=(const mutex &other) = delete;

private:
    pthread_mutex_t _lock;
};

class lockGuard
{
public:
    lockGuard(mutex &mtx) : _mtx(mtx)
    {
        _mtx.lock();
    }
    ~lockGuard()
    {
        _mtx.unlock();
    }

private:
    mutex &_mtx;
};

class condition
{
public:
    condition()
    {
        pthread_cond_init(&_cond, nullptr);
    }

    ~condition()
    {
        pthread_cond_destroy(&_cond);
    }
    void wait(mutex &lock)
    {
        pthread_cond_wait(&_cond, lock.getLockPtr());
    }

    void signal()
    {
        pthread_cond_signal(&_cond);
    }

    void signal_all()
    {
        pthread_cond_broadcast(&_cond);
    }

private:
    pthread_cond_t _cond;
};