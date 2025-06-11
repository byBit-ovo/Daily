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
            return "n,";
        }
        string me = to_string(root->val) + _deli +
        serialize(root->left)+ _deli+ serialize(root->right);
        return me;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string& data) {
        if(data.empty()){
            return nullptr;
        }else if(data[0]=='n'){
            data.erase(data.begin(),data.begin()+1);
            return nullptr;
        }
        int pos = data.find(_deli);
        string valStr = data.substr(0,pos);
        int val =stoi(valStr);
        TreeNode* root = new TreeNode(val);
        data.erase(data.begin(),data.begin()+pos);
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
    string _deli = ",";
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
