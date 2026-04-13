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
    int kthSmallest(TreeNode* root, int k) {
        _k=k;
        dfs(root);
        return _res;
    }
    void dfs(TreeNode* root)
    {
        if(root==nullptr || _res!=-1){
            return;
        }
        dfs(root->left);
        if(_k==1){
            _res = root->val;
        }
        _k--;
        dfs(root->right);
    }
private:
    int _res=-1;
    int _k;
};
