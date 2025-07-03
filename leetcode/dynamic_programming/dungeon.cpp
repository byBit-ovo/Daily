class Solution {
public:
    int m,n;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //dp[i][j]表示从dp[i][j]到达dp[m-1][n-1]时的最低生命值
        m=dungeon.size(),n=dungeon[0].size();
        return dp(dungeon,0,0);
    }

    int dp(vector<vector<int>>& dungeon,int i,int j)
    {
        if(i>=m || j>=n){
            return INT_MAX;
        }
        if(i==m-1 && j==n-1){
            if(dungeon[i][j] >= 0){
                return 1;
            }
            return 1-dungeon[i][j];
        }
        int next = min(dp(dungeon,i,j+1),dp(dungeon,i+1,j));

        if(dungeon[i][j] >= next){
            return 1;
        }

        if(dungeon[i][j] < 0)
        {
            int minHp = 1-dungeon[i][j];
            return max(minHp,next);
        }
        else
        {
            return next - dungeon[i][j];
        }
    }
};