#include <stdio.h>
int main()
{
	int m, n, j;
	for (m = 0; m < 6; m++)
	{
		for (n = 0; n < 6 - m; n++)
			printf(" ");
		for (j = 0; j < m; j++)
			printf(" *");
		printf("\n");
	}
	for (m = 1; m < 6; m++)
	{
		for (n = 0; n < 6 - m; n++)
			printf(" ");
		for (j = 0; j < m; j++)
			printf(" *");
		printf("\n");
	}
	printf("     ***\n");
	printf("     ***\n");
	printf("     ***\n");
	printf("     ***\n");
	return 0;
}