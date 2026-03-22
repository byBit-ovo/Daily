
class Solution {
public:
    vector<bool> colUsed;
    vector<bool> diagonalUsed;
    vector<bool> disdiagonalUsed;
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> solveNQueens(int n) {
        colUsed.resize(n,false);
        diagonalUsed.resize(2*n-1,false);
        disdiagonalUsed.resize(2*n-1,false);
        path.resize(n,string(n,'.'));
        backTrack(n,0);
        return res;
    }

    void backTrack(int n,int row)
    {
        if(n==row){
            res.emplace_back(path);
            return;
        }
        
        for(int j=0;j<n;++j)
        {
            if(path[row][j]=='.' && !colUsed[j] && !diagonalUsed[row-j+n-1] && !disdiagonalUsed[row+j]){
                path[row][j]='Q';
                colUsed[j]=diagonalUsed[row-j+n-1]=disdiagonalUsed[row+j]=true;
                backTrack(n,row+1);
                path[row][j]='.';
                colUsed[j]=diagonalUsed[row-j+n-1]=disdiagonalUsed[row+j]=false;
            }
        }
        
    }




};