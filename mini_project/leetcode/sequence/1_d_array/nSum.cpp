class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> valToPos;
        for(int i=0;i<nums.size();++i){
            if(valToPos.count(target-nums[i])){
                return {i,valToPos[target-nums[i]]};
            }
            valToPos[nums[i]] = i;
        }
        return {-1,-1};
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();){
            int n = nums[i];
            unordered_set<int> hash;
            for(int j=i+1;j<nums.size();){
                int m = nums[j];
                if(hash.count(-n-m)){
                    res.push_back({n,m,-n-m});
                    while(j<nums.size()&&nums[j]==m) ++j;
                }else{
                    hash.insert(m);
                    ++j;
                }
            }
            while(i<nums.size() && nums[i]==n) ++i;
        }
        return res;
    }
};