#include <vector>
#include <iostream>

void quickSort(std::vector<int>& arr, int start, int end)
{
    if(start >= end){
        return;
    }
    int head = start,tail = end;
    int pivot = arr[start];
    while(start < end)
    {
        while(start < end && arr[end] >= pivot){
            --end;
        }
        while(start < end && arr[start] <= pivot){
            ++start;
        }
        std::swap(arr[start],arr[end]);
    }
    std::swap(arr[head], arr[start]);

    quickSort(arr,head,start-1);
    quickSort(arr,start+1,tail);
}


void mergeSort(std::vector<int> &arr,int start, int end)
{
    if(start >= end){
        return;
    }
    int mid = start + (end - start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    std::vector<int> tmp(end-start+1);
    int i  = start, j = mid + 1;
    int tail = 0;
    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j]){
            tmp[tail++] = arr[i++];
        }
        else
        {
            tmp[tail++] = arr[j++];
        }
    }
    while(i<=mid){
        tmp[tail++] = arr[i++];
    }
    while(j<=end){
        tmp[tail++] = arr[j++];
    }
    for(int i=0;i<tmp.size();++i){
        arr[start+i] = tmp[i];
    }
}

int main()
{
    std::vector<int> arr = {5, 1, 2, 3, 4};   // start = 0, end = 4, pivot = 5
    // quickSort(arr,0,arr.size() - 1);
    mergeSort(arr,0,arr.size());
    for(int e:arr){
        std::cout<<e<<" ";
    }
    std::cout<<std::endl;
    return 0;
}