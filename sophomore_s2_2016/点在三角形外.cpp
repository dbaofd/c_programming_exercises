#include <iostream>
#include <math.h>
#include <Windows.h>
#define ESC 1E-6
using namespace std;
struct Pointd
{
	double x;
	double y;
};
boolean Myjudge(Pointd A, Pointd B, Pointd C, Pointd D);
double area(Pointd A, Pointd B, Pointd C);
double aa(Pointd A, Pointd B);
int main()
{
	double x1, x2, x3, x4, y1, y2, y3, y4;
	Pointd A, B, C, D;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
	{
		A.x = x1;
		A.y = y1;
		B.x = x2;
		B.y = y2;
		C.x = x3;
		C.y = y3;
		D.x = x4;
		D.y = y4;
		if (Myjudge(A, B, C, D))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
boolean Myjudge(Pointd A, Pointd B, Pointd C, Pointd D)
{
	double ABC = area(A, B, C);
	if (fabs(area(A, B, D) + area(A, C, D) + area(B, C, D) - ABC) < ESC)
	{
		return true;
	}
	else
	{
		return false;
	}
}
double area(Pointd A, Pointd B, Pointd C)
{
	double d1 = aa(A, B);
	double d2 = aa(A, C);
	double d3 = aa(B, C);
	double s = (d1 + d2 + d3) / 2;
	return sqrt(s * (s - d1) * (s - d2) * (s - d3));
}
double aa(Pointd A, Pointd B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}