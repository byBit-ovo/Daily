#include "test.h"

int main(){
    for(int i=0;i<10;++i){
        if(fork()==0){
            std::cout<<"I am a child process,my pid: "<<getpid()<<std::endl;
            return 1;
        }
        sleep(1);
    }
    sleep(20);
    return 0;
}
