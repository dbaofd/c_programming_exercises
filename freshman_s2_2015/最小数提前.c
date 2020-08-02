//输入n(n < 100) 个数，找出其中最小的数，将它与最前面的数交换后输出这些数。
#include <stdio.h>
	int main()
{
	int n, a[100], temp, i, k, j, m;
	while (~scanf("%d", &n))
	{
		if (n == 0)
			break;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; i++)
		{
			k = 0;
			for (j = 0; j < n; j++)
				if (a[i] < a[j])
				{
					k++;
					m = i;
				}
			if (k == n - 1)
			{
				temp = a[m];
				a[m] = a[0];
				a[0] = temp;
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
	return 0;
}