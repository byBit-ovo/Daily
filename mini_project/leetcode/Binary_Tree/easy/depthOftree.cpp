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
    int maxDepth(TreeNode* root) {
        traverse(root);
        return maxdepth;
    }
private:
    int maxdepth = 0;
    int curdepth = 0;
    void traverse(TreeNode* root)
    {
        if(root==nullptr) return;
        ++curdepth;
        maxdepth = max(maxdepth,curdepth);
        traverse(root->left);
        traverse(root->right);
        --curdepth;
    }
};
