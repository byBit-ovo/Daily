//preSum[i] is the sum of nums[0...i)
class NumArray {
public:
    NumArray(vector<int>& nums) {
        preSum.push_back(0);
        for(int i=0;i<nums.size();++i){
            preSum.push_back(preSum.back()+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right+1] - preSum[left];
    }
private:
    std::vector<int> preSum;
};
