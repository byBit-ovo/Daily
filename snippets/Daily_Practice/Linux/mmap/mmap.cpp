#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <iostream>
void sharedMem(){
    int fd = open("map_test.txt",O_CREAT | O_RDWR | O_APPEND,0666);
    if(fd < 0){
        std::cout<<"文件打开失败"<<std::endl;
        return;
    }
    ftruncate(fd,1024*4);
    void *addr = mmap(nullptr,1024*4,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    if(addr==MAP_FAILED){
        std::cout<<"映射地址失败"<<std::endl;
    }
    char *p = reinterpret_cast<char*>(addr);
    for(int i=0;i<26;++i){
        p[i] = 'a'+i+1;
        sleep(1);
    }

    munmap(addr,1024*4);
    close(fd);
}
int main()
{

    return 0;
}