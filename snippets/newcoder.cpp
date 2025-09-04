#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(256,'\n');
    vector<long long> pre_sum(n);
    long long sum = 0;
    for(int i=0;i<n;++i)
    {
        long long m; cin >> m;
        if(i==0){
            pre_sum[i] = m;
        }
        else {
            pre_sum[i] = pre_sum[i-1] + m;
        }
        sum += m;
    } 
    long long res = INT_MAX;
    for(int i=0;i < n;++i)
    {
        res = min(res,pre_sum[i] * (sum - pre_sum[i]));
    }
    printf("%lld", res);
    
    return 0;
}
// 64 位输出请用 printf("%lld")