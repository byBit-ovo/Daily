#include "log.hpp"
#include <memory>
#include <queue>


template <typename T>
class threadPool
{
public:
    
    threadPool(int count)
    {
        for (int i = 0;i<count;++i)
        {
            _threads.emplace_back(std::make_shared<myThread>(std::bind(&threadPool::handlerTask,this,std::placeholders::_1)));
        }
    }

    void start()
    {
        if(_isrunning)
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
        for (int i = 0; i < _threads.size();++i)
        {
            _threads[i]->join();
            LOG(logLevel::INFO) << _threads[i]->getName() << "退出...";
        }
    }

    void enQueue(T task) //类模板实例化后不是万能引用，需要再定义模板
    {
        if(_isrunning)
        {
            lockGuard guard(_lock);
            _taskq.push(task);
            if(_wait_num)
            {
                _cond.signal();
            }
        }
    }

    void stop()
    {
        //停止入任务
        lockGuard guard(_lock);
        if(_isrunning)
        {
            _isrunning = false;
            if(_wait_num)
            {
                _cond.signal_all();
            }
            LOG(logLevel::INFO) << "对所有线程发送停止处理任务信号...";
        }
    }
private:
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
                while(isEmpty() && _isrunning)
                {
                    ++_wait_num;
                    LOG(logLevel::INFO) << name << "等待条件变量";
                    _cond.wait(_lock);
                    --_wait_num;
                }
                if(isEmpty() && _isrunning==false)
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
    bool _isrunning = false;
    mutex _lock;
    condition _cond;
    int _wait_num = 0;
};