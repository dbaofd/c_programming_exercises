#include <stdio.h>
int main()
{
	int monkey[1000] = {0}, count, N, i, j = 1, k;
	scanf("%d", &N);
	count = N;
	while (count != 1)
	{
		for (i = 0; i < N; i++)
		{
			if (monkey[i] == 1)
				continue;
			if (j == 3)
			{
				monkey[i] = 1;
				count--;
				j = 0;
			}
			j++;
		}
	}
	for (i = 0; i < N; i++)
		if (monkey[i] == 0)
			printf("%d", i + 1);
	return 0;
}