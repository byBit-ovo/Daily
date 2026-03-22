struct Node {
    int key;
    int value;
    int freq;
    Node* next;
    Node* prev;
    Node(int k,int v, int f):
    key(k),value(v),freq(f),next(nullptr),prev(nullptr){}
};
class MyList {
private:
    Node* dummy;
    Node* tail;
public:
    MyList():dummy(new Node(0,0,0)),tail(new Node(0,0,0)){
        dummy->next = tail;
        tail->prev = dummy;
    }
    void append(Node* newNode) {
        Node* prev = tail->prev;
        newNode->next = tail;
        prev->next = newNode;
        newNode->prev = prev;
        tail->prev = newNode;

    }
    bool isEmpty(){
        return dummy->next == tail;
    }
    void remove(Node* target) {
        Node* prev = target->prev;
        Node* next = target->next;
        prev->next = next;
        next->prev = prev;
    }
    Node* pop(){
        Node* f = dummy->next;
        remove(f);
        return f;
    }
};
class LFUCache {
public:
    LFUCache(int c):capacity(c) {
        
    }
    void updateFreq(Node* target) {
        int key = target->key;
        freqList[target->freq].remove(target);
        if(minFreq == target->freq && freqList[target->freq].isEmpty()) {
            minFreq += 1;
        }
        target->freq += 1;
        freqList[target->freq].append(target);
    }
    // key  -> node
    // freq -> list 存相同频率的节点值（最先使用的排在最后
    // get -> 将node 从freq==n的链表中取出， 放入freq==n+1的链表末尾，如果freq==n链表为空，更新minFreq=n+1
    int get(int key) {
        auto iter = keyNode.find(key);
        if(iter == keyNode.end()) {
            return -1;
        }
        Node* target = iter->second;
        updateFreq(target);
        return target->value;
    }
    // put:
    // 存在：新节点存在—>将node 从freq==n的链表中取出， 放入freq==n+1的链表末尾，如果freq==n链表为空，更新minFreq=n+1
    // 不存在且满：删除freq最小的队头节点,如果为空了, 则更新freq==1
    // 最后放入freq==1
    void put(int key, int value) {
        if(capacity==0){
            return;
        }
        auto iter = keyNode.find(key);
        if(iter != keyNode.end()) {
            iter->second->value = value;
            updateFreq(iter->second);
            return;
        }
        // 不存在该节点
        // 满了，要删除频率最低的节点,并添加新节点
        if(capacity == curSize) {
            Node* w = freqList[minFreq].pop();
            keyNode.erase(w->key);
            w->key = key;
            w->value = value;
            w->freq = 1;
            keyNode[w->key] = w;
            freqList[1].append(w);

        }else{// 没满， 直接添加
            Node * newNode = new Node(key, value, 1);
            keyNode[key] = newNode;
            freqList[1].append(newNode);
            curSize+=1;

        }
        //只要添加新节点，minFreq一定是1
        minFreq = 1;
        
    }
private:
    int capacity;
    int curSize = 0;
    int minFreq = 0;
    unordered_map<int,Node*> keyNode;
    unordered_map<int,MyList> freqList;
    
};



/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */