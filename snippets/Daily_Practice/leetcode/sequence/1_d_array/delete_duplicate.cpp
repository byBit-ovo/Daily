class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int slow =0,fast =0;
        while(fast < n)
        {
            //version 1
            // if(nums[slow] == nums[fast])
            // {
            //     ++fast;
            // }
            // else
            // {
            //     nums[++slow] = nums[fast];
            //     ++fast;
            // }
            //version 2,just look less codes
            if(nums[slow] != nums[fast])
            {
                nums[++slow] = nums[fast];
            }
            ++fast;
        }
        return slow+1;
    }
};
