#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <cstring>


int main()
{
    FILE* file = fopen("bite.txt", "r+");
    // char s[] = "Linux is so easy\n";
    // fwrite(s, sizeof(char), sizeof(s),file);
    // char buffer[30];
    // rewind(file);  

    // fread(buffer,sizeof(char),sizeof(s),file);
    // fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    char buffer[5];
    fread(buffer, sizeof(char), sizeof(buffer) - 1,file);
    buffer[4]=0;
    printf("从文件中读到了%s\n", buffer);
    char text[5] = {'a', 'p', 'p', 'l', 'e'};
    fwrite(text, sizeof(char), sizeof(text), file);
    fclose(file);
    //Linuapplex is so easy 
    return 0;
}