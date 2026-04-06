#include <cstddef>
#include <iostream>


namespace my {

template<typename T>
class shared_ptr {
private:
    int* _count;
    T* _obj;
public:
    shared_ptr():_count(nullptr),_obj(nullptr){}
    shared_ptr(T* obj):_obj(obj),_count(nullptr) {
        if(_obj != nullptr) {
            _count = new int(1);
        }
    }
    shared_ptr(const shared_ptr<T>& other):
    _obj(other._obj),_count(other._count) {
        increment();
    }
    ~shared_ptr(){
        decrement();
    }
    const T& operator*() const {
        return *_obj;
    }
    // sp<T> *const this 
    const T* operator->() const {
        return _obj;
    }
    T& operator*() {
        return *_obj;
    }
    // sp<T> *const this 
    T* operator->() {
        return _obj;
    }
    shared_ptr<T>& operator=(const shared_ptr<T>& other){
        shared_ptr<T> tmp(other);
        this->swap(tmp);
        return *this;
    }

private:
    void increment() {
        if(_count != nullptr) {
            *_count += 1;
        }
    }
    void decrement(){

        if(_count != nullptr && *_count > 0) {
            *_count -= 1;
        }
        if(_count != nullptr && *_count == 0){
            delete _count;
            delete _obj;
            _count = nullptr;
            _obj = nullptr;
        }
    }
    void swap(shared_ptr<T>& other) {
        std::swap(_count, other._count);
        std::swap(_obj, other._obj);
    }
    
};
}


int main(){
    const my::shared_ptr<int> a(new int(1));
    return 0;
}