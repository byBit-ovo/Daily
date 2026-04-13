
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();++i){
            IdxInIn[inorder[i]]=i;
        }
        return divide(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1 );
    }

    TreeNode* divide(vector<int>& preorder,int p1,int p2,
                     vector<int>& inorder,int i1,int i2){
        if(p1>p2 || i1>i2){
            return nullptr;
        }
        int root_val = preorder[p1];
        int rooti = IdxInIn[root_val];
        TreeNode* root = new TreeNode(root_val);
        int left_size = rooti - i1;
        root->left = divide(preorder,p1+1,p1+left_size,inorder,i1,rooti-1);
        root->right = divide(preorder,p1+1+left_size,p2,inorder,rooti+1,i2);
        return root;
    }
private:
    unordered_map<int,int> IdxInIn;
};
