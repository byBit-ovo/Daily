#pragma once
#include <iostream>
using namespace std;
enum Color{
    BLACK,
    RED
};
//define of node
template <class V>
struct RB_node{
    RB_node<V>* _parent;
    RB_node<V>* _left;
    RB_node<V>* _right;
    V _value;
    Color _col;
    RB_node(const V& value)
    :_value(value), _parent(nullptr),
    _left(nullptr),_right(nullptr),
    _col(RED){}
};
//define of iterator
template<class T,class Ref,class Pointer>
struct rbIterator{
    typedef RB_node<T> node;
    typedef rbIterator Self;
    rbIterator(node* pointer):_pointer(pointer){}
    Ref operator*(){return _pointer->_value;}
    Pointer operator->(){return &_pointer->_value;}
    bool operator!=(const Self& iter){
        return _pointer!=iter._pointer;
    }
    bool operator==(const Self& iter){
        return _pointer==iter._pointer;
    }
    Self& operator++(){
        if(_pointer->_right!=nullptr){
            _pointer=_pointer->_right;
            while(_pointer!=nullptr && _pointer->_left!=nullptr){
                _pointer=_pointer->_left;
            }
        }
        else{
            node* parent = _pointer->_parent;
            while(parent!=nullptr && _pointer == parent->_right){
                _pointer = parent;
                parent = _pointer->_parent;
            }
            _pointer=parent;
            
        }
        return *this;
    }
    node* _pointer;
};



template <class T>
class my_greater{
    public:
    bool operator()(const T& p1,const T& p2){
        return p1>p2;
    }
};
template <class T>
class my_less{
    public:
    bool operator()(const T& p1,const T& p2){
        return p1<p2;
    }
};
//rbtree
template<class K,class V,class keyOfvalue,class Compare = my_less<K>>
class RB_tree{
    typedef RB_node<V> node;
public:
    typedef rbIterator<V,V&,V*> iterator;
    typedef rbIterator<V,const V&,const V*> const_iterator;
    iterator Begin(){
        node* leftMost = _root;
        while(leftMost!=nullptr && leftMost->_left!=nullptr){
            leftMost = leftMost->_left;
        }
        return iterator(leftMost);
    }
    iterator End(){
        return iterator(nullptr);
    }
    const_iterator Begin()const
    {
        node *leftMost = _root;
        while (leftMost != nullptr && leftMost->_left != nullptr)
        {
            leftMost = leftMost->_left;
        }
        return const_iterator(leftMost);
    }
    const_iterator End()const
    {
        return const_iterator(nullptr);
    }
    int tree_height(){
        return height(_root);
    }

    RB_tree()=default;
    ~RB_tree(){
        Destroy(_root);
    }
    RB_tree(const RB_tree& COPY){
        _root = copy(COPY._root);
    }
    iterator Find(const K& key)
    {
        node* cur = _root;
        while (cur != nullptr)
        {
            if (key < cur->_value)
                cur = cur->_left;
            else if (key > cur->_value)
                cur = cur->_right;
            else
                return iterator(cur);
        }
        return End();
    }
    pair<iterator,bool> Insert(const V& value){
        if(_root==nullptr){
            _root = new node(value);
            _root->_col = BLACK;
            return make_pair(iterator(_root),true);
        }
        else{
            node* cur = _root,*parent = nullptr;
            keyOfvalue kofv;
            Compare cmp;
            while(cur!=nullptr){
                if(cmp(kofv(value),kofv(cur->_value))){
                    parent = cur;
                    cur = cur->_left;
                }
                else if(cmp(kofv(cur->_value),kofv(value))){
                    parent=cur;
                    cur = cur->_right;
                }
                else{
                    return make_pair(iterator(cur),false);
                }
            }
            cur = new node(value);
            node* new_node = cur;
            if(cmp(kofv(value),kofv(parent->_value))){
                parent->_left = cur;
            }
            else{
                parent->_right = cur;
            }
            cur->_parent = parent;
            while(parent!=nullptr && parent->_col==RED){
                node* grandfather = parent->_parent;//parent is red so grandfather is black
                if(parent==grandfather->_left){
                    node* uncle = grandfather->_right;
                    if(uncle!=nullptr && uncle->_col==RED){
                        parent->_col = uncle->_col=BLACK;
                        grandfather->_col = RED;
                        cur=grandfather;
                        parent = cur->_parent;
                        //deal it up
                    }
                    else{
                        //uncle is nullptr or BLACK
                        if(cur==parent->_left){
                            rorate_right(grandfather);
                            parent->_col = BLACK;
                            grandfather->_col = RED;
                        }
                        else{
                            rorate_left(parent);
                            rorate_right(grandfather);
                            cur->_col = BLACK;
                            grandfather->_col = RED;
                        }
                        break;
                    }
                }
                else{
                    //parent==grandfather->_right
                    node* uncle = grandfather->_left;
                    if(uncle!=nullptr && uncle->_col==RED){
                        parent->_col = uncle->_col = BLACK;
                        grandfather->_col = RED;
                        cur = grandfather;
                        parent = cur->_parent;
                        //deal it up
                    }
                    else{
                        //uncle is nullptr or BLACK
                        if(cur==parent->_right){
                            rorate_left(grandfather);
                            parent->_col=BLACK;
                            grandfather->_col=RED;
                        }
                        else{
                            rorate_right(parent);
                            rorate_left(grandfather);
                            cur->_col=BLACK;
                            grandfather->_col=RED;
                        }
                        break;
                    }

                }

            }
            _root->_col=BLACK;
            return make_pair(iterator(new_node),true);
        }
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
        
        p_l->_parent = pparent;
    }
    node* _root=nullptr;
    node* copy(node* root){
        if(root==nullptr)
        return root;
        node* newRoot = new node(root->_value);
        newRoot->_col=root->_col;
        node* left_child = copy(root->_left);
        node* right_child = copy(root->_right);
        if (left_child != nullptr)
            left_child->_parent = newRoot;
        if (right_child != nullptr)
            right_child->_parent = newRoot;

        newRoot->_left = left_child;
        newRoot->_right = right_child;
        return newRoot;
    }
    void Destroy(node *root)
    {
        if (root == nullptr)
        {
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
};