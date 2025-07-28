class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0,fast=0;
        int n = nums.size();
        while(fast < n)
        {
            if(nums[fast]!=val)
            {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }
        return slow;
    }
};
