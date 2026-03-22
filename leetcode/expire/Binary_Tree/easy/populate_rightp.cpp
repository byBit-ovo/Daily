class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            Node* prev = nullptr;
            for(int i=sz;i>0;--i)
            {
                Node* cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                if(prev){
                    prev->next = cur;
                }
                prev = cur;
            }
            prev->next = nullptr;
        }
        return root;
    }
};

class Solution2 {
public:
    Node* connect(Node* root) {
        traverse(root);
        return root;
    }

    void traverse(Node* root)
    {
        if(root==nullptr || root->left==nullptr) return;
        root->left->next = root->right;
        if(root->next){
            root->right->next = root->next->left;
        }
        traverse(root->left);
        traverse(root->right);
    }
};
