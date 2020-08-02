#include <stdio.h>
#include <windows.h>
int main()
{
	int a[100], m, n, i, temp, j, k;
	while (~scanf("%d", &n) && n != 0)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				if (a[j] <= 0 && a[j + 1] <= 0)
				{
					if (-a[j] < -a[j + 1])
					{
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
				else if (a[j] >= 0 && a[j + 1] >= 0)
				{
					if (a[j] < a[j + 1])
					{
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
				else if (a[j] <= 0 && a[j + 1] >= 0)
				{
					if (-a[j] < a[j + 1])
					{
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
				else if (a[j] >= 0 && a[j + 1] <= 0)
				{
					if (a[j] < -a[j + 1])
					{
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			if (i != n - 1)
				printf("%d ", a[i]);
			else
				printf("%d\n", a[i]);
		}
	}
	system("pause");
	return 0;
}
