#include <sw/redis++/redis++.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;

int main()
{
	sw::redis::Redis redis("tcp://127.0.0.1:6379");
	sw::redis::OptionalString ret = redis.get("key1");
	cout << ret->c_str() << endl;
	return 0;
}