#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Long = long long;
//删除相邻数字的最大分数
int main() {
    int n; cin>>n;
    std::vector<int> num(n);
    for(int i=0;i<n;++i)
    {
        cin>>num[i];
    }

    Long sum[10001]={0};

    for(int i=0;i<n;++i)
    {
        sum[num[i]] += num[i];
    }

    Long dp[10001] = {0};
    dp[0] = sum[0];
    if(n>=2)
    {
        dp[1] = max(sum[0],sum[1]);
    }

    for(int i=2;i<10001;++i)
    {
        dp[i] = max(sum[i] + dp[i-2],dp[i-1]);
    }

    cout<<dp[10000]<<endl;

    return 0;
}
// 64 位输出请用 printf("%lld")