class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int len = nums.size();
        return dp(nums,len-1,target);
    }

    int dp(vector<int>& nums,int end,int target)
    {
        if(end < 0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        int res = 0;
        res += dp(nums,end-1,target-nums[end]);
        res += dp(nums,end-1,target+nums[end]);
        return res;
    }
};
