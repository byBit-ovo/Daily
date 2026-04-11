#include <iostream>
#include <deque>
using namespace std;
template<class T,class Container = deque<T>>
class Mystack
{
public:
	void push(const T& val)
	{
		_con.push_back(val);
	} 
	void pop()
	{
		_con.pop_back();
	}
	T top() const
	{
		return _con.back();
	}
	bool empty()
	{
		return _con.empty();
	}
	int size()
	{
		return _con.size();
	}
private:
	Container _con;
};
template<class T,class Container = deque<T>>
class Myqueue
{
public:
	void push(const T& value)
	{
		_con.push_back(value);
	}
	void pop()
	{
		_con.pop_front();
	}
	T top()
	{
		return _con.front();
	}
	bool empty()
	{
		return _con.empty();
	}
	int size()
	{
		return _con.size();
	}


private:
	Container _con;

};
void queue()
{
	Myqueue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		int top = q.top();
		cout << top << " ";
		q.pop();
	}
	cout << endl;
}
void stack()
{
	
	Mystack<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		int top = q.top();
		cout << top << " ";
		q.pop();
	}
	cout << endl;
}
int main()
{
	stack();
	queue();

	return 0;
}