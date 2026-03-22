#include "bst.h"
#include "Date.h"
#include "my_map.h"
void test()
{
    BST<int> tree_1;
    tree_1.insert(3);
    tree_1.insert(0);
    tree_1.insert(6);
    tree_1.insert(1);
    tree_1.insert(-4);
    tree_1.In_order();
}
void test_2(){
    BST<Date> tree_1;
    srand(time(0));
    tree_1.insert(Date(1980,1,1));
    tree_1.insert(Date(1993,4,3));
    tree_1.insert(Date(2023,8,9));
    tree_1.insert(Date(2000,5,9));
    tree_1.insert(Date(1949,10,1));
    tree_1.In_order();
    cout << endl;
    tree_1.erase(Date(1980, 1, 1));
    tree_1.In_order();
    cout << endl;
    tree_1.erase(Date(1993, 4, 3));
    tree_1.In_order();
    cout<<endl;

    tree_1.erase(Date(2023,8,9));
    tree_1.In_order();
    cout<<endl;

    tree_1.erase(Date(2000,5,9));
    tree_1.In_order();
    cout<<endl;

    tree_1.erase(Date(1949,10,1));
    tree_1.In_order();
    cout<<endl;

}
void test_3(){
    srand(time(0));
    BST<int> tree_1;
    for(int i=-3;i<9;++i) tree_1.insert(i);
    tree_1.In_order();
    cout<<endl;
    int flag[12]={0};
    while (!tree_1.empty())
    {
        int w = rand() % 12 - 3;
        while (flag[w+3] != 1)
        {
            flag[w+3] = 1;
            tree_1.erase(w);
            tree_1.In_order();
            cout << endl;
        }
    }
}
void test_4(){
    KV::my_map<string,string> dict;
    dict.insert("定住","immbolize");
    dict.insert("叶隐","into the leaves");
    dict.insert("凉快去","take a hike");
    dict.insert("变化","change");
    dict.insert("扫尘","gone with leaves");
    string str;
    // while(cin>>str){
    //     auto ret = dict.find(str);
    //     if(ret){
    //         cout<<ret->_value<<endl;
    //     }
    //     else{
    //         cout<<"not found"<<endl;
    //     }
    // }
    KV::my_map<string,string> dict2(dict);
    dict.In_order();
    dict2.In_order();
}
int main()
{
    // test_2();
    // test_3();
    test_4();
    return 0;
}