class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
    string dfs(TreeNode* root)
    {
        if(root==nullptr){
            return "n";
        }
        string left_post = dfs(root->left);
        string right_post = dfs(root->right);
        string me = left_post +right_post+to_string(root->val);
        if(hash[me]==1){
            res.push_back(root);
        }
        ++hash[me];
        return me;
    }
private:
    unordered_map<string,int> hash;
    vector<TreeNode*> res;
};
