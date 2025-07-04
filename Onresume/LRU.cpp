// Least Rencently used
#include <iostream>
#include <unordered_map>
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
            ~List(){
                Node* cur = _head;
                while(cur!=nullptr){
                    Node* next = cur->_next;
                    // delete cur;
                    cur = next;
                }
            }
            bool empty(){
                return _head==nullptr;
            }
            void push_front(const T& val){
                if(_head==nullptr){
                    _head = _tail = new Node(val);
                    return;
                }
                Node* newHead = new Node(val);
                newHead->_next = _head;
                _head->_prev = newHead;
                _head = newHead;
            }
            void push_back(const T& val){
                if(_tail==nullptr){
                    _head = _tail = new Node(val);
                    return;
                }
                _tail->_next = new Node(val);
                _tail->_next->_prev = _tail;
                _tail = _tail->_next;
            }
            void insert(Node* pos,const T& val){
                if(pos==nullptr){
                    return;
                }
                if(pos==_head){
                    push_front(val);
                    return;
                }
                Node* prev = pos->_prev;
                Node* newNode = new Node(val);
                prev->_next = newNode;
                newNode->_next = pos;
                newNode->_prev = prev;
                pos->_prev = newNode;
            }
            void pop_front(){
                if(_head==nullptr){
                    return;
                }
                Node* del = _head;
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
                Node* del = _tail;
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
            int _capacity;
            List<std::pair<int,int>> _queue;
            std::unordered_map<int,List<std::pair<int,int>>::Node*> map; 
            using Node = List<std::pair<int,int>>::Node;
        public:
        LRUCache(int capacity):_capacity(capacity){
        }
    
        int get(int key) {
            
        }
        
        void put(int key, int value) {
            if(map.find(key)!=map.end()){
                //存在则修改
                Node* target = map[key];
                _queue.erase(target);
                target->_val.second = value;
                _queue.push_back()
            }
        }
    
    };
}
int main()
{
    bybit::List<int> ls;
    for(int i=1;i<=3;++i){
        ls.push_back(i);
    }
    for(int i=4;i<=7;++i){
        ls.push_front(i);
    }
    //7 6 5 4 1 2 3
    ls.show();  
    // while(!ls.empty()){
    //     ls.pop_back();
    //     ls.show();
    // }
    while(!ls.empty()){
        ls.pop_front();
        ls.show();
    }
    return 0;
}