#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
class shape
{
public:
	double x, y;
	virtual void getdata(double p, double q = 0) {}
	virtual void disp() {}
};
class tri : public shape
{
public:
	void getdata(double p, double q = 0)
	{
		x = p;
		y = q;
	}
	void disp()
	{
		double area = 0.5 * x * y;
		cout << "area of triangle : " << area << endl;
	}
};
class rect : public shape
{
public:
	void getdata(double p, double q = 0)
	{
		x = p;
		y = q;
	}
	void disp()
	{
		double area = x * y;
		cout << "area of rectangle : " << area << endl;
	}
};
class circle : public shape
{
public:
	void getdata(double p, double q = 0)
	{
		x = p;
		y = q;
	}
	void disp()
	{
		double area = 3.14 * x * x;
		cout << "area of circle : " << area << endl;
	}
};

int main()
{
	double var1, var2;
	int ch;
	shape *sp;
	sp = new shape;
	tri t;
	rect r;
	circle c;
	while (1)
	{
		cout << "Enter choice \n1.Triangle \t 2.Rectangle \t 3.Circle \t 4.exit\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter base and height\n";
			cin >> var1 >> var2;
			sp = &t;
			sp->getdata(var1, var2);
			sp->disp();
			break;
		case 2:
			cout << "Enter length and breadth\n";
			cin >> var1 >> var2;
			sp = &r;
			sp->getdata(var1, var2);
			sp->disp();
			break;
		case 3:
			cout << "Enter Radius\n";
			cin >> var1;
			sp = &c;
			sp->getdata(var1);
			sp->disp();
			break;
		case 4:
			exit(0);
		}
	}
	return 0;
}