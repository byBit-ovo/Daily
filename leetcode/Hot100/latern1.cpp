
class Solution {
public:
    vector<int> decorateRecord(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root != nullptr){
            q.push(root);
        }        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            res.push_back(p->val);
            if(p->left != nullptr){
                q.push(p->left);
            }
            if(p->right != nullptr){
                q.push(p->right);
            }
        }
        return res;
    }
};
