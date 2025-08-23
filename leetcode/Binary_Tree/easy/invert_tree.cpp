tion for a binary tree node.
 * struct TreeNode {
     *  *     int val;
     *   *     TreeNode *left;
     *    *     TreeNode *right;
     *     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *      *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *       *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     *        * };
*         */
class Solution {
    public:
    TreeNode* invertTree(TreeNode* root) {
         if(!root) return nullptr;
         TreeNode* left = root->left;
         root->left = invertTree(root->right);
         root->right = invertTree(left);
         return root;
         }
};

class Solution {
    public:
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
         return root;
 }
void traverse(TreeNode* root)
{
    if(root==nullptr) return;
    traverse(root->left);
    traverse(root->right);
    TreeNode* left = root->left;
    root->left = root->right;
    root->right = left;
}
};
