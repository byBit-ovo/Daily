class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        dp[1][1]=grid[0][0];
        dp[0][1]= dp[1][0] = 0;
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};
class Solution2 {
public:
    vector<vector<int>> cache;
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size(),n=grid[0].size();
        cache.resize(m,vector<int>(n,-1));
        return dp(grid,m-1,n-1);
    }

    int dp(vector<vector<int>>& grid,int x,int y)
    {
        if(x<0 || y<0){
            return INT_MAX;
        }
        if(x==0 && y==0){
            return grid[0][0];
        }
        if(cache[x][y]!=-1){
            return cache[x][y];
        }
        cache[x][y] = min(dp(grid,x-1,y),dp(grid,x,y-1)) + grid[x][y];
        return cache[x][y];
    }
};
