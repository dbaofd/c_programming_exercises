#include <stdio.h>
int main()
{
	int m, n, N, i, j, k, sum1 = 0, sum2 = 0;
	scanf("%d", &N);
	for (k = 0; k < N; k++)
	{
		sum1 = 0;
		sum2 = 0;
		scanf("%d%d", &m, &n);
		for (i = 1; i < m; i++)
		{
			if (m % i == 0)
				sum1 += i;
		}
		for (j = 1; j < n; j++)
		{
			if (n % j == 0)
				sum2 += j;
		}
		if (sum1 == n && sum2 == m)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}