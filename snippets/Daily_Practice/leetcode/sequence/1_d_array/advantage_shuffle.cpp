class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> ans(nums1.size());
        auto cmp = [](std::pair<int, int>& p1, std::pair<int, int>& p2) {
            return p1.first < p2.first;
        };

        std::priority_queue<std::pair<int, int>,
        std::vector<std::pair<int, int>>, decltype(cmp)> heap(cmp);
        for(int i=0;i<nums2.size();++i){
            heap.push(std::make_pair(nums2[i],i));
        }
        sort(nums1.begin(),nums1.end(),std::greater<int>());
        // sort(nums2.begin(),nums2.end(),std::greater<int>());
        for(int i=0;i<nums1.size();)
        {
            int val = heap.top().first;
            int pos = heap.top().second;
            heap.pop();
            if(nums1[i] > val){
                ans[pos] = nums1[i++];
            }
            else{
                ans[pos] = nums1.back();
                nums1.pop_back();
            }
        }
        return ans;

    }
};
