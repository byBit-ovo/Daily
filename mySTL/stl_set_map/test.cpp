#include "my_set.h"
#include "my_map.h"
void test1(){
    xunyi::set<int> st;
    for(int i=1;i<20;++i)
    st.insert(i);

    for(auto e:st){
        cout<<e<<" ";
    }
    cout<<endl;
    xunyi::set<int,my_greater<int>> st2;
    for(int i=20;i>0;i-=3){
        st2.insert(i);
    }
    for(auto e:st2){
        cout<<e<<" ";
    }
    cout<<endl;
}
void test2(){
    xunyi::map<string,int> word_count;
    word_count["into the leaves"]=13;
    word_count["done with leaves"]=13;
    word_count["e"]=1;
    word_count["love"]=4;
    word_count["you"]=3;

    word_count["e"]=6;
    word_count["love"]=66;
    word_count["tom"]=666;
    word_count["jerry"]=999;
    for(const auto& e:word_count){
        cout<<e.first<<"  "<<e.second<<endl;
    }
}
int main(){
    test2();
    //test1();
    return 0;
}