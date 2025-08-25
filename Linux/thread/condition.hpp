#pragma once
#include <pthread.h>
#include <unistd.h>

namespace LockModule
{
    class Condition{
        public:
            Condition(){
                pthread_cond_init(&_cond,nullptr);
            }
            void wait(Mutex *mutex){
                pthread_cond_wait(&_cond,mutex->getRaw());
            }
            void notify(){
                pthread_cond_signal(&_cond);
            }
            void broadcast()
            {
                pthread_cond_broadcast(&_cond);
            }
            ~Condition()
            {
                pthread_cond_destroy(&_cond);
            }
        private:
            pthread_cond_t _cond;
    };
}