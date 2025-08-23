#include "AVL_tree.h"
#include "RB_tree.h"
#include <vector>
void test_1(){
    AVL<string,int> tree_1;
    tree_1.insert(make_pair("i",1));
    tree_1.insert(make_pair("love",4));
    tree_1.insert(make_pair("you",3));
    tree_1.insert(make_pair("forever",7));
    tree_1.insert(make_pair("ohhh!",4));
    tree_1.In_order();
    AVL<int,int> tree;
    int a[]={16,3,7,11,9,26,18,14,15};
    for(int e:a){
        tree.insert(make_pair(e,e));
    }
    tree.In_order();
    AVL<int, int> tree_2;
    int b[] = {4, 2, 6, 1, 3, 5, 15, 7, 16,14};
    for (int e : b) {
        tree_2.insert({ e,e });
    }
    tree_2.In_order();

}
void test_2(){
    AVL<int,int> tree_1,tree_2;
    int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    int b[] = {4, 2, 6, 1, 3, 5, 15, 7, 16,14};
    for(int e:a) tree_1.insert({e,e});
    for(int e:b) tree_2.insert({e,e});

    cout<<tree_1.tree_height()<<endl;
    cout<<tree_1._is_Balance()<<endl;
    cout<<tree_2.tree_height()<<endl;
    cout<<tree_2._is_Balance()<<endl;
}
void test3(){
    RB_tree<int,int> tree_rb;
    AVL<int,int> tree_avl;
    vector<int> tmp;
    srand(time(0));
    const int N = 100000;
    for(int i=0;i<N;++i){
        int a = rand();
        // tree_avl.insert(make_pair(a,a));
        tree_rb.insert(a);
    }
    // cout<<"avl_height:"<<tree_avl.tree_height()<<endl;
    cout<<"rb_height:"<<tree_rb.tree_height()<<endl;
    RB_tree<int,int> tree_3(tree_rb);
    tree_3.insert(3);
    for(int i=0;i<999;++i){
        tree_3.insert(rand());
    }
}

int main(){
    // test_2();
    test3();
    return 0;
}