#include "list.h"
using namespace std;
template<class T>
void show_list(const xunyi::List<T>& ls){
    for(auto e:ls){
        cout<<e<<" ";
    }
    cout<<endl;
}
void test1(){
    xunyi::List<int> ls1;
    ls1.push_back(1);
    ls1.push_back(2);
    ls1.push_back(3);
    ls1.push_back(4);
    ls1.push_back(5);

    xunyi::List<int> ls2;
    ls2.push_back(6);
    ls1.pop_back();
    ls1.pop_front();
    ls1.pop_front();

    show_list(ls2);
    show_list(ls1);
   
}

int main()
{
    test1();
    return 0;
}
