#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        //dp[i][j]表示从coins[0,i)中任选硬币，能够凑成j元的组合数
        vector<vector<double>> dp(len+1,vector<double>(amount+1,0));
        for(int i=0;i<=len;++i) dp[i][0]=1;

        for(int i=1;i<=len;++i)
        {
            for(int j=1;j<=amount;++j)
            {
                //不使用当前硬币coins[i-1]
                dp[i][j] += dp[i-1][j];
                //使用当前硬币coins[i-1]
                if(j-coins[i-1] >=0 )
                {
                    dp[i][j]+=dp[i][j-coins[i-1]];
                }               
            }
        }
        for(auto& v: dp)
        {
            for(int e: v)
            {
                std::cout<<e<<" ";
            }
            std::cout<<std::endl;
        }
        return dp[len][amount];
    }
};

int main()
{
    Solution tool;
    vector<int> coins = {2,5,7};
    tool.change(38,coins);
    return 0;
}