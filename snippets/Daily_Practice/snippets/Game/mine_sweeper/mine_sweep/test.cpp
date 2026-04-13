#include "mine_sweep.h"
void test(){
    cout << "size: ";
    int a = 0;
    cin >> a;
    Mine s_mine(a);
    s_mine.show_map();
    s_mine.run();
}
int main(){
    test();
    return 0;
}