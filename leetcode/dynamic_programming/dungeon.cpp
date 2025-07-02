class Solution {
public:
    int m,n;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //dp[i][j] : 从dungeon[i][j]到dungeon[m][n]的最低血量
        m=dungeon.size(),n=dungeon[0].size();
        return dp(dungeon,0,0);
    }

    int dp(vector<vector<int>>& dungeon,int i,int j)
    {
        if(i==m-1 && j==n-1){
            return 0;
        }

        if(dungeon[i][j])
    }
};
