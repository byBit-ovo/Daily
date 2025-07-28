#include "pipe.hpp"

int main(){
    int fd = open(pName, O_RDONLY,0666);
    if(fd==-1){
        std::cerr << "open error" << std::endl;
        return 2;
    }
    std::cout << "reader2 open pipe!" << std::endl;
    char a;
    while(true){
        int c = read(fd, &a, 1);
        if(c==0){
            std::cout << "writer close" << std::endl;
            exit(1);
        }
        std::cout <<"reader2:"<< a<<std::endl;
        sleep(1);
    }
    return 0;
}
