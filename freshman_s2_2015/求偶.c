// 有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，现在要求你按照顺序
// 每m个数求出一个平均值，如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。
#include <stdio.h>
int main()
{
	int n, m, q, p, sum, i, j, k;
	while (~scanf("%d%d", &n, &m))
	{
		sum = 0;
		k = 0;
		j = 2;
		if (n % m == 0)
			for (i = 0; i < n; i++)
			{
				sum += j;
				j += 2;
				k++;
				if (k % m == 0)
				{
					if (k != n)
						printf("%d ", sum / m);
					else
						printf("%d\n", sum / m);
					sum = 0;
				}
			}
		else
		{
			q = n % m;
			p = n - q;
			for (i = 0; i < p; i++)
			{
				sum += j;
				j += 2;
				k++;
				if (k % m == 0)
				{
					printf("%d ", sum / m);
					sum = 0;
				}
			}

			for (i = 0; i < q; i++)
			{
				sum += j;
				j += 2;
			}
			printf("%d\n", sum / q);
		}
	}
	return 0;
}