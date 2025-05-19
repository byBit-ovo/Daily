#include <iostream>
#include <vector>
using namespace std;
using Long = long long;
int main() {
    Long n;string s; std::cin>>n>>s;
    vector<vector<Long>> dp(n,vector<Long>(3,0));
    std::string t = "shy";
    //dp[i][j] is the letter's count "shy"[0,j] in s[0,i]  
    //dp[i][j] = dp[i-1][j] + s[i]==t[j]?dp[i-1][j-1]:0; 
    if(s[0]=='s') dp[0][0] = 1;
    for(int i=1;i<n;++i){
        if(s[i]==t[0]){
            dp[i][0] = dp[i-1][0] + 1;
        }
        else{
            dp[i][0] = dp[i-1][0];
        }
    }

    for(int i=1;i<s.size();++i){
        for(int j=1;j<3;++j){
            dp[i][j] = dp[i-1][j];
            if(s[i]==t[j]){
                dp[i][j] += dp[i-1][j-1];
            }
        }
    }
    std::cout<<dp[n-1][2]<<std::endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
