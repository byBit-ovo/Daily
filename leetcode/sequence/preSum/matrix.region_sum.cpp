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

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        NumMatrix tool(mat);
        int m = mat.size(),n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int x1 = max(i-k,0),y1=max(j-k,0);
                int x2 = min(i+k,m-1),y2=min(j+k,n-1);
                ans[i][j] = tool.sumRegion(x1,y1,x2,y2);
            }
        }
        return ans;
    }
};
