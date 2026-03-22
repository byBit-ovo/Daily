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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        _diameter = max(_diameter,dfs(root));
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return _diameter;
    }
private:
    int _diameter;
    int dfs(TreeNode* root)
    {
        if(root==nullptr) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        return l+r;
    }
    int depth(TreeNode* root)
    {
        if(root==nullptr) return 0;
        int leftdp = depth(root->left);
        int rightdp = depth(root->right);
        return max(leftdp,rightdp)+1;
    }
};

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
    int diameterOfBinaryTree(TreeNode* root) {
        int useless = depth(root);
        return _diameter;
    }
private:
    int _diameter = 0;
    int depth(TreeNode* root)
    {
        if(root==nullptr) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        _diameter = max(_diameter,l+r);
        return max(l,r)+1;
    }
};
