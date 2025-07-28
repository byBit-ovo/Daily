#include "container.h"
#include <iostream>
#include <deque>
using namespace std;
namespace xunyi{
    void test(){
    vector<int> q = {3,5,7,8,9,2,3,4,1,0,3,45,6,7};
    priority_queue<int> qq(q.begin(),q.end());
    while(!qq.empty()){
        cout<<qq.top()<<" ";
        qq.pop();
    }
    cout<<endl;
}
}
int main(){
    xunyi::test();
    return 0;
}