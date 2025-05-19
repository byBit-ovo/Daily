#include <iostream>
#include <assert.h>
using namespace std;
void menu(){
    cout<<"1. add         "<<"2. minus    "<<endl;
    cout<<"3. multiple    "<<"4. divide    "<<endl;
    cout<<"5. exit        "<<"             "<<endl;
    cout<<"Input: ";
}
int Add(int x,int y){return x+y;}
int Minus(int x,int y){return x-y;}
int multiple(int x,int y){return x*y;}
int divide(int x,int y){assert(y!=0); return x/y;}
int (*cal[4])(int,int) = {Add,Minus,multiple,divide};
int main(){
    int input = 0;
    while(1){
        menu();
        cin>>input;
        if(input>=1 && input<=4){
            cout<<"two numbers:";
            int a,b;
            cin>>a>>b; cout<<endl;
            cout<<cal[input-1](a,b)<<endl;
        }
        else if(input==5){
            break;
        }
        else{
            continue;
        }

    }
    return 0;
}