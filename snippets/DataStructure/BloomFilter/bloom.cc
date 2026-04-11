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
	BloomFilter<10> filter;
	filter.Set("hello");
	filter.Set("good");
	filter.Set("morning");
	filter.Set("weather");
	filter.Set("sunny");
	filter.Set("monday");
	filter.Set("football");
	filter.Set("666");
	filter.Set("93842");
	cout << filter.IsSet("hello") << endl;
	cout << filter.IsSet("good") << endl;
	cout << filter.IsSet("helll") << endl;
	cout << filter.IsSet("gooe") << endl;
	cout << filter.IsSet("weadher") << endl;
	cout << filter.IsSet("mondey") << endl;
	cout << filter.IsSet("666") << endl;
	cout << filter.IsSet("938") << endl;
	return 0;
}