#include <stdio.h>
int main()
{
	int i, temp = 4, n, sum = 0, s = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		sum = sum + s;
		s = temp;
		temp *= 2;
	}
	printf("sum = %d\n", sum + 1);
	return 0;
}