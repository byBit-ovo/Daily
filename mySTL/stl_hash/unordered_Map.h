#include "hash.h"

template<class K,class V,class hash=hashFunc<K>>
class unordered_Map{
    public:
    struct mapkeyOfv{
        const K& operator()(const pair<const K,V>& data){
            return data.first;
        }
    };
    typedef hash_iter<K,pair<const K,V>,V&,V*,mapkeyOfv,hash> iterator;
    typedef hash_iter<K,pair<const K,V>,const V&,const V*,mapkeyOfv,hash> const_iterator;
    bool insert(const pair<const K,V>& value){
        return _hash_table.Insert(value);
    }
    bool erase(const K& key){
        return _hash_table.erase(key);
    }
    private:
    hashTable<K,pair<const K,V>,mapkeyOfv,hash> _hash_table;
};