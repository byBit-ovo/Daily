#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class Date
{
private:
	int _year;
	int _month;
	int _day;
	static int b;
public:
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in,Date& d);
	bool CheckDate();
	int GetMonth_day(int year,int month)
	{
		assert(month > 0 && month < 13);
		static int month_day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2)
		{
			if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
				return month_day[2] + 1;
		}
		return month_day[month];
	}
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{
		if (!this->CheckDate())
		{
			cout << "日期非法" << endl;
		}
	}
	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);
	Date& operator--();
	Date operator--(int);
	Date& operator++();
	Date operator++(int);
	int operator-(const Date &d);

	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
};
