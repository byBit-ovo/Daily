
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        vector<TreeNode*> res;
        for(auto& v:_hash){
            if(v.second.size()>1){
                res.emplace_back(v.second[0]);
            }
        }
        return res;
    }

    string traverse(TreeNode* root)
    {
        if(root==nullptr){
            return "n";
        }
        string me = to_string(root->val) +_deli+
        traverse(root->left)+_deli +traverse(root->right);

        _hash[me].emplace_back(root);
        return me;
    }

private:
    unordered_map<string,vector<TreeNode*>> _hash;
    string _deli = ",";
};
