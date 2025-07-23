class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> maxLeft(len);
        vector<int> maxRight(len);
        maxLeft[0] = maxRight[len - 1] = -1;
        for(int i=1;i<len;++i){
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }
        for(int i = len - 2;i>=0;--i){
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }
        int res = 0;
        for(int i=0;i<len;++i){
            res += max(0, min(maxLeft[i],maxRight[i]) - height[i]);
        }
        return res;
    }
};
