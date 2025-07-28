#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include <stack>
#include <string>
using namespace std;

template <class T>
class Sort
{
    public:

    void Print_arr(vector<T>& arr);
    void insert_sort(vector<T>& arr);
    void shell_sort(vector<T>& arr);
    void select_sort(vector<T>& arr);
    static void quick_sort1(vector<T>& arr,int left,int right){
        if(left >= right)
        return;
        int key = arr[left];
        int prev = left,cur = left;
        while(cur <= right){
            if(arr[cur] >= key){
                ++cur;
            }
            else{
                swap(arr[prev++],arr[cur++]);
            }
        }
        if (prev > 0)
        {
            swap(arr[left], arr[prev - 1]);
        }
        quick_sort1(arr,left,prev-1);
        quick_sort1(arr,prev+1,right);
    }
    void quick_sort2(vector<T>& arr);
    void quick_sort3(vector<T>& arr);
    void bubble_sort(vector<T>& arr);
    void heap_sort(vector<T>& arr);
    void merge_sort(vector<T>& arr);
    void show(vector<int>& arr){
        for(const auto e: arr){
            cout<<e<<" ";
        }
        cout<<endl;
    }
};
