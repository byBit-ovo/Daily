#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>

class Heap
{
    private:
        std::vector<int> _tree;
        int _end;
        void sink(int parent)
        {
            int child = parent*2+1;
            while(child < _end)
            {
                if(child + 1 < _end && _tree[child+1] < _tree[child])
                {
                    ++child;
                }
                if(_tree[child] < _tree[parent])
                {
                    std::swap(_tree[child], _tree[parent]);
                    parent = child;
                    child = parent*2 + 1;
                }
                else{
                    break;
                }
            }
        }
        void SiftUp(int child)
        {
            int parent = (child - 1)/2;
            while(parent >= 0 && _tree[child] < _tree[parent])
            {
                std::swap(_tree[parent], _tree[child]);
                child = parent;
                parent = (parent - 1)/2;
            }
        }
        void Heapify()
        {
            for(int i = (_end- 1 - 1)/2;i>=0;--i) sink(i);
        }
    public:
        Heap(int n):_tree(n),_end(0){}
        template<class Iter>
        Heap(Iter start,Iter end):_tree(start,end),_end(end-start){
            Heapify();
        }

        bool Empty(){
            return _end ==0;
        }
        void push(int val)
        {
            if(_end >= _tree.size())
            {
                _tree.resize(std::max(1,static_cast<int>(_tree.size() * 2)));
            }
            _tree[_end] = val;
            SiftUp(_end);
            ++_end;
        }
        int top(){
            assert(!Empty());
            return _tree[0];
        }
        void pop()
        {
            assert(!Empty());
            std::swap(_tree[0], _tree[--_end]);
            sink(0);
        }
};

int main()
{
    int a[10] = {3,0,1,5,7,4,9,0,2,6};
    Heap heap(a,a+10);
    while(!heap.Empty())
    {
        std::cout<<heap.top()<<" ";
        heap.pop();
    }
    std::cout<<std::endl;
    return 0;
}