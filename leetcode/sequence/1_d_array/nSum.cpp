//Remember : When the direct approach fails, try the opposite.
//Remember : If the front door is locked, try the back.

#include <vector>
#include <unordered_map>
using namespace std;
class Solution1
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();++i)
        {
            hash[nums[i]] = i;
        }
        for(int i=0;i<nums.size();++i)
        {
            if(hash.count(target - nums[i]) && i!=hash[target -nums[i]])
            {
                return {i,hash[target -nums[i]]};
            }
        }
        return {-1,-1};
    }
};


//Don't miss any detail that can be optimized 
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();++i)
        {
            if(hash.count(target-nums[i]))
            {
                return {i,hash[target-nums[i]]};
            }
            hash[nums[i]] = i;
        }
        return {-1,-1};
    }
};

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