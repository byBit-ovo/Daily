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
    std::vector<TreeNode*> res;
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
    vector<TreeNode*> generate(int start,int end){
        vector<TreeNode*> treeList;
        if(start>end){
            treeList.push_back(nullptr);
            return treeList;
        }
        
        //先枚举BST的根节点
        for(int root=start;root<=end;++root)
        {
            vector<TreeNode*> left = generate(start,root-1);
            vector<TreeNode*> right = generate(root+1,end);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* tree = new TreeNode(root);
                    tree->left = l;
                    tree->right = r;
                    treeList.push_back(tree);
                }
            }
        }
        return treeList;
    }
};