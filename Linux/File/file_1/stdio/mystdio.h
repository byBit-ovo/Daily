#include <cstring>
#include <fcntl.h>
#include <unistd.h>

//#include <sys/stat.h>
//#include <sys/type.h>
typedef struct my_file{
    int _fd;
    char _buffer[1024];
    int _size;
    int _capacity;
} my_file;

my_file* myfopen(char* name,char* mode);

int myfwrite(const void* ptr,int num,my_file* file);

void myfflush(my_file* file);

void myfclose(my_file* file);
