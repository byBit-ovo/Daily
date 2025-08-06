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
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    int res = INT_MIN;
    //返回以当前节点开始的普通路径最大和,顺便计算最值
    int dfs(TreeNode *root)
    {
        if(root==nullptr){
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        int cur = root->val;
        if(l > 0){
            cur += l;
        } 
        if(r > 0){
            cur += r;
        }
        res = max(res, cur);
        return max(0,max(r,l)) + root->val;
    }
};