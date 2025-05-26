//
#include <vector>
// so clever solution
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int l = 0,r = len - 1;
        
        while(l < r)
        {
            int t = l,b = r;
            for(int i =0; i<r-l ;++i)
            {
                int leftTop = matrix[t][l+i];
                matrix[t][l+i] = matrix[b-i][l];
                matrix[b-i][l] = matrix[b][r-i];
                matrix[b][r-i] = matrix[t+i][r];
                matrix[t+i][r] = leftTop;
            }
            ++l;
            --r;
        }

    }
};