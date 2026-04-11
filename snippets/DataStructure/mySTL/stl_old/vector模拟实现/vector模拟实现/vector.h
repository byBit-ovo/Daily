#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <assert.h>
#include <algorithm>
using namespace std;
namespace bit
{
	template<class T>
	class vector
	{
	public:
		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_start = _end_of_storage = _finish = nullptr;
			}
		}
		vector() = default;
		vector(initializer_list<T> list)
		{
			reserve(list.size());
			for (auto& e : list)
			{
				push_back(e);
			}
		}
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (auto e : v)
			{
				push_back(e);
			}
		}
		void swap(vector<T>& v)
		{
			std::swap(_finish, v._finish);
			std::swap(_start, v._start);
			std::swap(_end_of_storage,v._end_of_storage);
		}
		vector<T>& operator=(vector<T> t)
		{
			swap(t);
			return *this;
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first++);
			}
		}
		vector(size_t n, const T& value = T())//缺省值用匿名对象，调用默认构造,同时也支持内置类型 
		{
			reserve(n);
			while (n > 0)
			{
				push_back(value);
				--n;
			}
		}
		vector(int n, const T& value = T())//重载构造，解决了不支持vector（int ,int)这样的写法
		{
			reserve(n);
			while (n > 0)
			{
				push_back(value);
				--n;
			}
		}
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		const T& operator[](size_t i)const
		{
			assert(i < size());
			return *(_start + i);
		}
		int capacity()const
		{
			return _end_of_storage - _start;
		}
		int size()const
		{
			return _finish - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				size_t old_size = size();
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T) * size());如果T是string，就是浅拷贝
					for (int i = 0; i < old_size; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}

		}
		void push_back(const T& d)
		{
			/*if (_end_of_storage == _finish)
			{
				int new_capacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(new_capacity);
			}
			*_finish = d;
			++_finish;*/
			//复用
			insert(_finish, d);
		}
		void pop_back()
		{
			assert(size() > 0);
			--_finish;
		}
		iterator insert(iterator pos, const T& d)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _end_of_storage)
			{
				int gap = pos - _start;
				int new_capacity = capacity() ==0 ? 4 : capacity() * 2;
				reserve(new_capacity);
				pos = _start + gap;
			}
			for (iterator t = _finish;t>pos; --t)
			{
				*t = *(t-1);
			}
			*pos = d;
			++_finish;
			return pos;//返回新的pos
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			for (iterator t = pos;t<end(); ++t)
			{
				*t = *(t + 1);
			}
			--_finish;
			return pos;
		}
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;

	};
}


