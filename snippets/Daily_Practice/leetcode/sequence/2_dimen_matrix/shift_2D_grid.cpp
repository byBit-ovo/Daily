//This solution makes me look very fool.....wuwuwuwu....
#include <vector>
using namespace std;
class Solution
{
public:
    void shift(vector<vector<int>>& grid)
    {
        int m = grid.size(),n=grid[0].size();

        for(int i=0;i<m;++i){
            for(int j=0;j<n-1;++j){
                tmp[i][j+1]=grid[i][j];
            }
        }
        tmp[0][0] = grid[m-1][n-1];
        for(int i=0;i<m-1;++i){
            tmp[i+1][0]=grid[i][n-1];
        }
        grid = tmp;

    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n=grid[0].size();
        tmp.resize(m);
        for(auto& t:tmp) t.resize(n);
        for(int i=0;i<k;++i){
            shift(grid);
        }
        return grid;
    }
private:
    std::vector<vector<int>> tmp;
};
//seems better... I'm back! 
class Solution2 {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        m=grid.size(),n=grid[0].size();
        k%=m*n;
        for(int i=0;i<k;++i){
            shift(grid);
        }
        return grid;

    }
private:
    int m,n;
    void shift(vector<vector<int>>& grid)
    {
        auto tmp = grid;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                int new_row = (i + (j+1)/n)%m;
                int new_col = (j+1)%n;
                tmp[new_row][new_col] = grid[i][j];
            }
        }
        grid=tmp;
    }
};
//The elegant power of mode,it's magical.
class Solution3 {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        k%=m*n;
        auto tmp = grid;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                int new_row = (i + (j+k)/n)%m;
                int new_col = (j+k)%n;
                tmp[new_row][new_col] = grid[i][j];
            }
        }
        grid=tmp;
        return grid;

    }
};
//optimize the space complexity to O(1)
class Solution4 {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        m = grid.size(),n=grid[0].size();
        k%=m*n;
        reverse(grid,0,m*n-1);
        reverse(grid,0,k-1);
        reverse(grid,k,m*n-1);
        return grid;
    }
private:
    int m,n;
    pair<int,int> GetPosin2(int pos)
    {
        return {pos/n,pos%n};
    }
    void reverse(vector<vector<int>>& grid,int s,int e)
    {
        for(int i=s,j=e;i<=j;++i,--j)
        {
            auto p1 = GetPosin2(i),p2 =GetPosin2(j);
            int x1=p1.first,y1=p1.second,x2=p2.first,y2=p2.second;
            swap(grid[x1][y1],grid[x2][y2]);
        }
    }

};
