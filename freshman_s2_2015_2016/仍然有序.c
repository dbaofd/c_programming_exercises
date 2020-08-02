// 有n(n<=100)个整数，已经按照从小到大顺序排列好，现在另外给一个整数x，请将该数插入到序列中，
// 并使新的序列仍然有序。
#include <stdio.h>
#include <windows.h>
int main()
{
	int m, n, i, k, a[100];
	while (~scanf("%d%d", &n, &m) && m != 0 && n != 0)
	{
		k = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; i++)
		{
			if (m > a[i])
			{
				printf("%d ", a[i]);
				continue;
			}
			else
			{
				k++;
				break;
			}
		}
		printf("%d", m);
		if (i == n - 1 && k == 0)
		{
			printf("\n");
		}
		else
			printf(" ");
		for (; i < n; i++)
		{
			if (i != n - 1)
				printf("%d ", a[i]);
			else
				printf("%d\n", a[i]);
		}
	}
	system("pause");
	return 0;
}