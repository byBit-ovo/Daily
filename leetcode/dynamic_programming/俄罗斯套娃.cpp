#include <vector>
#include <algorithm>
using namespace std;
//
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        auto snapshot(envelopes);

        auto cmp = [](const vector<int> &a, const vector<int> &b) -> bool
        {
            if (a[0] < b[0])
                return true;
            if (a[0] == b[0])
                return a[1] > b[1];
            return false;
        };
        sort(snapshot.begin(), snapshot.end(), cmp);
        vector<int> nums;
        for (int i = 0; i < snapshot.size(); ++i)
        {
            nums.emplace_back(snapshot[i][1]);
        }
        return lengthOfLIS(nums);
    }

private:
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