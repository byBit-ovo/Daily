#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include<cstring>
#include <sys/stat.h>

int main(){
    printf("hello printf:1\n");
    fprintf(stdout,"hello fprintf:2\n");
    fwrite("hello:fwrite:3\n",1,15,stdout);

    write(1,"write:4\n",8);
    write(1,"write:4\n",8);
    write(1,"write:4\n",8);
    write(1,"write:4\n",8);
    write(1,"write:4\n",8);
    fflush(stdout);
    fork();









   //umask(0);
   //int dr = open("log.txt",O_WRONLY | O_CREAT | O_APPEND,0666);
   //const char* luck = "what a fucking good day\n";
   //write(dr,luck,strlen(luck));
   //close(dr);
    return 0;
}
