#include "sort.h"
class A{
    public:
    virtual ~A(){
        cout<<"~A"<<endl;
    }
    void func1(){
        cout<<"func1"<<endl;
    }
    virtual void func2(){
        cout<<"func2"<<endl;
    }

};
// class B: public A{
//     ~B(){
//         cout<<"~B"<<endl;
//     }
// };
// void test(){
//     A tools;
//     printf("Ad of fun1: %p\n",&A::func1);
//     printf("Ad of fun2: %p\n",&A::func2);

// }
class Solution {
public:
    static int _sum;
    static int _k;
    Solution(){
        ++_k;
        _sum+=_k;
    }
    int Sum_Solution(int n) {
        Solution arr[n];
        int ret = _sum;
        return ret;
    }
};

int Solution::_sum = 0;
int Solution::_k = 0;
void test(int ){
    
}
namespace bit{
    int a = 1;
}
namespace bit2{
    int a = 1;
}
namespace bit3{
    int a = 1;
}
#include <typeinfo>
void fun(int arr[]){
    for(int i=0;i<3;++i){
        cout<<arr[i]<<endl;
    }
    cout<<typeid(arr).name()<<endl;
}
int main(){
    // Sort<int> tools;
    // vector<int> arr = {3,1,0,7,-2,5,7,3,2,2,6};
    // tools.quick_sort1(arr,0,arr.size()-1);
    // tools.show(arr);
    //test();
    int arr[3]={1,2,3};
    fun(arr);
    //int a = 0;
    //cout<<&a<<endl;
    //cout<<&bit::a<<endl;
    //cout<<&bit3::a<<endl;
    //cout<<&bit2::a<<endl;
    //cout<<&::a<<endl;

    return 0;
}
