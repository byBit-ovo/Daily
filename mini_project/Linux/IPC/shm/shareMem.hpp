#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <iostream>
#include <sys/shm.h>
const char* gName = "/home/xunyi/gitee/mini_program/lnx/shm";
const char gId = 'a';
const int gSize = 1024*4;
const mode_t gMode = 0600;
class shm{
public:
private:
    void creatOrGet(int flag){
        _shmid = ::shmget(_key,gSize,flag);
        if(_shmid==-1){
            std::cerr<<"shmget error"<<std::endl;
            exit(2);
        }
    }
    int _shmid;
    key_t _key;
    void* _adr;
public:
    shm(const char* name,int id){
        _key = ::ftok(name,id);
        if(_key==-1){
            std::cerr<<"ftok error"<<std::endl;
            exit(1);
        }
    }
    void creatShm(){
        creatOrGet(IPC_CREAT|IPC_EXCL|gMode);
    }
    void getShm(){
        creatOrGet(IPC_CREAT);
    }
    void attach(){
        _adr = ::shmat(_shmid,nullptr,0);
        if(_adr==(void*)-1){
            std::cerr<<"shmat error"<<std::endl;
        }
    }
    void detach(){
        if(_adr!=nullptr){
            ::shmdt(_adr);
        }
    }

    void dltshm(){
        ::shmctl(_shmid,IPC_RMID,nullptr);
    }
    void* getAdr(){
        return  _adr;
    }

};
