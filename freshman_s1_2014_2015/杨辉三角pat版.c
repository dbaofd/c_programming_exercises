#include <stdio.h>
int main()
{
	int i, j, k, a[10][10], N;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (i = 2; i < N; i++)
		for (j = 1; j < i; j++)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < N - 1 - i; k++)
			printf(" ");
		for (j = 0; j <= i; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	return 0;
}
