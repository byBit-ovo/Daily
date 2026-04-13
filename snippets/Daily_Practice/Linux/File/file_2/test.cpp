#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>
#include <sys/stat.h>
void testC(){
    // FILE* file = fopen("bite.txt", "r+");
    // char s[] = "Linux is so easy\n";
    // fwrite(s, sizeof(char), sizeof(s),file);
    // char buffer[30];
    // rewind(file);  

    // fread(buffer,sizeof(char),sizeof(s),file);
    // fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    // char buffer[5];
    // fread(buffer, sizeof(char), sizeof(buffer) - 1,file);
    // buffer[4]=0;
    // printf("从文件中读到了%s\n", buffer);
    // char text[5] = {'a', 'p', 'p', 'l', 'e'};
    // fwrite(text, sizeof(char), sizeof(text), file);
    // fclose(file);
}
void testSystem(){
    int fd = open("bite.txt", O_RDWR | O_TRUNC, 0666);
    const char* buffer = "I like Linux";
    write(fd,buffer,strlen(buffer));
    lseek(fd, 0, SEEK_SET);
    char buff[20];
    int n = read(fd,buff,20);
    if(n < 0){
        std::cout<<strerror(errno)<<std::endl;
        close(fd);
        return ;
    }
    buff[n]= 0;
    printf("%s\n", buff);
    close(fd);

}
void replace(){
    int fd = open("qzr.txt", O_WRONLY | O_CREAT,0666);
    if(fd < 0){
        std::cout<<"open error"<<std::endl;
        return ;
    }
    dup2(fd,1);
    close(fd);
    char buffer[] = "I love coding";
    printf("%s\n", buffer);
}

int main()
{
    // int fd = open("qzr.txt", O_RDWR | O_CREAT | O_APPEND,0666);
    // if(fd < 0){
    //     std::cout<<"open error"<<std::endl;
    //     return 1;
    // }
    // char buffer[] = "I love coding";
    // printf("%s\n", buffer);
    // close(fd);
    dup2(1,2);
    fprintf(stderr,"%s\n","abs");
    return 0;
}