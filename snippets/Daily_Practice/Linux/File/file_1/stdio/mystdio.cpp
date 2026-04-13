#include "mystdio.h"


my_file* myfopen(char* name,char* mode){
    int fd = -1;
    if(strcmp(mode, "r") == 0)
    {
        fd = open(name, O_RDONLY);
    }
    else if(strcmp(mode, "w")== 0)
    {
        fd = open(name, O_CREAT|O_WRONLY|O_TRUNC, 0666);
    }
    else if(strcmp(mode, "a") == 0)
    {
        fd = open(name, O_CREAT|O_WRONLY|O_APPEND, 0666);
    }

    my_file* file  = new my_file();
    file->_fd = fd;
    file->_size = file->_capacity = 0;
    return file;
}

int myfwrite(const void* ptr,int num,my_file* file){
    if(num + file->_size > file->_capacity){
        myfflush(file);
    }

    memcpy(file->_buffer,ptr,num);
    file->_size +=num;
    if (file->_size > 0 && file->_buffer[file->_size - 1] == '\n')
    {
        myfflush(file);
        file->_size = 0;
    }
    return num;
}

void myfflush(my_file* file){
    if(file->_size>0){
        write(file->_fd,file->_buffer,file->_size);
        file->_size=0;
    }
}

void myfclose(my_file* file){
    myfflush(file);
    close(file->_fd);
    delete file;
}
