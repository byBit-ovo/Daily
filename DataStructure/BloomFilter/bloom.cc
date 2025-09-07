#include "bloom.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


void testEndia()
{
	int a = 0x01020304;
	char *p = reinterpret_cast<char*>(&a);
	if(*p == 0x01)
	{
		cout << "large endia" << endl;
	}
	else
	{
		cout << "small endia" << endl;
	}
}
void test()
{
	BitSet<0xffffffff> bitset;
	bitset.Set(1234);
	bitset.Set(45);
	bitset.Set(57);
	bitset.Set(838);
	cout << bitset.IsSet(1) << endl;
	cout << bitset.IsSet(23) << endl;
	cout << bitset.IsSet(43) << endl;
	cout << bitset.IsSet(1234) << endl;
	cout << bitset.IsSet(45) << endl;
	cout << bitset.IsSet(47) << endl;
	cout << bitset.IsSet(838) << endl;
}



int main()
{
	BloomFilter<100> filter;
	return 0;
}