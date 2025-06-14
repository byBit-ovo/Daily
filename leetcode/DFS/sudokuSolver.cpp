class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    _rowUsed[i][board[i][j]-'0']=true;
                    _colUsed[j][board[i][j]-'0']=true;
                    _gridUsed[i/3][j/3][board[i][j]-'0']=true;
                }
            }
        }
        backTrack(board);
    }

private:
    bool backTrack(vector<vector<char>>& board){

        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;++k){
                        if(!_colUsed[j][k] &&!_rowUsed[i][k] && !_gridUsed[i/3][j/3][k]){
                            board[i][j]=k+'0';
                            _colUsed[j][k]=_rowUsed[i][k]=_gridUsed[i/3][j/3][k]=true;
                            if(backTrack(board)){
                                return true;
                            }
                            _colUsed[j][k]=_rowUsed[i][k]=_gridUsed[i/3][j/3][k]=false;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    vector<vector<bool>> _rowUsed = vector<vector<bool>>(9, vector<bool>(10, false));
    vector<vector<bool>> _colUsed = vector<vector<bool>>(9, vector<bool>(10, false));
    vector<vector<vector<bool>>> _gridUsed = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));
};