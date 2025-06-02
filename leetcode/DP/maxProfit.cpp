#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int p = prices[0];
            int ans = 0;
    
            for(int i=1;i<prices.size();++i)
            {
                if(prices[i] > p)
                {
                    ans = max(ans,prices[i] - p);
                }
                else
                {
                    p = prices[i];
                }
            }
    
            return ans;
        }
    };