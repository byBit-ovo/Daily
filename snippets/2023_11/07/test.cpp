#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int my_strlen(char*s ){
    char* cur = s;
    while(*cur != '\0'){
        ++cur;
    }
    return cur-s;
}
void print(int* p){
    for(int i=0;i<5;++i){
        printf("%d ",p[i]);
    }
    cout<<endl;
}
void bubble_sort(int* p,int len){
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (p[j] > p[j + 1])
            {
                int t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
}
void ofjs(vector<int>& arr){
    int i=0,j=0;
    int len = arr.size();
    while(j < len){
        if(((arr[j])&1)==1){
            ++j;
        }
        else{
            swap(arr[i++],arr[j]);
        }
    }
}
bool is_rorate(string s1,string s2){
    if(s1.size() != s2.size()) return false;
    int len = s1.size();
    for(int i=0;i<len;++i){
        if(s1==s2) return true;
        s1+=s1.front();
        s1.erase(s1.begin());
    }
    return false;
}
void test1(){
    // char* str = "skahdd";
    // char* str2 = "akuhsidf3";
    // printf("%d\n%d\n",my_strlen(str),my_strlen(str2));
    // int arr[10] = {2,3,0,0,0,0};
    // int* p1 = arr;
    // int* p2 = arr+2;
    // printf("%ld\n",p2-p1);
}
void search_in_matrix(vector<vector<int>>& matrix,int val){

}
void test2()
{
    int arr[5] = {3, 4, 5, 1, 2};
    bubble_sort(arr, 5);
    print(arr);
    vector<int> arr2 = {3,1,5,6,7,8,3,2,4,5,9,0,12,45,23,75647};
    ofjs(arr2);
    for (const int &e : arr2)
        cout << e << " ";
        cout<<endl;
}
void test3(){
    string a = "abcdefg";
    string b = "abcdefg";
    if(is_rorate(a,b)){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
void who_is_murder(){
// A说：不是我。
// B说：是C。
// C说：是D
// D说：C在胡说
// 已知3个人说了真话，1个人说的是假话。
}
int main(){
    test3();
    return 0;
}