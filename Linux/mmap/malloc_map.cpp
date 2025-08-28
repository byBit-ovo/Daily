#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <iostream>
void *my_malloc(int size)
{
    if(size > 0){
        void *addr = mmap(nullptr,size,PROT_READ | PROT_WRITE,MAP_PRIVATE | MAP_ANONYMOUS,-1,0);
        if(addr != MAP_FAILED){
            return addr;
        }
    }
    return nullptr;
}
void *my_free(void *addr,int size){
    if(addr != nullptr && size > 0){
        munmap(addr,size);
    }
    return nullptr;
}
int main(){
    void *addr = my_malloc(1024);
    if(addr == nullptr){
        std::cout<<"申请错误"<<std::endl;
        return 1;
    }
    char *p = reinterpret_cast<char*>(addr);
    for(char c='a';c<'z'+1;++c){
        p[c-'a'] = c;
        std::cout<<p<<std::endl;
    }
    
    my_free(addr,1024);
    return 0;
}