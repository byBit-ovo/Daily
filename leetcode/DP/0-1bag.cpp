#include <vector>

class Solution1
{
    public:
        int bag01(int cap,std::vector<int>& weight,std::vector<int>& value)
        {
            int count = weight.size();
            std::vector<std::vector<int>> dp(cap+1,std::vector<int>(count+1,0));
            for(int i=1;i<=cap;++i)
            {
                for(int j=1;j<=count;++j)
                {
                    int addThis = 0;
                    if(weight[j-1] <= i)
                    {
                        addThis = value[j-1] + dp[i-weight[j-1]][j-1];
                    }
                    dp[i][j] = std::max(addThis,dp[i][j-1]);
                }
            }
            return dp[cap][count];
        }
};

class Solution2
{
    public:
        std::vector<std::vector<int>> cache;

        int bag01(int cap,std::vector<int>& weight,std::vector<int>& value)
        {
            int count = weight.size();
            cache.resize(cap+1,std::vector<int>(count+1,-1));
            return dp(cap,weight,value,count);
        }

        int dp(int cap,std::vector<int>& weight,std::vector<int>& value,int k)
        {
            if(k<=0 || cap <= 0){
                return 0;
            }
            if(cache[cap][k]!=-1){
                return cache[cap][k];
            }
            int a = 0;
            if(cap >= weight[k-1]){
                a = value[k-1] + dp(cap-weight[k-1],weight,value,k-1);
            }
            int b = dp(cap,weight,value,k-1); 
            cache[cap][k]=std::max(a,b);
            return cache[cap][k];
        }
};