#include<iostream>
#include "sort.h"
#include <time.h>
using namespace std;
void test()
{
	srand(time(nullptr));
	vector<int> v;
	for (int i = 0; i < 30; ++i)
	{
		v.push_back(rand() % 100);
	}
	/*insert_sort(v);*/
	/*select_sort(v);*/
	/*shell_sort(v);*/
	merge_sort(v);
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}
int main()
{
	test();
	return 0;
}