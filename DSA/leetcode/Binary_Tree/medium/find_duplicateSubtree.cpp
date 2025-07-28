
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return _res;
    }

    string traverse(TreeNode* root)
    {
        if(root==nullptr){
            return "n";
        }
        string me = to_string(root->val) +_deli+
        traverse(root->left)+_deli +traverse(root->right);
        if(_hash[me].size()==1){
            _res.emplace_back(root);
        }
        _hash[me].emplace_back(root);
        return me;
    }

private:
    vector<TreeNode*> _res;
    unordered_map<string,vector<TreeNode*>> _hash;
    string _deli = ",";
};
