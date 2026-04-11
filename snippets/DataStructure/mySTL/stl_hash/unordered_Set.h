#include "hash.h"

template <class K,class hash=hashFunc<K>>
class unordered_Set{
    public:
    struct setkeyOfvalue{
        const K& operator()(const K& key){
            return key;
        }
    };
    typedef hash_iter<K,const K,K&,K*,setkeyOfvalue,hash> iterator;
    typedef hash_iter<K,const K,const K&,const K*,setkeyOfvalue,hash> const_iterator;
    bool insert(const K& key){
        return _hash_table.Insert(key);
    }
    bool erase(const K& key){
        return _hash_table.erase(key);
    }
    private:
    hashTable<K,const K,setkeyOfvalue,hash> _hash_table;
};