using namespace std;
#include <iostream>
#include <functional>
#include<cstdlib>
#include <unistd.h>
namespace xy
{

    template<class T>
    class shared_ptr{
        public:
        shared_ptr(T* ptr=nullptr):
            _ptr(ptr),
            _count(new int(1)){}
        shared_ptr(const shared_ptr<T>& other):
            _ptr(other._ptr),
            _count(other._count){
            ++*_count;
        }
        template<class D>
        shared_ptr(T* ptr,D del):
            _ptr(ptr),
            _del(del),
            _count(new int(1)){}

        shared_ptr<T>& operator=(const shared_ptr<T>& other){
            if(_ptr!=other._ptr){
                release();
                _ptr = other._ptr;
                _count = other._count;
                ++*_count;
            }
            return *this;
        }
        void release(){
            if(--(*_count)==0){
                // delete _ptr;
                _del(_ptr);
                delete _count;
                _ptr = nullptr;
                _count = nullptr;
                cout << "~share_ptr()" << endl;
            }
        }
        ~shared_ptr(){
            release();
        }
        int use_count(){
            return *_count;
        }
        T& operator*(){
            return *_ptr;
        }
        T* operator->(){
            return _ptr;
        }
        T* get()const{
            return _ptr;
        }

        private:
            T *_ptr;
            int *_count;
            function<void(T *ptr)> _del = [](T *ptr) -> void
            {
                delete ptr;
            };
    };
    template <class T>
    class weak_ptr{
        public:
        weak_ptr(const shared_ptr<T>& other):
            _ptr(other.get()){}
        
        weak_ptr& operator=(const shared_ptr<T>& other){
            _ptr = other.get();
            return *this;
        }

        private:
            T *_ptr;
    };
}