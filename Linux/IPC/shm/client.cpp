#include "shareMem.hpp"

int main()
{
    shm shm_1(gName, gId);
    shm_1.getShm();
    shm_1.attach();
    char *shmAdr = (char *)shm_1.getAdr();
    for (int i = 0; i < 10; ++i)
    {
        ::printf("%s\n", shmAdr);
        sleep(1);
    }
    shm_1.detach();
    return 0;
}