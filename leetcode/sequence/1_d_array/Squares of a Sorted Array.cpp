class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> tmp(len);
        int index = len-1; 
        for(int i=0,j=len-1;i<=j;)
        {
            if(abs(nums[i]) < abs(nums[j]))
            {
                tmp[index] = nums[j]*nums[j]; --j;
            }
            else
            {
                tmp[index] = nums[i] * nums[i]; ++i;
            }
            --index;
        }
        return tmp;
    }
};