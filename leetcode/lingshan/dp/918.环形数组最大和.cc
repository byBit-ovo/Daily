class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) {
            int max_dp = nums[0], min_dp = nums[0];
            int cur_max = 0, cur_min = 0, sum = 0;
            for(int n: nums) {
                sum += n;
                if(cur_max >= 0){
                    cur_max += n; 
                }else{
                    cur_max = n;
                }
    
                if(cur_min <= 0) {
                    cur_min += n;
                }else{
                    cur_min = n;
                }
                max_dp = max(cur_max, max_dp);
                min_dp = min(min_dp, cur_min);
            }
            if(max_dp < 0) {
                return max_dp;
            }
            return max(max_dp, sum - min_dp);
        }
    };