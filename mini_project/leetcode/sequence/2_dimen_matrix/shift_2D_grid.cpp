//This solution makes me look very fool.....wuwuwuwu....
class Solution {
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
