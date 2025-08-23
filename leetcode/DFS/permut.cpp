class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        _used.resize(len);
        dfs(nums);
        return _res;
    }

private:
    void dfs(const vector<int>& nums)
    {
        if(_path.size()==nums.size()){
            _res.push_back(_path);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(!_used[i]){
                _path.push_back(nums[i]);
                _used[i]=1;
                dfs(nums);
                _path.pop_back();
                _used[i]=0;
            }
        }
    }
    vector<vector<int>> _res;
    vector<int> _path;
    vector<int> _used;
};