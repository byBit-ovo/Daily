
class Solution {
    public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            return build(nums,0,nums.size()-1);
     }
        
     TreeNode* build(vector<int>& nums,int start,int end){
        if(start > end){
             return nullptr;
        }
     TreeNode* root = nullptr;
        int rootVal = nums[start];
        int index = start;
        for(int i=start;i<=end;++i){
            if(rootVal<nums[i]){
             rootVal = nums[i];
             index = i;
         }
     }
                                        
     root = new TreeNode(rootVal);
     root->left = build(nums,start,index-1);
     root->right = build(nums,index+1,end);
      return root;
                                                                        
                                                                        
 }
};
