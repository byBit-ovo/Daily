class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        ans.resize(helper.size());
        int j = 0;
        for(auto& e: helper){
            sort(e.second.begin(),e.second.end(),[](const superNode& a,const superNode& b)->bool{
                if(a._x < b._x){
                    return true; 
                }
                else if(a._x==b._x){
                    return a._root < b._root;
                }
                return false;
            });
            for(int i=0;i<e.second.size();++i){
                ans[j].emplace_back(e.second[i]._root);
            }
            ++j;
        }
        return ans;
    }
private:
    struct superNode{
        int _root;
        int _x,_y;
        superNode(int root,int x,int y):
            _root(root),_x(x),_y(y){}
    };
    vector<vector<int>> ans;
    map<int,vector<superNode>> helper;
    void dfs(TreeNode* root,int x,int y){
        if(root==nullptr) return;
        helper[y].emplace_back(superNode(root->val,x,y));
        dfs(root->left,x+1,y-1);
        dfs(root->right,x+1,y+1);
    }
};
