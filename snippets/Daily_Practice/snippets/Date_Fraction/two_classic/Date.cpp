#include "Date.h"
bool Date::CheckDate()
{
	if (_month < 1 || _month>12 ||
		_day<1 || _day >GetMonth_day(_year, _month))
		return false;
	return true;
}
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;

}
bool Date::operator==(const Date& d)
{
	if (_year == d._year &&
		_month == d._month &&
		_day == d._day)
		return true;

	return false;
}
bool Date::operator>=(const Date& d)
{
	if (*this > d || *this == d)
		return true;

	return false;
}
bool Date::operator<(const Date& d)
{
	if (*this >= d)
		return false;

	return true;
}
bool Date::operator<=(const Date& d)
{
	if (*this > d)
		return false;

	return true;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonth_day(_year, _month))
	{
		_day -= GetMonth_day(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day)
{
	Date temp(*this);
	return temp+=day;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month <= 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonth_day(_year, _month);
	}

	return *this;
}
Date Date::operator-(int day)
{
	Date temp = *this;
	return temp -= day;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}
int Date::operator-(const Date& d)
{
	Date big = *this;
	Date small = d;
	int flag = 1;
	if (*this < d)
	{
		big = d;
		small = *this;
		flag = -1;
	}
	int days = 0;
	while (small != big)
	{
		small++;
		days++;
	}
	return days*flag;
}
ostream& operator<<(ostream& out,const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日"<<endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	cout << "请输入日期" << endl;
	in >> d._year >> d._month >> d._day;
	if (!d.CheckDate())
	{
		cout << "日期非法" << endl;
	}
	return in;
}