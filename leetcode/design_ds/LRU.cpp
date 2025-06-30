#include <list>
#include <unordered_map>


class LRUCache {
public:
    std::unordered_map<int,std::list<int>::iterator> map;
    std::list<int> cache; 
    std::list<int>::iterator tail;
    int _capacity;

    LRUCache(int capacity) {
        map.reserve(capacity);
        _capacity=capacity;
    }
    
    int get(int key) {
        auto iter = map.find(key);
        if(iter==map.end()){
            return -1;
        }
        auto liter = iter->second;
        int res = *liter;
        cache.emplace_back(*liter);
        cache.erase(liter);
        map[key] = std::prev(cache.end());
        return res;
    }
    
    void put(int key, int value) {
        auto iter = map.find(key);
        if(iter==map.end()){
            cache.emplace_back(key);
            map.insert(std::make_pair(key,std::prev(cache.end())));
            if(map.size()>_capacity)
            {
                int pop = cache.front();
                cache.pop_front();
                map.erase(pop);
            }

        }else{
            *map[key]=value;
            cache.erase(map[key]);
            cache.emplace_back(key);
        }
    }
    
};