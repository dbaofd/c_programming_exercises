#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
#define NULL 0
#define LEN sizeof(struct student)
int N, n;
struct student
{
	long num;
	char name[10];
	int score;
	struct student *next;
};
struct student *creat(int N)
{
	n = 0;
	int i;
	struct student *p1, *p2, *head;
	for (i = 0; i < N - 1; i++)
	{
		n++;
		if (n == 1)
		{
			p1 = p2 = (struct student *)malloc(LEN);
			scanf("%ld%s%d", &p1->num, &p1->name, &p1->score);
			head = p1;
		}
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student *)malloc(LEN);
		scanf("%ld%s%d", &p1->num, &p1->name, &p1->score);
	}
	p2->next = p1;
	p2 = p1;
	p1->next = NULL;
	return head;
}
struct student *DEL(long num, struct student *head)
{
	struct student *p1, *p2;
	p1 = head;
	while (num != p1->num && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (num == p1->num)
	{
		if (p1 == head)
			head = p1->next;
		else
			p2->next = p1->next;
		n = n - 1;
		printf("DELETE:%ld\n", num);
	}
	else
		printf("%ld can not be found!\n", num);
	return head;
}
struct student *insert(struct student *stud, struct student *head)
{
	struct student *p0, *p1, *p2;
	p1 = head;
	p0 = stud;
	while (p0->num > p1->num && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p0->num > p1->num)
	{
		p1->next = p0;
		p0->next = NULL;
		printf("insert:%ld\n", p0->num);
	}
	else if (p0->num < p1->num)
	{
		if (p1 == head)
			head = p0;
		else
			p2->next = p0;
		p0->next = p1;
		printf("insert:%ld\n", p0->num);
	}

	n = n + 1;
	return head;
}
int main()
{
	struct student *p, *p0, *p00, *p000, *p0000, *head, *stud;
	int NUM, i;
	printf("请输入学生的数量:");
	scanf("%d", &N);
	head = NULL;
	p = p0 = creat(N);
	while (p != NULL)
	{
		printf("%ld %s %d\n", p->num, p->name, p->score);
		p = p->next;
	}
	printf("请输入需要删除的学生的学号:");
	scanf("%ld", &NUM);
	p00 = p000 = DEL(NUM, p0);
	while (p00 != NULL)
	{
		printf("%ld %s %d\n", p00->num, p00->name, p00->score);
		p00 = p00->next;
	}
	printf("请输入要插入的学生的信息:");
	stud = (struct student *)malloc(LEN);
	scanf("%ld%s%d", &stud->num, &stud->name, &stud->score);
	p0000 = insert(stud, p000);
	while (p0000 != NULL)
	{
		printf("%ld %s %d\n", p0000->num, p0000->name, p0000->score);
		p0000 = p0000->next;
	}
	system("pause");
	return 0;
}
