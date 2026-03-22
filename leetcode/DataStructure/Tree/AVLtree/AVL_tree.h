#include <iostream>
#include <assert.h>
using namespace std;
template <class K,class V>
struct AVL_Node
{
    struct AVL_Node<K,V>* _left;
    struct AVL_Node<K,V>* _right;
    struct AVL_Node<K,V>* _parent;
    pair<K,V> _kv;
    int _bf = 0;
    AVL_Node(const pair<K,V>& kv) : _kv(kv),
                                    _left(nullptr),
                                    _right(nullptr),
                                    _parent(nullptr){}
};
template <class K,class V>
class AVL
{
    typedef AVL_Node<K,V> node;
public:
    ~AVL(){
        Destroy(_root);
        _root = nullptr;
    }
    AVL():_root(nullptr){}
    AVL(const AVL& COPY){
        _root=copy(COPY._root);
    }
    int tree_height(){
        return height(_root);
    }
    bool _is_Balance(){
        return _IsBalanceTree(_root);
    }
    node* find(const pair<K,V>& kv){
        node* cur = _root;
        while(cur!=nullptr){
            if(kv.first < cur->_kv.first){
                cur=cur->_left;
            }
            else if(kv.first > cur->_kv.first){
                cur=cur->_right;
            }
            else{
                return cur;
            }
        }
        return nullptr;
    }
    bool empty()const{
        return _root==nullptr;
    }

    bool insert(const pair<K,V>& kv)
    {
        if(_root==nullptr){
            _root = new node(kv);
            return true;
        }
        node* cur = _root,*parent=nullptr;
        while(cur){
            if(kv.first < cur->_kv.first){
                parent = cur;
                cur=cur->_left;
            }
            else if(kv.first > cur->_kv.first){
                parent = cur;
                cur=cur->_right;
            }
            else{
                return false;
            }
        }
        // 
        node* child = new node(kv);
        if(kv.first < parent->_kv.first){
            parent->_left = child;
        }
        else{
            parent->_right=child;
        }
        child->_parent = parent;
        while (parent)
        {
            if(parent->_left==child){
                --parent->_bf;
            }
            else{
                ++parent->_bf;
            }
            if (parent->_bf == 0)
            {
                break;
            }
            else if (parent->_bf == 1 || parent->_bf == -1)
            {
                child = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2)
            {
                //rorate
                if(parent->_bf==2 && child->_bf==1){
                    rorate_left(parent);
                }
                else if(parent->_bf==-2&& child->_bf==-1){
                    rorate_right(parent);
                }
                else if(parent->_bf==2&& child->_bf==-1){
                    rorate_rl(parent);
                }
                else if(parent->_bf==-2&& child->_bf==1){
                    rorate_lr(parent);
                }
                break;
            }
            else{
                cout<<"balance factor ouf of range"<<endl;
                assert(false);
            }
        }
        return true;
    }

    void In_order()
    {
        _In_order(_root);
    }
private:
    void rorate_left(node* parent){
        node* p_r = parent->_right;
        node* p_rl = parent->_right->_left;
        node* pparent = parent->_parent;
        parent->_right =  p_rl;
        p_r->_left = parent;
        if(p_rl!=nullptr){
            p_rl->_parent = parent;
        }
        parent->_parent = p_r;
        if(pparent==nullptr){
            _root = p_r;
            p_r->_parent = nullptr;
        }
        else if(pparent->_left==parent){
            pparent->_left = p_r;
        }
        else{
            pparent->_right = p_r;
        }
        p_r->_parent = pparent;
        p_r->_bf = parent->_bf = 0;
    }
    void rorate_right(node* parent){
        node* p_l = parent->_left;
        node* p_lr = p_l->_right;
        node* pparent = parent->_parent;

        p_l->_right = parent;
        parent->_parent = p_l;
        parent->_left = p_lr;
        if(p_lr!=nullptr){
            p_lr->_parent = parent;
        }
        if(pparent==nullptr){
            _root=p_l;
        }
        else if(pparent->_left == parent){
            pparent->_left = p_l;
        }
        else{
            pparent->_right = p_l;
        }
        parent->_bf = p_l->_bf = 0;
        p_l->_parent = pparent;
    }
    void rorate_lr(node* parent){
        node* p_l = parent->_left,*p_lr = p_l->_right;
        int p_lr_bf = p_lr->_bf;
        rorate_left(p_l);
        rorate_right(parent);
        if(p_lr->_bf==1){
            p_l->_bf=-1;
            parent->_bf=0;
            p_lr->_bf=0;
        }
        else if(p_lr->_bf==0){
            p_l->_bf=0;
            parent->_bf=0;
            p_lr->_bf=0;
        }
        else if(p_lr->_bf==-1){
            parent->_bf=1;
            p_l->_bf=0;
            p_lr->_bf=0;
        }
        else{
            assert(false);
        }
}
    void rorate_rl(node* parent){
        node* p_r = parent->_right,*p_rl = p_r->_left;
        int p_rl_bf = p_rl->_bf;
        rorate_right(parent->_right);
        rorate_left(parent);
        if(p_rl_bf==0){
            parent->_bf = p_r->_bf = p_rl->_bf=0;
        }
        else if(p_rl_bf==1){
            parent->_bf=-1;
            p_r->_bf=0;
            p_rl->_bf=0;
        }
        else if(p_rl_bf==-1){
            parent->_bf=0;
            p_r->_bf=1;
            p_rl->_bf=0;
        }
        else{
            assert(false);
        }
    }
    bool _IsBalanceTree(node* pRoot)
    {
        // 空树也是AVL树
        if (nullptr == pRoot)
            return true;
        // 计算pRoot节点的平衡因子：即pRoot左右子树的高度差
        int leftHeight = height(pRoot->_left);
        int rightHeight = height(pRoot->_right);
        int diff = rightHeight - leftHeight;
        // 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
        // pRoot平衡因子的绝对值超过1，则一定不是AVL树
        if (diff != pRoot->_bf || (diff > 1 || diff < -1))
            return false;
        // pRoot的左和右如果都是AVL树，则该树一定是AVL树
        return _IsBalanceTree(pRoot->_left) && _IsBalanceTree(pRoot->_right);
    }
    void Destroy(node* root){
        if(root==nullptr){
            return;
        }
        Destroy(root->_left);
        Destroy(root->_right);
        delete root;
    }
    int height(node *root)
    {
        if (root == nullptr)
            return 0;

        int l = height(root->_left);
        int r = height(root->_right);
        return l > r ? l + 1 : r + 1;
    }
    void _In_order(node *root)
    {
        if (root == nullptr)
            return;
        _In_order(root->_left);
        cout << root->_kv.first<<" "<<root->_kv.second<<endl;
        _In_order(root->_right);
    }
    node *copy(node *root)
    {
        if (root == nullptr)
            return root;
        node *newRoot = new node(root->_kv);
        node *left_child = copy(root->_left);
        node *right_child = copy(root->_right);
        newRoot->_left = left_child;
        newRoot->_right = right_child;
        if (left_child != nullptr)
            left_child->_parent = newRoot;
        if (right_child != nullptr)
            right_child->_parent = newRoot;
        newRoot->_bf = root->_bf;
        return newRoot;
    }
    node *_root = nullptr;
};