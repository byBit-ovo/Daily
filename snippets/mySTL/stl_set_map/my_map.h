#include "RB_tree.h"
namespace xunyi{
    template<class K,class V,class Compare=my_less<K>>
    class map{
        public:
        struct keyOfvalue{
            const K& operator()(const pair<K,V>& p){
                return p.first;
            }
        };
        typedef typename RB_tree<K,pair<const K,V>,keyOfvalue>::iterator iterator;
        typedef typename RB_tree<K,pair<const K,V>,keyOfvalue>::const_iterator const_iterator;
        V& operator[](const K& key){
            return (tree.Insert(make_pair(key,V())).first)->second;
        }
        iterator begin()
        {
            return tree.Begin();
        }
        iterator end()
        {
            return tree.End();
        }
        const_iterator begin() const
        {
            return tree.Begin();
        }
        const_iterator end() const
        {
            return tree.End();
        }
        pair<iterator,bool> insert(const pair<K,V>& p)
        {
            return tree.Insert(p);
        }
        iterator find(const K& key){
            return tree.Find(key);
        }
        private:
        RB_tree<K,pair<const K,V>,keyOfvalue,Compare> tree;

    };
}