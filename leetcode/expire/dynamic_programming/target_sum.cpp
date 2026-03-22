#include <vector>
#include <string>
#include <iostream>
#include <limits.h>
#include <unordered_map>

using namespace std;

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

class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int len = nums.size();
        return dp(nums,len-1,target);
    }
    unordered_map<string,int> cache;
    int dp(vector<int>& nums,int end,int target)
    {
        if(end < 0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        string key = to_string(end) + ',' + to_string(target);
        if(cache.count(key)){
            return cache[key];
        }
        int res = 0;
        res += dp(nums,end-1,target-nums[end]);
        res += dp(nums,end-1,target+nums[end]);
        cache[key] = res;
        return res;
    }
    int a = INT_MAX;
};
int main()
{
    std::cout<<0x7fffffff<<std::endl;
    return 0;
}
