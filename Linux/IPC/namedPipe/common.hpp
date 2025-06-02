#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
const std::string gpipeName = "pipe";
const int _openForRead = O_RDONLY;
const int _openForWrite = O_WRONLY;
const mode_t gmode = 0600; //rw- --- ---
const int gsize = 1024;

int openPipe(int flag)
{
    int fd = ::open(gpipeName.c_str(), flag,gmode);
    if(fd==-1){
        std::cerr << "pipe open fail!" << std::endl;
        exit(0);
    }
    return fd;
}

void closePipe(int fd){
    ::close(fd);
}