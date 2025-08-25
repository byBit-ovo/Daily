#include "thread.hpp"
#include "mutex.hpp"
#include "condition.hpp"
#include <queue>
#include <iostream>

namespace LockModule
{
    template<class T>
    class Thread_Safe_Queue
    {
        public:
            Thread_Safe_Queue():_capacity(10),_wait_consumers(0),_wait_producers(0){}
            T pop(){
                LockGuard guard(&_mutex);
                T task;
                while(isEmpty()){
                    ++_wait_consumers;
                    std::cout<<"消费者阻塞... QueueSize: "<<_tasks.size()<<std::endl;
                    _cond_consumer.wait(&_mutex);
                    --_wait_consumers;
                    std::cout<<"消费者被唤醒... QueueSize: "<<_tasks.size()<<std::endl;
                }
                std::cout<<"pop 前的个数："<<_tasks.size()<<std::endl;
                task = _tasks.front();
                _tasks.pop();
                // 先唤醒，让他在锁上等，后面再解锁
                if(_wait_producers > 0)
                    _cond_producer.notify();
                // if(_wait_producers > 0)
                //         _cond_producer.notify();
                return task;
            }
            void push(const T& task)
            {
                LockGuard guard(&_mutex);
                while(isFull()){
                    ++_wait_producers;
                    std::cout<<"生产者阻塞... QueueSize: "<<_tasks.size()<<std::endl;
                    _cond_producer.wait(&_mutex);
                    --_wait_producers;
                    std::cout<<"生产者被唤醒... QueueSize: "<<_tasks.size()<<std::endl;
                }
                _tasks.push(task);
                // 先唤醒，让他在锁上等，后面再解锁
                if(_wait_consumers>0)
                    _cond_consumer.notify();
                // if(_wait_consumers>0)
                //     _cond_consumer.notify();
            }
            bool isFull(){return _tasks.size() == _capacity;}
            bool isEmpty(){return _tasks.empty();}
        private:
            int _capacity;
            Mutex _mutex;        //一把锁只能
            Condition _cond_consumer;
            Condition _cond_producer;
            std::queue<T> _tasks;
            int _wait_consumers;
            int _wait_producers;
    };
}