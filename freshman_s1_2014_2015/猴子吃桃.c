#include <stdio.h>
int main()
{
	int N, i, j = 1;
	scanf("%d", &N);
	for (i = 1; i < N; i++)
		j = (j + 1) * 2;
	printf("%d", j);
	return 0;
}