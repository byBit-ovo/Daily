#include <iostream>
using namespace std;
template <class Type>
struct bst_Node
{
    struct bst_Node<Type>* _left;
    struct bst_Node<Type>* _right;
    Type _val;
    bst_Node(const Type &val = Type()) : _val(val),
                                         _left(nullptr),
                                         _right(nullptr) {}
};
template <class Type>
class BST
{
    typedef bst_Node<Type> node;

public:
    node* find(const Type& val){
        node* cur = _root;
        while(cur!=nullptr){
            if(val < cur->_val){
                cur=cur->_left;
            }
            else if(val > cur->_val){
                cur=cur->_right;
            }
            else{
                return cur;
            }
            return nullptr;
    }
    }
    bool empty()const{
        return _root==nullptr;
    }
    bool erase(const Type& val){
        node* cur = _root,*patOfcur=nullptr;
        while(cur!=nullptr){
            if(val < cur->_val){
                patOfcur=cur;
                cur=cur->_left;
            }
            else if(val > cur->_val){
                patOfcur=cur;
                cur=cur->_right;
            }
            else{
                //aim_node found
                if(cur->_left==nullptr){
                    if(patOfcur==nullptr){
                        _root = cur->_right;
                    }
                    else{
                        if(cur==patOfcur->_left){
                            patOfcur->_left = cur->_right;
                        }
                        else{
                            patOfcur->_right = cur->_right;
                        }
                    }
                    delete cur;
                    return true;
                }
                else if(cur->_right==nullptr){
                    if(patOfcur==nullptr){
                        _root=cur->_left;
                    }
                    else{
                        if(cur==patOfcur->_left){
                            patOfcur->_left=cur->_left;
                        }
                        else{
                            patOfcur->_right=cur->_left;
                        }
                    }
                    delete cur;
                    return true;
                }
                else{
                    //aim_node has two kids
                    node* maxOf_left = cur->_left,*patOf_leftmax = cur;
                    while(maxOf_left->_right!=nullptr){
                        patOf_leftmax = maxOf_left;
                        maxOf_left=maxOf_left->_right;
                    }
                    cur->_val = maxOf_left->_val;
                    //maxOf_left only has left_child
                    if(patOf_leftmax->_right==maxOf_left)
                    patOf_leftmax->_right=maxOf_left->_left;
                    else
                    patOf_leftmax->_left=maxOf_left->_left;
                    delete maxOf_left;
                    return true;
                }
            }
        }
        //aim_node unexist
        return false;
    }
    bool insert(const Type &val)
    {
        if (_root == nullptr)
        {
            _root = new node(val);
            return true;
        }
        else
        {
            node *cur = _root, *pat = nullptr;
            while (cur != nullptr)
            {
                if (cur->_val == val)
                {
                    return false;
                }
                else if (val > cur->_val)
                {
                    pat = cur;
                    cur = cur->_right;
                }
                else
                {
                    pat = cur;
                    cur = cur->_left;
                }
            }
            node *new_node = new node(val);
            if (val < pat->_val)
            {
                pat->_left = new_node;
            }
            else
            {
                pat->_right = new_node;
            }
        }
        return true;
    }

    void In_order()
    {
        _In_order(_root);
    }

private:
    void _In_order(node *root)
    {
        if (root == nullptr)
            return;
        _In_order(root->_left);
        cout << root->_val<<" ";
        _In_order(root->_right);
    }
    node *_root = nullptr;
};