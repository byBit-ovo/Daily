class Solution {
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