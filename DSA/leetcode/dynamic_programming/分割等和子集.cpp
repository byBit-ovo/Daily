class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n:nums){
            sum+=n;
        }
        if(sum%2){
            return false;
        }
        int bagCap = sum/2,len=nums.size();
        vector<vector<bool>> dp(bagCap+1,vector<bool>(len+1,false));
        for(int i=0;i<=len;++i) dp[0][i]=true;
        for(int i=1;i<=bagCap;++i)
        {
            for(int j=1;j<=len;++j)
            {
                dp[i][j] = dp[i][j-1];
                if(i-nums[j-1]>=0 && dp[i-nums[j-1]][j-1])
                {
                    dp[i][j]=true;
                }
            }
        }

        return dp[bagCap][len];
    }
};
