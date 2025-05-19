#include "pipe.hpp"


int main(){
    umask(0);
    int ret = mkfifo(pName, 0666);
    if(ret==-1){
        std::cerr << "mkfifo error" << std::endl;
        return 1;
    }
    int fd = open(pName, O_WRONLY,0666);
    if(fd==-1){
        std::cerr << "open error" << std::endl;
        return 2;
    }
    std::cout << "writer open pipe!" << std::endl;
    char a = 'a';
    while (true)
    {
        if(write(fd, &a, 1)==-1){
            std::cerr<<"writer error"<<std::endl;
            return 1;
        }
        ++a;
        if (a == 'z'+1)  break;
        sleep(1);
    }
    unlink(pName);
    return 0;
}