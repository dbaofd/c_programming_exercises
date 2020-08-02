#include <stdio.h>
#include <math.h>
int main()
{
	int x, y, i, j, z, flag;
	while (~scanf("%d%d", &x, &y))
	{
		flag = 0;
		for (i = x; i <= y; i++)
		{
			if (x == y)
				break;
			z = i * i + i + 41;
			for (j = 2; j <= sqrt(z); j++)
				if (z % j == 0)
				{
					flag = 1;
				}
		}
		if (flag == 0 && x != y)
			printf("OK\n");
		else if (flag != 0 && x != y)
			printf("Sorry\n");
	}
	return 0;
}