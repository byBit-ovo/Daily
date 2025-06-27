#include <vector>
using namespace std;
class Solution1
{
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int p0 = 0,p2 = len -  1;
        vector<int> ans(len);
        int i = 0;
        for(;i<len;++i)
        {
            if(nums[i]==0) ans[p0++] = 0;
            else if(nums[i]==2) ans[p2--] = 2;
        }

        for(int i=p0;i<=p2;++i) ans[i] = 1;
        nums = ans;
    }
};

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int hash[3]={0};
        for(int e:nums) ++hash[e];
        int j = 0;
        
        for(int i =0;i<3;++i){
            while(hash[i]--){
                nums[j++] = i;
            }
        }
    }
};
