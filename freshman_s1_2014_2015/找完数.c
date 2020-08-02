#include <stdio.h>
int main()
{
	int i, j, m, n, k, t = 0, sum = 0, a[100] = {0};
	scanf("%d %d", &m, &n);
	for (i = m; i <= n; i++)
	{
		sum = 0;
		t = 0;
		if (i == 1)
			printf("%d = %d\n", i, i);
		for (j = 1; j <= i / 2; j++) //一个数的因子一定不会大于这个数的一半
			if (i % j == 0)
			{
				sum += j;
				a[t] = j;
				t++;
			}
		if (sum == i)
		{
			printf("%d = ", i);
			for (k = 0; k < t; k++)
			{
				if (k != t - 1)
					printf("%d + ", a[k]);
				else
					printf("%d", a[t - 1]);
			}
			printf("\n");
		}
	}
	return 0;
}
