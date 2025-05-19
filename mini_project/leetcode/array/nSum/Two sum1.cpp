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