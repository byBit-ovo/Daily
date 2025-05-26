class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        std::unordered_map<int,std::multiset<int>> hash;
        int r = mat.size(),l=mat[0].size();
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<l;++j)
            {
                hash[i-j].insert(mat[i][j]);
            }
        }
        auto ans = mat;
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<l;++j)
            {
                int val = *(hash[i-j].begin());
                ans[i][j] = val;
                hash[i-j].erase(hash[i-j].begin());
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        std::unordered_map<int,std::vector<int>> hash;
        int r = mat.size(),l=mat[0].size();
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<l;++j)
            {
                hash[i-j].emplace_back(mat[i][j]);
            }
        }
        for(auto& l:hash)
        {
            sort(l.second.begin(),l.second.end(),std::greater<int>());
        }
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<l;++j)
            {
                mat[i][j] = hash[i-j].back();
                hash[i-j].pop_back();
            }
        }
        return mat;
    }
};