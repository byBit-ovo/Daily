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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();++i){
            valToPos[inorder[i]] = i;
        }    
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode* build(vector<int>& inorder,int iStart,int iEnd,
                    vector<int>& postorder, int pStart,int pEnd)
    {
        if(iStart>iEnd ||pStart>pEnd){
            return nullptr;
        }
        int rootVal = postorder[pEnd];
        int index = valToPos[rootVal]; //find pos in inorder
        int left_size = index - iStart;
        int right_size = iEnd - index;
        TreeNode* root = new TreeNode(rootVal);
        root->left =                           build(inorder,iStart,index-1,postorder,pStart,pStart+left_size-1);
        root->right =
        build(inorder,index+1,iEnd,postorder,pStart+left_size,pEnd-1);
        return root;
    }
private:
    unordered_map<int,int> valToPos;
};