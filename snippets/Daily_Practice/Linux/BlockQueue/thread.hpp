#pragma once
#include <pthread.h>
#include <functional>
#include <unistd.h>
#include <stdio.h>

namespace LockModule
{
    enum class threadStatus: int{
        NEW,
        RUNNING,
        CANCELED,
        JOINED,
        DETACHED,
    };
    template<class ArgT>
    class Thread
    {
        public:
            using Fn = std::function<void(ArgT)>;
            static void *threadEntry(void *p)
            {
                Thread* self_pointer = reinterpret_cast<Thread*>(p);
                self_pointer->_threadfunc(self_pointer->_args);
                return nullptr;
            }
            Thread(const Fn &func,ArgT args)
            :_threadfunc(func),_args(args),_sta(threadStatus::NEW)
            {
            }
            void start(){
                int n = pthread_create(&_tid,nullptr,threadEntry,this);
                    if(n==0){
                    _sta = threadStatus::RUNNING;
                    printf("%0lx start!\n",_tid);
                }
            }
            void join(){
                if(_sta == threadStatus::RUNNING)
                {
                    int n = pthread_join(_tid,nullptr);
                    if(n==0){
                        printf("%0lx joined!\n",_tid);
                        _sta = threadStatus::JOINED;
                    }
                }
            }
        private:
            pthread_t _tid;
            Fn _threadfunc;
            ArgT _args;
            threadStatus _sta;
    };
    
}