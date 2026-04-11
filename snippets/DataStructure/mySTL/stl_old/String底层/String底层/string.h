#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
namespace bit
{
	class string
	{
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		const static size_t npos;
	public:
		string(const char* str = "");
		string(const string& b);
		/*string& operator=(const string& a);*/
		string& operator=(string tmp);
		~string();
		const char* c_str()const;
		size_t size()const;
		char& operator[](size_t pos);
		const char& operator[](size_t pos)const;
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin();
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;

		void reverse();
		void reserve(size_t n);
		void swap(string& s);
		void clear();

		void push_back(char ch);
		void append(const char* str);
		string substr(size_t pos=0, size_t len = npos)const;

		string& operator+=(char ch);
		string& operator+=(const char* str);
		string& operator+=(const string& s);
		/*string operator+(const string& s)const;*/
		bool operator<(const string& s)const;
		bool operator<=(const string& s)const;
		bool operator>(const string& s)const;
		bool operator>=(const string& s)const;
		bool operator==(const string& s)const;
		bool operator!=(const string& s)const;
		string operator+(const string& s)const;

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void eraser(size_t pos, int n = npos);

		size_t find(char ch, int pos = 0)const;
		size_t find(const char* s, int pos = 0)const;
	};
	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);
}


