//clever solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int l0 =0,l2 = len - 1; //0:[0,l0)
        for(int i=0;i<=l2;){    //2:(l2,len-1]
            if(nums[i]==0){
                swap(nums[i++],nums[l0++]);
            }
            else if(nums[i]==2){
                swap(nums[i],nums[l2--]);// 0 may be placed on nums[i],so do not increment i
            }
            else{
                ++i;
            }
        }
    }
};
