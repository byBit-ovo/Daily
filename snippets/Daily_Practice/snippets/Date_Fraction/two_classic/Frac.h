#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class Fraction
{
	friend istream& operator>>(istream& in, Fraction& f);
	friend ostream& operator<<(ostream& out,const Fraction& f);
private:
	int m;
	int z;
public:
	Fraction(int zz = 1,int mm=1) :m(mm), z(zz) {}
	void Simplify();
	Fraction operator+(Fraction& f);
	Fraction operator-(Fraction& f);
	Fraction operator*(Fraction& f);
	Fraction operator/(Fraction& f);
};
