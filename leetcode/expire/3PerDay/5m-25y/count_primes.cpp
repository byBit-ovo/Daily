#include <vector>
using namespace std;

class Solution
{
    std::vector<bool> hash;
public:
    void Load(int n)
    {
        hash.resize(n,true);
        for(int i=2;i*i<n;++i)
        {
            if(hash[i])
            {
                for(int j = i; j*i < n; ++j)
                {
                    hash[j*i] = false;
                }
            }
        }
    }

    int countPrimes(int n) {
        Load(n);
        int ans = 0;
        for(int i=2;i<n;++i)
        {
            if(hash[i]) ++ans;
        }
        return ans;
    }
};