//字符串替换
#include <string>
#include <vector> 

using namespace std;

class StringFormat
{
public:
    string formatString(string A, int n, vector<char> arg, int m)
    {
        // write code here
        string ans;
        int j = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (A[i] == '%')
            {
                ans += arg[j++];
                ++i;
            }
            else
            {
                ans += A[i];
            }
        }

        if (j < m)
        {
            ans.append(arg.begin() + j, arg.end());
        }
        return ans;
    }
};