#pragma once
#include "Sem.hpp"
#include "../BlockQueue/condition.hpp"
#include "../BlockQueue/mutex.hpp"
#include "../BlockQueue/thread.hpp"
#include <iostream>
#include <thread>
namespace RingModule
{
    template<class T>
    class RingBuffer{
        public:
            RingBuffer(int cap):
            _capacity(cap),_head(0),_tail(0),
            _space_sem(_capacity), _data_sem(0),_tasks(_capacity){}

            void push(const T& data){
                _space_sem.P();
                {
                    LockModule::LockGuard guard(&_mutex_p);
                    _tasks[_tail] = data;
                    ++_tail;
                    _tail %= _capacity;
                }
                _data_sem.V();
                //就算push满了，_head==_tail,此时生产者已被阻塞，只有消费者拿走_head,并V(空间)，生产者才会被唤醒
                //因此他们不会访问同一个位置，就比如上面，生产者会被P(空间)阻塞
            }

            void pop(T* out)
            {
                _data_sem.P();
                {
                    LockModule::LockGuard guard(&_mutex_c);
                    *out = _tasks[_head];
                    _head++;
                    _head %= _capacity;
                }
                _space_sem.V();
            }
        private:
            int _capacity;
            int _head;
            int _tail;
            Sem _space_sem;
            Sem _data_sem;
            LockModule::Mutex _mutex_p;
            LockModule::Mutex _mutex_c;
            std::vector<T> _tasks;
    };
}