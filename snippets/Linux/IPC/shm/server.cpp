#include "shareMem.hpp"

int main()
{
    shm shm_1(gName, gId);
    shm_1.creatShm();
    shm_1.attach();
    char *shmAdr = (char *)shm_1.getAdr();
    // for (int i = 0; i < 10; ++i)
    // {
    //     shmAdr[i] = 'a' + i;
    //     sleep(3);
    // }
    // for (int i = 0; i < 10;++i){
    //     if(shmAdr[i]==0){
    //         std::cout << "this is \\0" << std::endl;
    //     }
    // }
    shm_1.detach();
    shm_1.dltshm();
    return 0;
}
