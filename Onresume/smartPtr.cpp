

#include <iostream>

namespace bybit
{
    template<class T>
    class shared_ptr
    {
        private:
        T* _ptr;
        int* _count;
        public:
        shared_ptr():_ptr(nullptr),_count(new int(1)){}
        shared_ptr(T* ptr):_ptr(ptr),_count(new int(1)){}
        shared_ptr(const shared_ptr<T>& other):_ptr(other.get()),_count(other.use_ptr()){
            *_count++;
        }
        void release()
        {
            --(*_count);
            if(*_count==0)
            {
                delete _ptr;
                delete _count;
                _ptr = _count=nullptr;
            }
        }
        ~shared_ptr(){
            release();
        }
        const shared_ptr<T>& operator=(const shared_ptr<T>& other)
        {
            release();
            _ptr = other.get();
            _count = other.use_ptr();
            ++(*_count);
            return *this;
        }
        T* get(){return _ptr;}
        int* use_ptr(){return _count;}
    };
}
class test{
    public:
    test(){
        std::cout<<"test()"<<std::endl;
    }
    ~test(){
        std::cout<<"~test()"<<std::endl;
    }
};

int main()
{
    bybit::shared_ptr<test> p1(new test());
    std::cout<<"--------line1---------";
    {
        auto p2 = p1;
        std::cout<<"--------line2---------";
    }
    std::cout<<"--------line3---------";

    return 0;
}
