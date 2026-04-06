#include <iostream>
#include <assert.h>
using namespace std;
class Date{
    public:
    Date(int year=2025,int month=1,int day=8):
    _year(year),_month(month),_day(day){}
    Date(const Date& d){
        _year = d._year;
        _month=d._month;
        _day = d._day;
    }
    int get_Day(int year,int month);
    bool operator>(const Date& d)const;
    bool operator<(const Date& d)const;
    bool operator>=(const Date& d)const;
    bool operator<=(const Date& d)const;
    bool operator==(const Date& d)const{
        return _year==d._year&&
               _month==d._month&&
               _day==d._day;
    }
    bool operator!=(const Date& d)const;
    Date& operator++();
    Date& operator--();
    Date operator++(int);
    Date operator--(int);
    Date operator+(int day)const;
    Date& operator+=(int day);
    Date operator-(int day)const;
    Date& operator-=(int day);
    friend ostream& operator<<(ostream& out,const Date& d);
    friend istream& operator>>(istream& in,Date& d);
    private:
    int _year;
    int _month;
    int _day;
};