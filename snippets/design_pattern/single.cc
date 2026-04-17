#include <mutex>
#include <iostream>
class Singleton {
public:
	static Singleton& get_instance() {
		static Singleton obj;
		return obj;
	}
	Singleton(const Singleton &s) = delete;
	Singleton& operator=(const Singleton &s) = delete;
	// 移动构造需要修改源对象的状态，所以参数不能加const
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;

private:
	// 饿汉模式
	// static Singleton obj;
	Singleton() = default;
	~Singleton() = default;
};

class Singleton_ptr{
public:
	static Singleton_ptr* get_instance()
	{
		if(_ptr == nullptr)
		{
			std::unique_lock<std::mutex> guard(_mu);
			if(_ptr == nullptr)
			{
				_ptr = new Singleton_ptr();
			}
		}
		return _ptr;
	}
	Singleton_ptr(const Singleton_ptr& other) = delete;
	Singleton_ptr(Singleton_ptr&& other) = delete;
	Singleton_ptr& operator=(const Singleton_ptr& other) = delete;
	Singleton_ptr& operator=(Singleton_ptr&& other) = delete;
private:
	// 内嵌一个垃圾回收类
	class GC
	{
	public:
		~GC()
		{
			if(Singleton_ptr::_ptr != nullptr)
			{
				delete Singleton_ptr::_ptr;
			}
		}
	private:
	};
	static GC _gc;
	static Singleton_ptr* _ptr;
	static std::mutex _mu;
	Singleton_ptr() = default;
	~Singleton_ptr() = default;
};

Singleton_ptr* Singleton_ptr::_ptr = nullptr;
std::mutex Singleton_ptr::_mu;
Singleton_ptr::GC Singleton_ptr::_gc;

int main() {
	Singleton &a = Singleton::get_instance();
	Singleton &b = Singleton::get_instance();
	Singleton_ptr* pa = Singleton_ptr::get_instance();
	Singleton_ptr* pb = Singleton_ptr::get_instance();
	Singleton_ptr* pc = Singleton_ptr::get_instance();
	Singleton_ptr* pd = Singleton_ptr::get_instance();
	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::cout << pa << std::endl;
	std::cout << pb << std::endl;
	std::cout << pc << std::endl;
	std::cout << pd << std::endl;
	return 0;
}