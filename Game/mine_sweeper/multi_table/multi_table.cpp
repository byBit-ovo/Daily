#include <iostream>
#include <math.h>
using namespace std;
void m_table(int size = 9)
{
    cout << "size:";
    cin >> size;

    for (int i = 1; i <= size; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << j << "*" << i << "=" << i * j << " ";
        }
        cout << endl;
    }
}
bool is_run_year(int year){
    return year%400==0 || (year%4==0 && year%100!=0);
}
bool is_prime(int k){
    if(k<=1) return false;
    if(k==2) return true;
    if((k&1)==0) return false;
    for(int i = 3;i<=sqrt(k);i+=2){
        if(k%i==0)
        return false;
    }
    return true;
}
void init(int* a,int len){
    for(int i=0;i<len;++i){
        a[i]=i;
    }
}
void print(int* a,int len){
    for(int i=0;i<len;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void reverse(int* a,int len){
    int i=0;
    int j=9;
    while(i<j){
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        ++i;
        --j;
    }
}
int main()
{
    int arr[10];
    init(arr,sizeof(arr)/sizeof(arr[0]));
    print(arr,sizeof(arr)/sizeof(arr[0]));
    reverse(arr,sizeof(arr)/sizeof(arr[0]));
    print(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}