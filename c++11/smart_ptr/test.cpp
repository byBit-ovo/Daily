#include "st_ptr.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
using xy::shared_ptr;
using xy::weak_ptr;
struct node{
    weak_ptr<node> _next;
    weak_ptr<node> _prev;
    int _data;
    node(int data=0):
        _data(data),
        _prev(nullptr),
        _next(nullptr){}
};
int main()
{
    pid_t id = fork();
    if(id<0){
        cout << strerror(errno) << endl;
    }
    else if(id==0){
        int cnt = 5;
        while(cnt--){
            sleep(1);
            cout << "I am child process,my id:" << getpid() << endl;
        }
    }
    else{
        pid_t id = wait(nullptr);
        cout<<"wait sucess,child id:"<<id<<endl;
        cout << "I am parent" << endl;
    }
    return 0;
}