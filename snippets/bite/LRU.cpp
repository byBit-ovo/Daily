// Least Rencently used
#include <iostream>
#include <unordered_map>
#include <queue>
namespace bybit
{
    template<class T>
    class List
    {
        public:
        struct Node{
            T _val;
            Node* _next;
            Node* _prev;
            Node(const T& val=T()):_val(val),_next(nullptr),_prev(nullptr){}
        };
        private:
            Node* _head;
            Node* _tail;
        public:
            List():_head(nullptr),_tail(nullptr){}
            // ~List(){
            //     Node* cur = _head;
            //     while(cur!=nullptr){
            //         Node* next = cur->_next;
            //         delete cur;
            //         cur = next;
            //     }
            // }
            bool empty(){
                return _head==nullptr;
            }
            // void push_front(const T& val){
            //     if(_head==nullptr){
            //         _head = _tail = new Node(val);
            //         return;
            //     }
            //     Node* newHead = new Node(val);
            //     newHead->_next = _head;
            //     _head->_prev = newHead;
            //     _head = newHead;
            // }
            void push_front(Node* newNode){
                if(_head==nullptr){
                    _head = _tail = newNode;
                    return;
                }
                newNode->_next = _head;
                _head->_prev = newNode;
                _head = newNode;
            }
            // void push_back(const T& val){
            //     if(_tail==nullptr){
            //         _head = _tail = new Node(val);
            //         return;
            //     }
            //     _tail->_next = new Node(val);
            //     _tail->_next->_prev = _tail;
            //     _tail = _tail->_next;
            // }
            void push_back(Node* newNode){
                if(_tail==nullptr){
                    _head = _tail = newNode;
                    return;
                }
                _tail->_next = newNode;
                newNode->_prev = _tail;
                _tail = _tail->_next;
            }
            Node* front(){
                return _head;
            }
            // void insert(Node* pos,const T& val){
            //     if(pos==nullptr){
            //         return;
            //     }
            //     if(pos==_head){
            //         push_front(val);
            //         return;
            //     }
            //     Node* prev = pos->_prev;
            //     Node* newNode = new Node(val);
            //     prev->_next = newNode;
            //     newNode->_next = pos;
            //     newNode->_prev = prev;
            //     pos->_prev = newNode;
            // }
            void pop_front(){
                if(_head==nullptr){
                    return;
                }
                // Node* del = _head;
                _head=_head->_next;
                if(_head!=nullptr){
                    _head->_prev = nullptr;
                }else{
                    _tail=nullptr;
                }
                // delete del;
            }
            void pop_back(){
                if(_tail==nullptr){
                    return;
                }
                // Node* del = _tail;
                _tail=_tail->_prev;
                if(_tail != nullptr){
                    _tail->_next = nullptr;
                }else{
                    _head=nullptr;
                }
                // delete del;
            }
            void erase(Node* pos){
                if(pos==nullptr){
                    return;
                }
                if(pos==_head){
                    pop_front();
                    return;
                }
                if(pos==_tail){
                    pop_back();
                    return;
                }
                Node* prev = pos->_prev;
                Node* next = pos->_next;
                prev->_next = next;
                next->_prev = prev;
                // delete pos;
            }
            void show(){
                Node* cur = _head;
                while(cur){
                    std::cout<<cur->_val<<" ";
                    cur = cur->_next;
                }
                std::cout<<std::endl;
            }

    };

    class LRUCache {
        private:
            using Node = List<std::pair<int,int>>::Node;
            int _capacity;
            List<std::pair<int,int>> _queue;
            std::unordered_map<int,Node> map; 
        public:
        LRUCache(int capacity):_capacity(capacity){
        }
        
        int get(int key) {
            if(map.find(key) != map.end())
            {
                Node* refresh = &map[key];
                _queue.erase(refresh);
                _queue.push_back(refresh);
                return refresh->_val.second;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if(map.find(key)!=map.end()){
                //存在则修改
                Node& target = map[key];
                _queue.erase(&target);
                target._val.second = value;
                _queue.push_back(&target);
                return;
            }
            if(map.size()==_capacity){
                Node* waste = _queue.front();
                _queue.pop_front();
                map.erase(waste->_val.first);
            }
            map.insert(std::make_pair(key,Node({key,value})));
            _queue.push_back(&map[key]);
        }
    
    };
}
// void oo(int a){

// }
// void oo(const int &a){

// }
void test()
{
    bybit::LRUCache lru(3);
    lru.put(1,2);
    lru.put(3,4);
    lru.put(4,5);
    lru.put(5,6);
    lru.put(1,2);
}
int main()
{
    auto f = [](int a,int b){
        return a > b;
    };
    struct cmp{
        bool operator()(int a,int b){
            return a>b;
        }
    };
    // std::priority_queue<int,std::vector<int>,decltype(f)> heap(f);
    std::priority_queue<int,std::vector<int>,cmp> heap;
    heap.push(1);
    heap.push(1);
    heap.push(2);
    std::cout<<heap.top()<<std::endl;
    heap.pop();
    std::cout<<heap.top()<<std::endl;
    heap.pop();
    std::cout<<heap.top()<<std::endl;
    heap.pop();
    return 0;
}
