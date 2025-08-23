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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* subRoot = Find(root,key);
        if(subRoot->left==nullptr){

        }
    }

    TreeNode* FindAimParent(TreeNode* root,int key){
        TreeNode* parent = nullptr;
        while(root!=nullptr){
            if(root->val==key){
                return parent;
            }else if(root->val>key){
                parent=root;
                root=root->left;
            }else{
                parent=root;
                root=root->right;
            }
        }
        return nullptr;
    }
    TreeNode* Find_leftMostParent(TreeNode* root){
        if(!root){
            return root;
        }
        TreeNode* rootParent = nullptr;
        while(root->left){
            rootParent=root;
            root=root->left;
        }
        return rootParent;
    }
    TreeNode* Find_rightMostParent(TreeNode* root){
        if(!root){
            return root;
        }
        TreeNode* rootParent = nullptr;
        while(root->right){
            rootParent=root;
            root=root->right;
        }
        return rootParent;
    }

};
