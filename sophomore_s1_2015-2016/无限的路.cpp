#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	int N, x1, x2, y1, y2, i, T1, T2, n;
	double d, d0;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		T1 = x1 + y1;
		T2 = x2 + y2; //T代表坐标点所在的层数
		if (T1 == T2)
		{
			d = (double)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			cout << fixed << setprecision(3) << d << endl;
		}
		else if (T1 > T2)
		{
			d = (double)sqrt(x1 * x1 + (y1 - T1) * (y1 - T1)) + (double)sqrt((x2 - T2) * (x2 - T2) + y2 * y2);
			d0 = 0;
			while (T1 != T2)
			{
				d0 = d0 + (double)sqrt(T2 * T2 + (T2 + 1) * (T2 + 1));
				T2++;
				if (T2 != T1)
					d0 = d0 + (double)sqrt(T2 * T2 + T2 * T2);
			}
			cout << fixed << setprecision(3) << d + d0 << endl;
		}
		else
		{
			d = (double)sqrt(x2 * x2 + (y2 - T2) * (y2 - T2)) + (double)sqrt((x1 - T1) * (x1 - T1) + y1 * y1);
			d0 = 0;
			while (T1 != T2)
			{
				d0 = d0 + (double)sqrt(T1 * T1 + (T1 + 1) * (T1 + 1));
				T1++;
				if (T2 != T1)
					d0 = d0 + (double)sqrt(T1 * T1 + T1 * T1);
			}
			cout << fixed << setprecision(3) << d + d0 << endl;
		}
	}
	system("pause");
	return 0;
}