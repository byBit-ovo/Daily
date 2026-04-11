#include "skiplist.hpp"
#include <iostream>
int main()
{
	SkipList<int> list(5);
	for(int i=0;i<999;i++)
	{
		std::cout << list.RandomLevel() << " ";
	}
	return 0;
}