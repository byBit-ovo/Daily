#include "Date.h"
bool Date::operator>(const Date &d)const{
    if(_year > d._year){
        return true;
    }
    else if(_year == d._year){
        if(_month > d._month){
            return true;
        }
        else if(_month ==d._month){
            if(_day>d._day){
                return true;
            }
        }
    }
    return false;
}
bool Date::operator<(const Date &d)const{
    return !(*this >= d);
}
bool Date::operator>=(const Date &d)const{
    return *this>d || *this==d;
}
bool Date::operator<=(const Date &d)const{
    return d>*this;
}
bool Date::operator!=(const Date &d)const{
    return !(*this==d);
}
Date& Date::operator++(){
    *this+=1;
    return *this;
}
Date& Date::operator--(){
    *this-=1;
    return *this;
}
Date Date::operator++(int){
    Date tmp(*this);
    *this+=1;
    return tmp;
}
Date Date::operator--(int){
    Date tmp(*this);
    *this -=1;
    return tmp;
}
Date Date::operator+(int day)const{
    Date tmp(*this);
    tmp+=day;
    return tmp;
}
int Date::get_Day(int year, int month){
    assert(month >0 && month <13);
    static int day[12] ={31,28,31,30,31,30,31,31,30,31,30,31};
    int days = day[month-1];
    if(month==2 &&((year%400==0)||(year%4==0 && year%100!=0)))
    ++days;
    return days;
}

Date& Date::operator+=(int day)
{
    if (day < 0)
    {
        *this -= (-day);
    }
    else
    {
        _day += day;
        while (_day > get_Day(_year, _month))
        {
            _day -= get_Day(_year, _month);
            ++_month;
            if (_month == 13)
            {
                ++_year;
                _month = 1;
            }
        }
    }
    return *this;
}
Date Date::operator-(int day) const{
    Date tmp(*this);
    tmp -= day;
    return tmp;
}
Date& Date::operator-=(int day)
{
    if (day < 0)
    {
        *this += (-day);
    }
    else
    {
        _day -= day;
        while (_day <= 0)
        {
            --_month;
            if (_month == 0)
            {
                _month = 12;
                --_year;
            }
            _day += get_Day(_year, _month);
        }
    }
    return *this;
}
ostream& operator<<(ostream& out, const Date& d){
    out<<d._year<<"."<<d._month<<"."<<d._day<<endl;
    return out;
}
istream& operator>>(istream& in,Date& d){
    in>>d._year>>d._month>>d._day;
    return in;
}