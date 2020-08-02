#include <stdio.h>
#include <malloc.h>
#define NULL 0
#define LEN sizeof(struct polygon)
struct polygon
{
	float x;
	float y;
	struct polygon *next;
};
int n, N;
struct polygon *p1, *p2, *head;
struct polygon *CREAT(int N)
{
	int i;
	n = 0;
	head = NULL;
	p1 = p2 = (struct polygon *)malloc(LEN);
	printf("构造\n");
	scanf("%f%f", &p1->x, &p1->y);
	for (i = 0; i < N - 1; i++)
	{
		n++;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct polygon *)malloc(LEN);
		scanf("%f%f", &p1->x, &p1->y);
	}
	n++;
	p2->next = p1;
	p2 = p1;
	p1->next = head;
	p1 = head;
	return head;
}
struct polygon *DEL(float x0, float y0)
{
	int i;
	p1 = head;
	for (i = 0; i < n; i++)
	{
		p2 = p1;
		p1 = p1->next;
		if (x0 == p1->x && y0 == p1->y)
		{
			if (p1 == head)
				head = p1->next;
			else
				p2->next = p1->next;
			n = n - 1;
			printf("DELETE:(%.0f,%.0f)\n", x0, y0);
			break;
		}
	}
	return head;
}
struct polygon *INSERT(struct polygon *point)
{
	float X, Y;
	printf("请输入需要插入的位置(插在输入的点之前):");
	scanf("%f%f", &X, &Y);
	p1 = head;
	while (1)
	{
		if (p1->x == X && p1->y == Y)
		{
			p2->next = point;
			point->next = p1;
			break;
		}
		p2 = p1;
		p1 = p1->next;
	}

	n = n + 1;
	return head;
}
int main()
{
	struct polygon *p, *point;
	float X0, Y0;
	int i, j;
	printf("请输入多边形的边数:");
	scanf("%d", &N);
	p = CREAT(N);
	printf("创建成功\n");
	for (i = 0; i < n; i++)
	{
		printf("%.f %.f\n", p1->x, p1->y);
		p1 = p1->next;
	}
	while (~scanf("%d", &j))
	{
		switch (j)
		{
		case 1:
			point = (struct polygon *)malloc(LEN);
			printf("请输入要插入的点:");
			scanf("%f%f", &point->x, &point->y);
			p = INSERT(point);
			printf("插入成功\n");
			for (i = 0; i < n; i++)
			{
				printf("%.f %.f\n", p->x, p->y);
				p = p->next;
			}
			break;
		case 2:
			printf("请输入要删除的点:");
			scanf("%f%f", &X0, &Y0);
			p = DEL(X0, Y0);
			for (i = 0; i < n; i++)
			{
				printf("%.f%5.f\n", p->x, p->y);
				p = p->next;
			}
			break;
		}
	}
	return 0;
}