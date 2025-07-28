class Solution {
public:
    struct cmp{
        bool operator()(vector<int>& v1,vector<int>& v2){
            return v1[0] < v2[0];
        }        
    };
    struct cmp _cmp;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),_cmp);
        vector<vector<int>> res;
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1;i < intervals.size(); ++i)
        {
            if(intervals[i][0] > end)
            {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else
            {
                end = max(end, intervals[i][1]);
            }
        }
        res.push_back({start, end});

        return res;
    }
};
