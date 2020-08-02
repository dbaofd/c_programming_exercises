#include <stdio.h>
#include <math.h>
int main()
{
	int n, m, i, a, k, b, c;
	while (~scanf("%d%d", &m, &n))
	{
		k = 0;
		for (i = m; i <= n; i++)
		{
			a = 0;
			b = 0;
			c = 0;
			a = i % 10;
			b = (i / 10) % 10;
			c = i / 100;
			if (i == (a * a * a + b * b * b + c * c * c))
			{
				if (k == 1)
					printf(" ");
				printf("%d", i);
				k = 1;
			}
		}
		if (k == 0)
			printf("no\n");
		else
			printf("\n");
	}
	return 0;
}