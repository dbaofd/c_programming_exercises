#include <iostream>
#include <Windows.h>
using namespace std;
int judge(int a[], int n)
{
	int i, j, k;
	int sum = 0;
	sum = (n - 1) * n / 2;
	if (n == 1)
		return 1;
	for (i = 0; i < n - 1; i++)
	{
		k = a[i + 1] - a[i];
		if (k <= 0)
			k = 0 - k;
		sum -= k;
	}
	if (sum == 0)
		return 1;
	else
		return 0;
}
int main()
{
	int n;
	int i, flag;
	int a[3022];
	while (cin >> n)
	{
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		flag = judge(a, n);
		if (flag == 1)
			cout << "Jolly" << endl;
		else if (flag == 0)
			cout << "Not jolly" << endl;
	}
	system("pause");
	return 0;
}
