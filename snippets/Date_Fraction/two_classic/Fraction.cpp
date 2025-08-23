#include "Frac.h"
void Fraction::Simplify()
{
	if (z == 0)
		return;
	int i = 1;
	int y;
	int min = abs(m < z ? m : z);
	for (i = 1; i <= min; i++)
	{
		if (m % i == 0 && z % i == 0)
			y = i;
	}
	m /= y;
	z /= y;
	if (m * z < 0)
	{
		if (m < 0)
		{
			m = -m;
			z = -z;
		}
	}
	if (m < 0 && z < 0)
	{
		m = -m;
		z = -z;
	}
}
Fraction Fraction::operator+(Fraction& f)
{
	int mm = m * f.m;
	int zz = z * f.m + m * f.z;
	Fraction ff(zz,mm);
	ff.Simplify();
	return ff;
}
Fraction Fraction::operator-(Fraction& f)
{
	int mm = m * f.m;
	int zz = z * f.m - m * f.z;
	Fraction ff(zz,mm);
	ff.Simplify();
	return ff;
}
Fraction Fraction::operator*(Fraction& f)
{
	int mm = m * f.m;
	int zz = z*f.z;
	Fraction ff(zz,mm);
	ff.Simplify();
	return ff;
}
Fraction Fraction::operator/(Fraction& f)
{
	int mm = m * f.z;
	int zz = z * f.m;
	Fraction ff(zz,mm);
	ff.Simplify();
	return ff;
}
istream& operator>>(istream& in, Fraction& f)
{
	cout << "请输入分数（用 / 隔开分子分母）： " << endl;
	char c;
	in >> f.z >>c>> f.m;
	while(f.m == 0)
	{
		cout << "分母不能为0，请重新输入分母：" << endl;
		cin >> f.m;
	}
	f.Simplify();
	return in;
}
ostream& operator<<(ostream& out, const Fraction& f)
{
	if (f.z == 0)
	{
		out << "0" << endl;
	}
	else
	{
		if (f.m != 1)
		{
			out << f.z << "/" << f.m << endl;
		}
		else
		{
			out << f.z << endl;
		}
	}
	return out;
}
