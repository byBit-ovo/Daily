#include <semaphore.h>
class Sem{
    public:
        Sem(int num):_num(num){
            //shared in threads
            sem_init(&_sem,0,_num);
        }
        void P()
        {
            sem_wait(&_sem);
        }
        void V()
        {
            sem_post(&_sem);
        }
        ~Sem(){
            sem_destroy(&_sem);
        }
    private:
        sem_t _sem;
        int _num;
};