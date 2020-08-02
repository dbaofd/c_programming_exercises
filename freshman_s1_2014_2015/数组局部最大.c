#include <stdio.h>
int main()
{
	int row, clumn, i, j, count = 0;
	int a[100][100];
	scanf("%d %d", &row, &clumn);
	for (i = 0; i < row; i++)
		for (j = 0; j < clumn; j++)
			scanf("%d", &a[i][j]);
	for (i = 1; i < row - 1; i++)
		for (j = 1; j < clumn - 1; j++)
			if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1])
			{
				printf("%d %d %d\n", a[i][j], i + 1, j + 1);
				count++;
			}
	if (count == 0)
		printf("none %d %d\n", row, clumn);
	return 0;
}