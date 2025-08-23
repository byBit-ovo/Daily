#include "vector.h"
namespace bit
{
	void test()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		auto it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it = v.erase(it);
		}
	}
	void test2()
	{
		int ar[] ={1,2,3,4,0,5,6,7,8,9};

	int n = sizeof(ar) / sizeof(int);

	vector<int> v(ar, ar+n);

	vector<int>::iterator it = v.begin();

	while(it != v.end())

	{

		if(*it != 0)

			cout<<*it;

		else

			v.erase(it);

		it++;

	}
	}
	void test3()
	{
		int ar[] = { 0,1, 2, 3, 4,  5, 6, 7, 8, 9 };

	int n = sizeof(ar) / sizeof(int);

	list<int> mylist(ar, ar+n); 

	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);

	reverse(mylist.begin(), pos);

	reverse(pos, mylist.end());

	list<int>::const_reverse_iterator crit = mylist.crbegin();

	while(crit != mylist.crend())

	{

		cout<<*crit<<" ";

		++crit;

	}

	cout<<endl;
	}
	void test6() {
		vector<int> a = { 1,2,3 };
		for (auto e : a) {
			cout << e;
		}
	}
}

int main()
{
	bit::test6();

	return 0;
}