#include <sw/redis++/redis++.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unistd.h>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;

void test1(sw::redis::Redis &redis)
{
	redis.flushdb();
	redis.set("key1","11");
	redis.set("key2","12");
	redis.set("key3","13");
	redis.set("key4","14");
	cout << redis.get("key1").value() << endl;
	cout << redis.get("key2").value() << endl;
	cout << redis.get("key3").value() << endl;
	cout << redis.get("key4").value() << endl;
	vector<string> words;
	auto biter = std::back_inserter(words);
	redis.keys("key*",biter);
	for(auto &s: words){
		cout << s << endl;
	}
}
void test2(sw::redis::Redis &client)
{
	client.flushdb();
	if(client.set("this is a ttl for 10s","10") == false)
	{
		cout << "set fail!" << endl;
		return;
	}
	if(client.expire("this is a ttl for 10s",10) == false)
	{
		cout << "expire in 10s" << endl;
		return;
	}
	while(true)
	{
		auto v = client.get("this is a ttl for 10s");
		auto t = client.ttl("this is a ttl for 10s");
		if(v && t){
			cout << v.value() << endl;
			cout << t << endl;
		}
		else
		{
			cout << "not exists" << endl;
			break;
		}
		sleep(1);
	}
}
void test3(sw::redis::Redis &client)
{
	client.flushdb();
	vector<std::pair<string,string>> vecs =
	{
		{"key1","111"},
		{"key2","112"},
		{"key3","113"},
		{"key4","114"},
		{"key5","115"}
	};
	client.mset(vecs.begin(),vecs.end());
	auto value = client.get("key1");
	if(value){
		cout << value.value() << endl;
	}
	value = client.get("key2");
	if(value){
		cout << value.value() << endl;
	}
	value = client.get("key3");
	if(value){
		cout << value.value() << endl;
	}
	value = client.get("key4");
	if(value){
		cout << value.value() << endl;
	}
}
void test4(sw::redis::Redis &client)
{
	client.flushdb();

	client.lpush("key1",{"1","2","fdf"});
	
	int len = client.llen("key1");
	for(int i=0;i < len; ++i)
	{
		cout << client.lindex("key1",i).value() << endl;
	}
}
int main()
{
	sw::redis::Redis redis("tcp://127.0.0.1:6379");
	// test1(redis);
	// test2(redis);
	// test3(redis);
	test4(redis);
	return 0;
}

//s->next = p->next;
//s->next->prev = s;
//1 3 2 1 2 1 5 1 2 3
// 21 ^= 31
//   0 0 1 0 1 0 1
//   0 0 1 1 1 1 1
//   0 0 0 1 0 1 0