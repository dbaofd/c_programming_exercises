// 例
// 2 1//2代表树的节点数，1代表有孩子的节点数
// 01 1 02//01代表那个有孩子的节点，1代表表示他有几个孩子，02代表01的孩子
// 1 0
// 7 4
// 01 2 02 03
// 06 1 07
// 02 2 04 05
// 03 1 06
// 0 0

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	int parent;
	int flag;
	int height;
} Node;
int main()
{
	int N, M;
	int i, j, k, t, p, e;
	int g, flag1, flag2;
	Node a[100], temp;
	int count;
	while (~scanf("%d %d", &N, &M) && N != 0)
	{
		for (i = 0; i < N; i++)
		{
			a[i].parent = -1;
			a[i].flag = 0;
			a[i].height = -1;
		}
		t = 0; //记录数组a的下标
		for (i = 0; i < M; i++)
		{
			scanf("%d", &g);
			flag1 = 0;
			if (i == 0) //i=0说明是第一个，第一个就直接放在数组里面，以后要判断这个点是否在数组内就要遍历数组
			{
				a[t].data = g;
				a[t].flag = 1;
				e = t; //e是用来刚刚输入的数据的下标
				t++;
			}
			else
			{
				for (p = 0; p < t; p++)
				{
					if (g == a[p].data)
					{
						a[p].flag = 1;
						flag1 = 1;
						e = p;
						break;
					}
				}
				if (flag1 == 0)
				{
					a[t].data = g;
					a[t].flag = 1;
					e = t;
					t++;
				}
			}
			if (g == 1)
			{
				a[t - 1].height = 0;
			}
			scanf("%d", &k);
			for (j = 0; j < k; j++)
			{
				scanf("%d", &g);
				flag2 = 0;
				for (p = 0; p < t; p++)
				{
					if (g == a[p].data)
					{
						flag2 = 1;
						a[p].parent = e;
						break;
					}
				}
				if (flag2 == 0)
				{
					a[t].data = g;
					a[t].parent = e;
					t++;
				}
			}
		}
		if (M != 0)
		{
			for (i = 0; i < t; i++)		//根据一个根的深度为0，通过parent计算出所有节点的深度
				for (j = 0; j < t; j++) //因为根节点不一定就在a[0],所以需要双循环来层层遍历
					if (a[a[j].parent].height != -1 && a[j].parent != -1 && a[j].height == -1)
					{
						a[j].height = a[a[j].parent].height + 1;
					}
			for (i = 0; i < N - 1; i++) //冒泡排序为了得到树的深度
				for (j = 0; j < N - 1 - i; j++)
					if (a[j].height > a[j + 1].height)
					{
						temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
			for (j = 0; j <= a[N - 1].height; j++)
			{
				count = 0;
				for (i = 0; i < N; i++)
				{
					if (a[i].height == j && a[i].flag == 0)
						count++;
				}
				printf("%d", count);
				if (j != a[N - 1].height)
					printf(" ");
				else
					printf("\n");
			}
			/*for (i = 0; i < N; i++)
				printf("%d parent%d flag%d height%d\n", a[i].data, a[i].parent, a[i].flag, a[i].height);*/
		}
		else
			printf("1\n");
	}
	system("pause");
	return 0;
}