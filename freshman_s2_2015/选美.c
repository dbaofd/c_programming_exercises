//找出二维数组中，绝对值最大的数，有重复的就数出行小的，行一样就输出列小的
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>
int main()
{
	int h, l, i, j, k, **A, max = 0, m, n;
	while (~scanf("%d%d", &h, &l))
	{
		A = (int **)calloc(h, sizeof(int *));
		for (i = 0; i < h; i++)
		{
			A[i] = (int *)calloc(l, sizeof(int));
		}
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < l; j++)
			{
				scanf("%d", &A[i][j]);
			}
		}
		max = fabs(A[0][0]);
		for (i = 0; i < h; i++)
		{
			for (j = 0; j < l; j++)
			{
				if (A[i][j] <= 0)
				{
					if (-A[i][j] > max)
					{
						max = -A[i][j];
						m = i;
						n = j;
					}
				}
				else if (A[i][j] > 0)
				{
					if (A[i][j] > max && A[i][j] != max)
					{
						max = A[i][j];
						m = i;
						n = j;
					}
				}
			}
		}
		printf("%d %d %d\n", m + 1, n + 1, A[m][n]);
	}
	return 0;
}