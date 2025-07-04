

#include <iostream>
#include <functional>
namespace bybit
{
    template<class T>
    class shared_ptr
    {
        private:
        T* _ptr;
        int* _count;
        std::function<void(T*)> _del =[](T* _ptr){
            delete _ptr;
        };
        public:
        shared_ptr(T* ptr=nullptr):
        _ptr(ptr),_count(nullptr){
            if(_ptr!=nullptr){
                _count = new int(1);
            }
        }
        shared_ptr(T* ptr=nullptr,std::function<void(T*)> del):
        _ptr(ptr),_count(nullptr),_del(del){
            if(_ptr!=nullptr){
                _count = new int(1);
            }
        }
        shared_ptr(const shared_ptr<T>& other):
        _ptr(other.get()),_count(other._count),_del(other._del){
            if(_count!=nullptr){
                ++(*_count);
            }
        }
        T& operator*()const{return *_ptr;}
        T* operator->()const{return _ptr;}
        void release()
        {
            if(_count!=nullptr)
            {
                --(*_count);
                if(*_count==0)
                {
                    // delete _ptr;
                    _del(_ptr);
                    delete _count;
                    _ptr = nullptr;
                    _count = nullptr;
                }
            }
        }
        ~shared_ptr(){
            release();
        }
        void swap(shared_ptr<T>& other){
            std::swap(other._count,_count);
            std::swap(other._ptr,_ptr);
        }
        const shared_ptr<T>& operator=(const shared_ptr<T>& other)
        {
            if(&other != this)
            {
                //1.写法一
                //release();
                // _ptr = other.get();
                // _count = other._count;
                // if(_count!=nullptr){
                //     (*_count)++;
                // }
                //2.更推荐的写法
                shared_ptr<T> tmp(other);
                this->swap(tmp);
            }
            return *this;
        }
        T* get()const {return _ptr;}

        int use_count()const 
        {
            if(_count==nullptr){
                return 0;
            }
            return *_count;
        }
    };
}
class test{
    public:
    test(int a=0):_a(a){
        std::cout<<"test()"<<std::endl;
    }
    ~test(){
        std::cout<<"~test(),a="<<_a<<std::endl;
    }
    private:
    int _a;
};

int main()
{
    bybit::shared_ptr<test> p1(new test(1));
    std::cout<<"--------line1---------"<<std::endl;
    {
        auto p2 = p1;
        std::cout<<"--------line2---------"<<std::endl; 
        bybit::shared_ptr<test> p3(new test(2));
    }
    std::cout<<"--------line3---------"<<std::endl;
    bybit::shared_ptr<test> p3(new test(3));
    p3=p3;
    std::cout<<"--------line4---------"<<std::endl;
    if(1){
        bybit::shared_ptr<test> p4(new test(4));
    }
    std::cout<<"--------line5---------"<<std::endl;

    return 0;
}
