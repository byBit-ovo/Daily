#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t id = fork();
    if(id==0){
        // execl("/bin/python3","python3","/home/xunyi/gitee/Daily_Practice/snippets/python/test.py");
        execl("/bin/bash","bash","/home/xunyi/gitee/Daily_Practice/snippets/python/test.sh");
        exit(0);
    }
    pid_t rid = wait(nullptr);
    printf("子进程退出!\n");
    const char * const env[] = {"hello","hjfoad"};
    const char* env2[] = {":ehf","fjsaf"};
    printf("%s",env2[0]);
    return 0;
}