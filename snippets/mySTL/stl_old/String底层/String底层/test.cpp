#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>
#include "string.h"
using namespace std;
namespace bit
{
	void test_string1()
	{
		string a = "xunyi";
		string b = "hello";
		string c = a + b;
		cout << c;
	}
}

int main()
{
	bit::test_string1();
	return 0;
}


