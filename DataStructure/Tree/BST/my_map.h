namespace KV{
template <class K,class V>
struct Bst_Node
{
    struct Bst_Node<K,V>* _left;
    struct Bst_Node<K,V>* _right;
    K _key;
    V _value;
    Bst_Node(const K& key=K(),const V& val=V()) : _key(key),
                                         _value(val),
                                         _left(nullptr),
                                         _right(nullptr) {}
};
template <class K,class V>
class my_map
{
    typedef Bst_Node<K,V> node;

public:
    my_map()=default;
    my_map(const my_map<K,V>& src){
        copy(_root,src._root);
    }
    ~my_map(){
        Destroy(_root);
    }
    node* find(const K& key)
    {
        node* cur = _root;
        while (cur != nullptr)
        {
            if (key < cur->_key)
            {
                cur = cur->_left;
            }
            else if (key > cur->_key)
            {
                cur = cur->_right;
            }
            else
            {
                return cur;
            }
        }
            return nullptr;

    }
        bool empty() const
        {
            return _root == nullptr;
        }
        bool erase(const K &key)
        {
            node *cur = _root, *patOfcur = nullptr;
            while (cur != nullptr)
            {
                if (key < cur->_key)
                {
                    patOfcur = cur;
                    cur = cur->_left;
                }
                else if (key > cur->_key)
                {
                    patOfcur = cur;
                    cur = cur->_right;
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
    bool insert(const K& key,const V& val)
    {
        if (_root == nullptr)
        {
            _root = new node(key,val);
            return true;
        }
        else
        {
            node *cur = _root, *pat = nullptr;
            while (cur != nullptr)
            {
                if (cur->_key == key)
                {
                    return false;
                }
                else if (key > cur->_key)
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
            node *new_node = new node(key,val);
            if (key < pat->_key)
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
    void show(){
        show_address(_root);
    }
private:
    void Destroy(node* root){
        if(root==nullptr){
            return;
        }
        Destroy(root->_left);
        Destroy(root->_right);
        delete root;
    }
    void show_address(node* root){
        if(root==nullptr){
            return ;
        }
        printf("%p\n",root);
        show_address(root->_left);
        show_address(root->_right);
    }
    void copy(node*& root,node* src){
        if(src==nullptr){
            return;
        }
        root=new node(src->_key,src->_value);
        copy(root->_left,src->_left);
        copy(root->_right,src->_right);
    }
    void _In_order(node *root)
    {
        if (root == nullptr)
            return;
        _In_order(root->_left);
        cout <<root->_key<<" "<< root->_value<<endl;
        _In_order(root->_right);
    }
    node *_root = nullptr;
};
}