#include "Date.h"
#include "Frac.h"
int main()
{
	Fraction f1(1,2);
	Fraction f2(2,3);
	cin >> f1 >> f2;
	Fraction f3 = f1 / f2;
	cout <<"商:" << f3;

}
#include<iostream>
#include<string>
using namespace std;
/***********begin**********/
//此处完成各个类的书写，并实现题目输出
class base
{
protected:
    string _area;
    int _single_price;
    int _count;
public:
    base(const string& area, int single_price, int count) :
        _area(area), _single_price(single_price), _count(count) {}
    void InStorage(int i)
    {
        _count += i;
    }
    void OutStorage(int i)
    {
        if (_count < i)
        {
            _count = 0;
            cout << "Insufficient  number!" << endl;
            return;
        }
        _count -= i;
    }
    void Calculate()
    {
        cout <<"total money="<<_single_price * _count << endl;
    }
};
class Shirt :public base
{
private:
    string _material;
public:
    Shirt(const string& area, int single_price, int count, const string& material) :
        base(area, single_price, count), _material(material) {}
};
class Cap :public base
{
private:
    string _material;
    string _shape;
public:
    Cap(const string& area, int single_price, int count, const string& material,const string& shape):
        base(area, single_price, count), _material(material),_shape(shape){}
};
class Capboard :public base
{
private:
    string _material;
    string _color;
public:
    Capboard(const string& area, int single_price, int count, const string& material,const string& color):
        base(area, single_price, count), _material(material),_color(color) {}
};
/**********end***********/
//int main() {
//
//    Shirt s1("江西南昌", 235, 150, "纯棉");
//    Cap p1("四川成都", 88, 150, "尼龙", "平顶");
//    Capboard cup1("云南昆明", 3500, 10, "云松木", "原色");
//    int i, j, k, m;
//    cin >> i >> j >> k >> m;
//    s1.InStorage(i);
//    s1.OutStorage(j);
//    p1.OutStorage(k);
//    cup1.OutStorage(m);
//    s1.Calculate();
//    p1.Calculate();
//    cup1.Calculate();
//}