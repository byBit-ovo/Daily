#include <iostream>
using namespace std;
void my_swap(void* p1,void* p2,int size){
    for(int i=0;i<size;++i){
        char tmp = *((char*)p1+i);
        *((char*)p1+i)= *((char*)p2+i);
        *((char*)p2+i) = tmp;
    }
}
bool my_comp(void* p1,void*p2,int size){
    return *((short*)p1) - *((short*)p2) > 0;
}
void my_qsort(void* base,int size,int count,bool (*compare)(void*,void*,int)){
    for(int i=0;i<count-1;++i){
        for(int j=0;j<count-1-i;++j){
            if(compare((char*)base+j*size,(char*)base+(j+1)*size,size)){
                my_swap((char*)base+j*size,(char*)base+(j+1)*size,size);
            }
        }
    }
}

int main(){
    short arr[8] = {4,1,6,3,8,0,2,5};
    my_qsort(arr,sizeof(short),8,my_comp);
    for(auto e:arr){
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}