#include <stdio.h>
#include <Windows.h>
typedef struct Node
{
	int K1;
	int K2;
	int Left;
	int Right;
} node;
int judge(node a[], int N)
{
	int i, j, k;
	int flag = 0;
	for (i = 0; i < N; i++)
	{
		if (a[i].Left == -1 && a[i].Right == -1)
			continue;
		else if (a[i].Left != -1 && a[i].Right != -1)
		{
			if ((a[i].K1 > a[a[i].Left].K1) && (a[i].K1 <= a[a[i].Right].K1))
			{
				if (a[i].K2 < a[a[i].Left].K2 && a[i].K2 <= a[a[i].Right].K2)
					continue;
				else
				{
					flag = 1;
					break;
				}
			}
			else
			{
				flag = 1;
				break;
			}
		}
		else
		{
			if ((a[i].K1 > a[a[i].Left].K1) || (a[i].K1 <= a[a[i].Right].K1))
			{
				if (a[i].K2 < a[a[i].Left].K2 || a[i].K2 <= a[a[i].Right].K2)
					continue;
				else
				{
					flag = 1;
					break;
				}
			}
			else
			{
				flag = 1;
				break;
			}
		}
	}
	return flag;
}
int main()
{
	int N;
	int i, j;
	scanf("%d", &N);
	node *a = (node *)malloc(sizeof(node) * N);
	for (i = 0; i < N; i++)
	{
		scanf("%d%d%d%d", &a[i].K1, &a[i].K2, &a[i].Left, &a[i].Right);
	}
	j = judge(a, N);
	if (j == 1)
		printf("NO\n");
	else if (j == 0)
		printf("YES\n");
	system("pause");
	return 0;
}