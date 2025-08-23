#include "../stl_vector/vector.h"
#include<deque>
using namespace std;
namespace xunyi{
    template<class Type,class Container=vector<Type>>
    class stack{
        private:
        Container _con;
        public:
        void push(const Type& value){
            _con.push_back(value);
        }
        void pop(){
            _con.pop_back();
        }
        int size(){
            return _con.size();
        }
        const Type& top(){
            return _con.back();
        }
        bool empty(){
            return _con.empty();
        }
    };

    template<class Type,class Container = deque<Type>>
    class queue{
        private:
        Container _con;
        public:
        void push(const Type& value){
            _con.push_back(value);
        }
        void pop(){
            _con.pop_front();
        }
        int size(){
            return _con.size();
        }
        const Type& front(){
            return _con.front();
        }
        bool empty(){
            return _con.empty();
        }
    };

    template<class T>
	struct myless
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	struct mygreater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T, class Container = deque<T>, class Comapre = mygreater<T>>
	class priority_queue
	{
	public:
		priority_queue() = default;

		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			for (int i = (_con.size()-1-1)/2; i >=0 ; i--)
			{
				adjust_down(i);
			}
		}

		void adjust_up(int child)
		{
			Comapre comfunc;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] < _con[child])
				if (comfunc(_con[parent],_con[child]))
				//if (comfunc.operator()(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		void adjust_down(int parent)
		{
			Comapre comfunc;

			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				//if (child+1 < _con.size() && _con[child] < _con[child+1] )
				if (child + 1 < _con.size() && comfunc(_con[child], _con[child + 1]))
				{
					++child;
				}

				//if (_con[parent] < _con[child])
				if (comfunc(_con[parent],_con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size()-1]);
			_con.pop_back();

			adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}