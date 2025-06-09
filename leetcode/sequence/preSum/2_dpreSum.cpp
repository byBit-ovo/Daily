class NumMatrix {
public:
    using Long = long long;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        preSum.resize(m+1,std::vector<Long>(n+1));
        for(int i=1;i<=m;++i){
            int lineSum=0;
            for(int j=1;j<=n;++j){
                lineSum += matrix[i-1][j-1];
                preSum[i][j] = preSum[i-1][j] + lineSum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] - preSum[row2+1][col1]-
        preSum[row1][col2+1]+preSum[row1][col1];
    }
private:   
    std::vector<std::vector<Long>> preSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
