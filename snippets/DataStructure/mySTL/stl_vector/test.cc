#include "vector.h"
#include <iostream>
#include <list>
using namespace std;
namespace xunyi{
    void show(vector<int>& v){
        for(const auto& e:v) cout<<e<<" ";
        cout<<endl;
    }
    void test1(){
        vector<int> v1 = {1,2,3,4,5,6,7,8,9};
        vector<int> v2 = {66,6};
        show(v1);
        show(v2);
        v2 = v1;
        show(v2);
        v1[0] = 333;
        v1[3] = 333;
        show(v1);
        show(v2);

    }
    void test2(){
        vector<string> arr = {"xunyi", "666"};
        for (const auto &e : arr)
            cout << e << " ";
        cout << endl;
        vector<string> arr2(arr);
        for (const auto &e : arr2)
            cout << e << " ";
        cout << endl;
        arr[0] = "333";
        for (const auto &e : arr2)
            cout << e << " ";
        cout << endl;
                for (const auto &e : arr)
            cout << e << " ";
        cout << endl;
    }
    void test3(){
        vector<vector<char>> arr(6,vector<char>(12,'o'));
        for(auto e:arr){
            for(auto a:e)
            cout<<a<<" ";
            cout<<endl;
        }
        cout<<"size:"<<sizeof(arr)<<endl;
        cout<<sizeof(arr[0]);
    }

    void test4(){
        int** arr = (int**)malloc(24);
        for(int i=0;i<3;++i){
            arr[i] = (int*)malloc(sizeof(int)*5);
        }
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                arr[i][j] = i + j;
            }
        }
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void test5(){
        vector<vector<int>> arr(3,vector<int>(6,1));
        for(int i=0;i<3;++i){
            for(int j=0;j<6;++j){
                printf("%p ",&arr[i][j]);
            }
            cout<<endl;
        }
    }
    void test6(){
        {
            int x = 666;
            cout<<x<<endl<<&x<<endl;
        }
        {
            int y;
            cout<<y<<endl<<&y<<endl;
        }
    }
}
bool is_hao(int n){
    int flag=1;
    while(n){
        if(flag==1){
            if((n&1)==0){
                return false;
            }
            flag=0;
        }
        else{
            if((n&1)==1){
                return false;
            }
            flag=1;
        }
        n/=10;
    }
    return true;
}
void solution(){
    int n; cin>>n;
    int ans = 0;
    for(int i=1;i<=n;++i){
        if(is_hao(i)){
            ++ans;
        }
    }
    cout<<ans<<endl;
}
int main(){
    solution();  
    return 0;
}