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
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        TreeNode* rightc= root->right;
        TreeNode* leftc= root->left;
        flatten(leftc);
        root->right = leftc;
        root->left = nullptr;
        TreeNode* tail = root;
        while(tail->right!=nullptr){
            tail=tail->right;
        }
        flatten(rightc);
        tail->right = rightc;

    }
};
