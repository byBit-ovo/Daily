class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.size(),lt=t.size();
        if(ls<lt){
            return 0;
        }
        //dp[i][j] : s[0,i]中出现了dp[i][j]次t[0,i]
        vector<vector<int>> dp(ls,vector<int>(lt,0));
        if(s[0]==t[0]){
            dp[0][0]=1;
        }
        for(int i=1;i<ls;++i){
            dp[i][0]=dp[i-1][0];
            if(s[i]==t[0]){
                ++dp[i][0];
            }
        }
        for(int i=1;i<ls;++i){
            for(int j=1;j<lt;++j){
                dp[i][j] = dp[i-1][j];
                if(t[j]==s[i]){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[ls-1][lt-1];
    }
};