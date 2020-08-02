#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	int n, a[100], i, j, count, t, flag, sum;
	while (cin >> n)
	{
		count = 0;
		sum = 1;
		flag = 1;
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
			sum *= a[i];
		}
		for (i = a[0]; i > 0; i--)
		{
			count = 0;
			for (j = 0; j < n; j++)
			{
				if (a[j] % i == 0)
					count++;
			}
			if (count == n)
				break;
			else if (count != n && j == n - 1)
			{
				flag = 0;
				printf("%d\n", sum);
			}
		}
		if (flag == 1)
			printf("%d", sum / i);
	}
	system("pause");
	return 0;
}