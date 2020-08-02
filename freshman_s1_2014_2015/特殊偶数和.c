#include <stdio.h>
int main()
{
	int s = 1, n, i, j;
	scanf("%d", &n);
	for (i = 2; i < n; i += 2)
	{
		printf("%d*", i);
		s *= i;
	}
	s = s * n;
	printf("%d", n);
	printf("=%d\n", s);
	return 0;
}