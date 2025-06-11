/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "N";
        }
        string res = to_string(root->val);
        res+=_deli;
        res += serialize(root->left);
        res+=_deli;
        res+=serialize(root->right);
        return res;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string& data) {
        if(data.empty()){
            return nullptr;
        }
        int pos = data.find(_deli);
        if(pos==string::npos){
            if(data=="N"){
                return nullptr;
            }
        }
        string valStr = data.substr(0,pos);
        if(valStr=="N"){
            data.erase(data.begin());
            if(!data.empty()){
                data.erase(data.begin());
            }
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(valStr));
        data.erase(data.begin(),data.begin()+pos+1);
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;

    }
    string _deli = ",";
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
