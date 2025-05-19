#include <iostream>
using namespace std;
int bottles1(int total,int single_price){
    int bot = total/single_price;
    int empty = bot;
    while(empty>=2){
        int exchange = empty/2;
        bot += exchange;
        empty = exchange+(empty%2);
    }
    return bot;
}
int bottles2(int empty){
    if(empty < 2) return 0;
    int exchange = empty/2;
    return exchange + bottles2(exchange+empty%2);
}
int fun2(int total, int single_price)
{
    int bot = total / single_price;
    int empty = bot;
    bot += bottles2(empty);
    return bot;
}

int bit_sum(int n){
    int ret = 0;
    int low_bit = n;
    for(int i=0;i<5;++i){
        ret += n;
        n = n*10+low_bit;
    }
    return ret;
}

void show_graph(int size){
    for(int i=0;i<size;++i){
        for(int j=0;j<size-i;++j){
            cout<<" ";
        }
        for(int k =0;k<i*2+1;++k){
            cout<<'*';
        }
        cout<<endl;
    }
    for(int i=1;i<size;++i){
        for(int j=0;j<=i;++j){
            cout<<" ";
        }
        for(int k=0;k<(size-i-1)*2+1;++k){
            cout<<'*';
        }
        cout<<endl;
    }
}
int main(){
    // int price = 0;
    // int money = 0;
    // cin>>money>>price;
    // cout<<bottles1(money,price)<<endl<<fun2(money,price)<<endl;
    // cout<<bit_sum(3);
    show_graph(5);
    return 0;
}