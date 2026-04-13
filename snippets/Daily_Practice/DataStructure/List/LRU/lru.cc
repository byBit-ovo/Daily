struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v):key(k),value(v),prev(nullptr),next(nullptr){}
};

class MyList {
private:
    Node *dummy;
    Node *tail;
public:
    MyList():dummy(new Node(0,0)), tail(new Node(0,0)){
        dummy->next = tail;
        tail->prev = dummy;
    }
    void moveToTail(Node* target){
        Node* prev = target->prev;
        prev->next = target->next;
        target->next->prev = prev;
        push_back(target);
    }
    void push_back(Node* target) {
        Node* prev = tail->prev;
        target->next = tail;
        target->prev = prev;
        prev->next = target;
        tail->prev = target;
    }
    Node* pop_front(){
        Node* head = dummy->next;
        dummy->next = head->next;
        head->next->prev = dummy;
        return head;
    }
};

class LRUCache {
public:
    LRUCache(int c):capacity(c) {
        
    }
    
    int get(int key) {
        auto iter = numMap.find(key);
        if(iter == numMap.end()){
            return -1;
        }
        cache.moveToTail(iter->second);
        return iter->second->value;
    }
    
    void put(int key, int value) {
        auto iter = numMap.find(key);
        if(iter != numMap.end()){
            cache.moveToTail(iter->second);
            iter->second->value = value;
        }else{ // not found
            if(numMap.size() < capacity) {
                Node* newNode = new Node(key,value);
                cache.push_back(newNode);
                numMap[key] = newNode;
            }else{
                Node* newNode = cache.pop_front();
                int w_key = newNode->key;
                numMap.erase(w_key);
                newNode->key = key;
                newNode->value = value;
                numMap[key] = newNode; 
                cache.push_back(newNode);
            }
        }
    }
private:
    int capacity;
    unordered_map<int, Node*> numMap;
    MyList cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */