#include "RB_tree.h"

namespace xunyi{
template <class K,class Compare=my_less<K>>
class set{
    public:
    struct keyOfvalue{
        const K& operator()(const K& key){
            return key;
        }
    };
    typedef typename RB_tree<K,const K,keyOfvalue>::iterator iterator;
    typedef typename RB_tree<K,const K,keyOfvalue>::const_iterator const_iterator;
    iterator begin(){
        return tree.Begin();
    }
    iterator end(){
        return tree.End();
    }
    const_iterator begin()const{
        return tree.Begin();
    }
    const_iterator end()const{
        return tree.End();
    }
    pair<iterator,bool> insert(const K& key){
        return tree.Insert(key);
    }
    iterator find(const K& key){
        return tree.Find(key);
    }
    private:
    RB_tree<K,const K,keyOfvalue,Compare> tree;
};
}