#include <iostream>
using namespace std;

int main() {
    int ans =0,base=1;
    int n;cin>>n;
    while(n)
    {
        ans += n%2*base;
        base*=10;
        n/=10;
    }
    cout<<ans;
    return 0;
}
// 64 位输出请用 printf("%lld")