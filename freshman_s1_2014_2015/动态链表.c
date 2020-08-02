#include <stdio.h>
#include <malloc.h>
#define NULL 0
#define LEN sizeof(struct student)
struct student
{
	long num;
	float score;
	struct student *next;
};
int n;
struct student *p1, *p2, *head;
struct student *CREAT()
{
	n = 0;
	head = NULL;
	p1 = p2 = (struct student *)malloc(LEN);
	scanf("%ld,%f", &p1->num, &p1->score);
	while (p1->num != 0)
	{
		n++;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student *)malloc(LEN);
		scanf("%ld,%f", &p1->num, &p1->score);
	}
	p2->next = NULL;
	return head;
}
struct student *DEL(long num)
{
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
struct student *INSERT(struct student *stud)
{
	struct student *p0;
	p1 = head;
	p0 = stud;
	while (p0->num > p1->num)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p0->num < p1->num)
	{
		if (p1 == head)
			head = p0;
		else
			p2->next = p0;
		p0->next = p1;
	}
	else
	{
		p1->next = p0;
		p0->next = NULL;
	}
	n = n + 1;
	return head;
}
int main()
{
	struct student *p, *stud;
	long num;
	p = CREAT();
	while (p != NULL)
	{
		printf("%ld%5.f\n", p->num, p->score);
		p = p->next;
	}
	stud = (struct student *)malloc(LEN);
	scanf("%ld,%f", &stud->num, &stud->score);
	p = INSERT(stud);
	while (p != NULL)
	{
		printf("%ld%5.f\n", p->num, p->score);
		p = p->next;
	}
	scanf("%ld", &num);
	p = DEL(num);
	while (p != NULL)
	{
		printf("%ld%5.f\n", p->num, p->score);
		p = p->next;
	}
	return 0;
}
//主函数可以这样子，无限查找
// int main()
// {
// 	struct student *p;
// 	long num;
// 	p=CREAT();
// 	while(p!=NULL)
// 	{
// 		printf("%ld %5.f\n",p->num,p->score);
// 		p=p->next;
// 	}
// 	while(~scanf("%ld",&num))
// 	{
// 	    p=DEL(num);
// 	    while(p!=NULL)
// 	   {
// 		    printf("%ld %5.f\n",p->num,p->score);
// 		    p=p->next;
// 	   }
// 	}
// 	return 0;
// }