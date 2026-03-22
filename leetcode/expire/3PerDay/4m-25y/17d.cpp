#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {

    int n;cin>>n;
    unordered_set<string> count;
    for(int i=0;i<n;++i)
    {
        string a; cin>>a;
        sort(a.begin(),a.end());
        count.insert(a);
    }

    std::cout<<count.size()<<std::endl;
    return 0;
}
// 64 位输出请用 printf("%lld")