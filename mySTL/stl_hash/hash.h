#ifndef __hash__
#define __hash__
#include <vector>
#include <iostream>
using namespace std;
template<class V>
struct hashNode{
    V _value;
    hashNode* _next;
    hashNode(const V& value,
        hashNode* next = nullptr):
        _value(value),_next(next){}
};

template<class K,class V,class keyOfv,class hash>
class hashTable;

template<class K,class V,class Ref,class Ptr,class keyOfv,class hash>
class hash_iter{
    public:
    typedef hashNode<V> node;
    typedef hash_iter<K,V,Ref,Ptr,keyOfv,hash> Self;
    typedef hashTable<K,V,keyOfv,hash> Master;
    hash_iter(node*& ps,Master*& pm):
             _pointer(ps)
            ,_ptable(pm){}
    bool operator!=(const Self& iter){
        return _pointer!=iter._pointer;
    }
    bool operator==(const Self& iter){
        return _pointer==iter._pointer;
    }
    Self& operator++(){
        node* cur = _pointer;
        if(cur->_next!=nullptr){
            _pointer=cur->_next;       
        }
        else{
            hash hs;
            keyOfv kov;
            int hashi = hs(kov(_pointer->_value))%(_ptable->_table.size());
            ++hashi;
            while(hashi < _ptable->_table.size()){
                if(_ptable->_table[hashi] !=nullptr){
                    break;
                }
                ++hashi;
            }
            if(hashi <_ptable->_table.size()){
                _pointer = _ptable->_table[hashi];
            }
            else{
                _pointer = nullptr;
            }
        }
        return *this;
    }
    Ref operator*(){
        return _pointer->_value;
    }
    Ptr operator->(){
        return &_pointer->_value;
    }
    private:
    node* _pointer;
    Master* _ptable;

};
template <class K>
struct hashFunc{
    size_t operator()(const K& key){
        return size_t(key);
    }
};
template<>
struct hashFunc<string>{
    size_t operator()(const string& s){
        size_t ret = 0;
        for(auto e:s){
            ret = ret*131+e;
        }
        return ret;
    }
};

template<class K,class V,class keyOfv,class hash>
class hashTable{
    public:
    typedef hashNode<V> node;
    hashTable(){
        _table.resize(10,nullptr);
    }
    ~hashTable(){
        for(auto& e:_table){
            node* cur = e;
            while(cur!=nullptr){
                node* next = cur->_next;
                delete cur;
                cur = next;
            }
            e=nullptr;
        }
    }
    node* Find(const K& key){
        hash hs;
        keyOfv kov;
        size_t hashi=hs(key)%_table.size();
        node* cur = _table[hashi];
        while(cur!=nullptr){
            if(kov(cur->_value)==key){
                break;
            }
            cur = cur->_next;
        }
        return cur;
    }
    bool erase(const K& key){
        hash hs;
        keyOfv kov;
        int hashi = hs(key)%_table.size();
        node* prev =nullptr;
        node* cur = _table[hashi];
        while(cur!=nullptr){
            if(kov(cur->_value)==key){
                if (prev == nullptr)
                    _table[hashi] = cur->_next;
                else
                    prev->_next = cur->_next;

                delete cur;
                --_count;
                return true;
            }
            prev = cur;
            cur = cur->_next;
        }
        return false;
    }
    bool Insert(const V& value){
        keyOfv kov;
        if(Find(kov(value))!=nullptr){
            return false;
        }
        hash hs;
        if(_count==_table.size()){
            vector<node*> newTable(2*_table.size(),nullptr);
            for(const auto& e:_table){
                node* cur = e;
                while(cur!=nullptr){ 
                    node* next = cur->_next;
                    size_t hashi = hs(kov(cur->_value))%newTable.size();
                    cur->_next = newTable[hashi];
                    newTable[hashi] = cur;
                    cur=next;
                }
            }
            _table.swap(newTable);
        }
        size_t hashi = hs(kov(value))%_table.size();
        node* newnode = new node(value);
        newnode->_next = _table[hashi];
        _table[hashi] = newnode;
        ++_count;
        return true;
    }
    void show() {
        for (auto e : _table) {
            node* cur = e;
            while (cur != nullptr) {
                cout << cur->_kv.first << "," << cur->_kv.second << "   ";
                cur = cur->_next;
            }
        }
    }
    private:
    vector<node*> _table;
    size_t _count = 0;
};
#endif