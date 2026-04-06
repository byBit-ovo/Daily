#include "mine_sweep.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
int Binary_search(vector<T>& arr,T aim){
    int i = 0;
    int j = arr.size()-1;
    while(i<=j){
        int mid = i+((j-i)>>1);
        if(arr[mid]>aim){
            j=mid-1;
        }
        else if(arr[mid] < aim){
            i = mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int> arr ={0,3,5,6,7,8,9,12,34};
    for(int i=0;i<arr.size();++i){
        cout<<"arr["<<Binary_search<int>(arr,arr[i]) << "] is " << arr[i] << endl;
    }
    return 0;
}