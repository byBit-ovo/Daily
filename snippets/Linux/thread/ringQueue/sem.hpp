#include <semaphore.h>
#include <iostream>

class sem
{
public:
    sem(int initValue=1) {sem_init(&_sem, 0, initValue);}
    void P() { sem_wait(&_sem); }
    void V() { sem_post(&_sem); }
    ~sem()   { sem_destroy(&_sem); }
private:
    sem_t _sem;
};