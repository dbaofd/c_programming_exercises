#include <iostream>
#include <Windows.h>
#include <iomanip>
#define PI 3.1415926
using namespace std;
int ball()
{
	double r;
	cout << "Please enter the radius :" << endl;
	cin >> r;
	cout << setiosflags(ios::fixed) << setprecision(2) << (4 * PI * r * r * r) / 3 << endl;
	return 0;
}
int cylinder()
{
	double r, h;
	cout << "Please enter the radius and the height:" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::fixed) << setprecision(2) << PI * r * r * h << endl;
	return 0;
}
int cone()
{
	double h, r;
	cout << "Please enter the radius and the height:" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::fixed) << setprecision(2) << (PI * r * r * h) / 3 << endl;
	return 0;
}
int main()
{
	int i;
	while (1)
	{
		cout << "1-Ball" << endl
			 << "2-Cylinder" << endl;
		cout << "3-Cone" << endl
			 << "other-Exit" << endl;
		cout << "Please enter your command:" << endl;
		cin >> i;
		if (i != 1 && i != 2 && i != 3)
			break;
		switch (i)
		{
		case 1:
			ball();
			break;
		case 2:
			cylinder();
			break;
		case 3:
			cone();
			break;
		}
	}

	return 0;
}