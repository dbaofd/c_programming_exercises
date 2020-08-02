#include <stdio.h>
int main()
{
	int N, U, D, T = 0, sum = 0;
	scanf("%d%d%d", &N, &U, &D);
	while (sum < N)
	{
		T++;
		if (T % 2 != 0)
		{
			sum += U;
			if (sum >= N)
				break;
		}
		else
			sum -= D;
	}
	printf("%d", T);
	return 0;
}