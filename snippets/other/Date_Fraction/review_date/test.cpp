#include "Date.h"
void test1(){
    Date d1(2025,1,1);
    Date d2(2025,1,2);
    Date d3(2025,1,3);
    if(d2>d1) cout<<"y"<<endl;
    if(d3>d2) cout<<"y"<<endl;
}
void test2(){
    Date d1(2024,4,22);
    cout<<d1;
    d1-=6666;
    cout<<d1;
    Date d2(2000,1,7);
    d2+=1234567;
    cout<<d2;
}
void test3(){
    Date d1(1980,2,6);
    Date d2(d1+999);
    cout<<d1<<d2;
}
void test4(){
    Date d(2006,4,1);
    cout<<d;
    d--;
    cout<<d;
    cout<<++d;
}
int main(){
    //test1();
    // test2();
    // test3();
    test4();
    return 0;
}