class Solution1 {
public:
    int numTrees(int n) {
        hash.resize(n+1,-1);
        return dfs(n);
    }
    int dfs(int n){
        if(n==0||n==1){
            hash[n]=1;
            return hash[n];
        }
        if(hash[n]!=-1) return hash[n];
        int ans = 0;
        for(int i=0;i<n;++i){
            ans += dfs(i)*dfs(n-1-i);
        }
        hash[n] = ans;
        return hash[n];
    }
private:
    vector<int> hash;
};

class Solution2 {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,1);

        for(int i=2;i<=n;++i){
            dp[i]=0;
            for(int j=0;j<i;++j){
                int subLeft = j,subRight=i-1-j;
                dp[i] += dp[subLeft]*dp[subRight];
            }
        }
        return dp[n];
    }
};
