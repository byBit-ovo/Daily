#include <vector>
using namespace std;

class Solution1
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> lis(len, 1);
        int answer = 1;

        for (int i = len - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (nums[j] > nums[i])
                {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        for (auto e : lis)
        {
            answer = max(answer, e);
        }

        return answer;
    }
};


class Solution2 {
    public:
        vector<int> cache;
    
        int lengthOfLIS(vector<int>& nums) {
            int len = nums.size();
            cache.resize(len,0);
    
            int ans = 1;
            for(int i=0;i<len;++i)
            {
                ans = max(ans,dfs(nums,i));
            }    
            return ans;
        }
    
        int dfs(vector<int>& nums,int index)
        {
            if(index >= nums.size())
            {
                return 0;
            }
            if(cache[index] != 0) 
            {
                return cache[index];
            }
    
            int lans = 1;
            for(int i = index+1;i < nums.size();++i)
            {
                if(nums[i] > nums[index])
                {
                    lans = max(lans,dfs(nums,i) + 1);
                }
            }
    
            cache[index] = lans;
            return lans;
        }
    };