/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int  n = preorder.size();
        for(int i=0;i<n;++i)
        {
            idxInPre[preorder[i]] = i;
            idxInPost[postorder[i]] = i;
        }
        return build(preorder,0,n-1,postorder,0,n-1);        
    }

    TreeNode* build(vector<int>& preorder,int p1,int p2,vector<int>& postorder,int p3,int p4)
    {
        if(p1>p2 || p3>p4) return nullptr;
        if(p1==p2){
            return new TreeNode(preorder[p1]);
        }
        if(p3==p4){
            return new TreeNode(postorder[p3]);
        }
        int rootVal = preorder[p1];
        TreeNode* root = new TreeNode(rootVal);
        int left_root = preorder[p1+1];
        int left_root_idx = idxInPost[left_root];
        int left_size = left_root_idx - p3+1;

        root->left = build(preorder,p1+1,p1+left_size,postorder,p3,p3+left_size-1);
        root->right = build(preorder,p1+left_size+1,p2,postorder,left_root_idx+1,p4-1);
        return root;
    }
private:
    unordered_map<int,int> idxInPre;
    unordered_map<int,int> idxInPost;
};
