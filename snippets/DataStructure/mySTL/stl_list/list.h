#pragma once
#include<iostream>
#include <initializer_list>
#include <assert.h>
using namespace std;


namespace xunyi {
    template<class T>
    struct ListNode {
        typedef ListNode<T> Self;
        Self* _next;
        Self* _prev;
        T     _value;
        ListNode(const T& value = T()) :_next(this), _prev(this), _value(value) {}
    };

    template<class T, class Ref, class Pointer>
    struct list_iterator {
        typedef list_iterator<T, Ref, Pointer> Self;
        typedef ListNode<T> Node;
        Node* _node;
        list_iterator(Node* value) :_node(value) {}
        list_iterator(const Self& value) :_node(value._node) {}
        Self& operator++() {
            _node = _node->_next;
            return *this;
        }
        Self operator++(int) {
            Self tmp(*this);
            _node = _node->_next;
            return tmp;
        }
        Self& operator--() {
            _node = _node->_prev;
            return *this;
        }
        Self operator--(int) {
            Self tmp(*this);
            _node = _node->_prev;
            return tmp;
        }

        Ref operator*() {
            return _node->_value;
        }

        Pointer operator->() {
            return &(_node->_value);
        }

        bool operator!=(const Self& him) {
            return _node != him._node;
        }
        bool operator==(const Self& him) {
            return _node == him._node;
        }

    };
    template <class T>
    class List
    {
    private:
        typedef ListNode<T> Node;
        Node *_head = new Node();

    public:
        typedef list_iterator<T, T &, T *> iterator;
        typedef list_iterator<T, const T &, const T *> const_iterator;
        List() = default;
        List(const List<T>& ls) {
            for (const auto& e : ls) {
                push_back(e);
            }
        }
        List(const initializer_list<T>& il)
        {
            for (const auto& e : il)
            {
                push_back(e);
            }
        }
        template<class input_start>
        List(input_start begin,input_start end){
            auto it = begin;
            while(it!=end){
                push_back(*it++);
            }
        }
        List<T>& operator=(List<int> ls) {
            std::swap(_head, ls._head);
            return *this;
        }
        ~List()
        {
            iterator it = begin();
            iterator finish = end();
            while (it != finish)
            {
                it = erase(it);
            }
            delete _head;
            _head = nullptr;
        }
        iterator end()
        {
            return iterator(_head);
        }
        iterator begin()
        {
            return iterator(_head->_next);
        }
        const_iterator end() const
        {
            return const_iterator(_head);
        }
        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }
        iterator insert(iterator pos, const T& value)
        {
            Node* newnode = new Node(value);
            Node* cur = pos._node;
            Node* prev = cur->_prev;
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;
            return iterator(newnode);
        }
        iterator erase(iterator pos)
        {
            assert(pos!=end());
            Node* cur = pos._node;
            Node* prev = cur->_prev;
            Node* next = cur->_next;

            prev->_next = next;
            next->_prev = prev;
            delete cur;
            return iterator(next);
        }
        void push_back(const T& value)
        {
            insert(end(), value);
        }
        void push_front(const T& value)
        {
            insert(begin(), value);
        }
        void pop_back()
        {
            erase(--end());
        }
        void pop_front()
        {
            erase(begin());
        }
    };
}
