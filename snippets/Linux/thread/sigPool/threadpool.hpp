#include "log.hpp"
#include <memory>
#include <queue>
#define DEFAULT_SIZE 10


template <typename T>
class threadPool
{
public:
    // threadPool(int count)
    // {
    //     for (int i = 0;i<count;++i)
    //     {
    //         _threads.emplace_back(std::make_shared<myThread>(std::bind(&threadPool::handlerTask,this,std::placeholders::_1)));
    //     }
    // }
    threadPool(const threadPool &other) = delete;
    const threadPool& operator=(const threadPool& other) = delete;//单例模式，去掉拷贝构造和赋值重载
    void start()
    {
        if (_isrunning)
            return;
        _isrunning = true;
        for (int i = 0; i < _threads.size(); ++i)
        {
            LOG(logLevel::INFO) << _threads[i]->getName() << "启动...";
            _threads[i]->start();
        }
        // _isrunning = true; 不能放到这，因为前面的线程可能会提前退出线程池( isEmpty() && _isrunning == false)
    }
    void wait()
    {
        for (int i = 0; i < _threads.size(); ++i)
        {
            _threads[i]->join();
            LOG(logLevel::INFO) << _threads[i]->getName() << "退出...";
        }
    }

    void enQueue(T task) // 类模板实例化后不是万能引用，需要再定义模板
    {
        if (_isrunning)
        {
            lockGuard guard(_lock);
            _taskq.push(task);
            if (_wait_num)
            {
                _cond.signal();
            }
        }
    }

    void stop()
    {
        // 停止入任务
        lockGuard guard(_lock);
        if (_isrunning)
        {
            _isrunning = false;
            if (_wait_num)
            {
                _cond.signal_all();
            }
            LOG(logLevel::INFO) << "对所有线程发送停止处理任务信号...";
        }
    }

    static threadPool<T>* getInstance(int count = DEFAULT_SIZE)
    {
        if(_sig_pool==nullptr)
        {
            lockGuard guard(_lock_sig);   //上锁防止单例被多次实例化
            if (_sig_pool == nullptr)
            {
                _sig_pool = new threadPool<T>(count);
                LOG(logLevel::INFO) << "单例首次实例化...";
            }
        }
        LOG(logLevel::INFO) << "单例已存在，直接返回...";
        return _sig_pool;
    }
    static void destroy_sig()
    {
        delete _sig_pool;
        LOG(logLevel::DEBUG) << "单例对象销毁";
    }

private:
    threadPool(int count):_wait_num(0),_isrunning(false)
    {
        for (int i = 0; i < count; ++i)
        {
            _threads.emplace_back(std::make_shared<myThread>(std::bind(&threadPool::handlerTask, this, std::placeholders::_1)));
        }
    }
    bool isEmpty() { return _taskq.empty(); }
    void handlerTask(std::string name)
    {
        LOG(logLevel::INFO) << name << "进入任务队列...";
        T t;
        while (true)
        {
            // lockGuard guard(_lock);//千万不要锁住t()！！！！！！
            {
                lockGuard guard(_lock);
                while (isEmpty() && _isrunning)
                {
                    ++_wait_num;
                    LOG(logLevel::INFO) << name << "等待条件变量";
                    _cond.wait(_lock);
                    --_wait_num;
                }
                if (isEmpty() && _isrunning == false)
                {
                    break;
                }
                t = _taskq.front();
                _taskq.pop();
            }
            t();
        }
        LOG(logLevel::INFO) << name << "退出任务队列...";
    }
    std::vector<std::shared_ptr<myThread>> _threads;
    std::queue<T> _taskq;
    condition _cond;
    mutex _lock;                                      //保护任务队列
    int _wait_num;
    bool _isrunning;
    static threadPool<T> *_sig_pool;
    static mutex _lock_sig;                           // 只用来保护单例模式

};

template <typename T>
threadPool<T> *threadPool<T>::_sig_pool = nullptr;

template <typename T>
mutex threadPool<T>::_lock_sig; // 只用来保护单例模式
