#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
int main(){
    const char * p = "hello world\n";
    write(0,p,strlen(p));
    printf("%d",stdin->_fileno);
    
    return 0;
}