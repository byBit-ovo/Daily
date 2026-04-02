



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

};



int main() {
	Singleton &a = Singleton::get_instance();
	Singleton &b = Singleton::get_instance();
	return 0;
}