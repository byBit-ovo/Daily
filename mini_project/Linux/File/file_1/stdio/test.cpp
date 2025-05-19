#include "mystdio.h"

int main(){

    my_file* file1 = myfopen("log.txt","w");
    if(file1==nullptr)
        return 1;
    char buffer[1024] = "hello tencent!\n";
    int cnt = 10;
    while(cnt--){
        buffer[0] = cnt + '0';
        myfwrite(buffer, strlen(buffer), file1);
        sleep(1);
    }
    myfclose(file1);
    return 0;
}
