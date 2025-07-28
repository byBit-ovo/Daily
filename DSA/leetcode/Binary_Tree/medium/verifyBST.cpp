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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        if(isValidBST(root->left) && isValidBST(root->right))
        {
            int leftMax = findMax(root->left);
            int rightMin = findMin(root->right);
            if(!root->left || root->val > leftMax){
                if(!root->right || root->val < rightMin)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int findMax(TreeNode* root)
    {
        if(root==nullptr){
            return 6;//无论多少
        }
        while(root && root->right){
            root=root->right;
        }
        return root->val;
    }
    int findMin(TreeNode* root)
    {
        if(root==nullptr){
            return 6;//无论多少
        }
        while(root && root->left)
        {
            root = root->left;
        }
        return root->val;
    }
};
