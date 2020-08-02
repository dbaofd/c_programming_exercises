#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
#define NULL 0
struct node
{
	int data;
	struct node *next;
	struct node *previous;
};
struct node *head;
node *creat(int i)
{
	int n = 1;
	struct node *p1, *p2;
	while (i != 1)
	{
		if (n == 1)
		{
			p1 = p2 = (struct node *)malloc(sizeof(struct node));
			scanf("%d", &p1->data);
			p1->previous = NULL;
			head = p1;
		}
		else
		{
			p2->next = p1;
			p1->previous = p2;
		}
		p2 = p1;
		p1 = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &p1->data);
		if (i == 2)
		{
			p2->next = p1;
			p1->previous = p2;
			p1->next = NULL;
		}
		i--;
		n++;
	}
	return head;
}
int ergodic()
{
	node *p1, *p2;
	p1 = head;
	while (p1 != NULL) //按照next的顺序遍历链表
	{
		printf("%d ", p1->data);
		p2 = p1;
		p1 = p1->next;
	}
	while (p2 != NULL) //按照previous的顺序遍历链表
	{
		printf("%d ", p2->data);
		p2 = p2->previous;
	}
	printf("\n");
	return 0;
}
node *Delete()
{
	node *p1;
	int data;
	p1 = head;
	printf("请输入要删除的节点数据:");
	scanf("%d", &data);
	while (1)
	{
		if (data == p1->data)
		{
			if (p1 == head)
			{
				p1->next->previous = NULL;
				head = p1->next;
			}
			else if (p1->next == NULL)
			{
				p1->previous->next = NULL;
			}
			else
			{
				p1->previous->next = p1->next;
				p1->next->previous = p1->previous;
			}
			printf("DELETE data%d\n", data);
			break;
		}
		else if (p1->next == NULL)
		{
			printf("找不到你要删除的节点！\n");
			break;
		}
		p1 = p1->next;
	}
	return head;
}
node *Insert()
{
	node *p1, *p;
	int data;
	p1 = head;
	p = (struct node *)malloc(sizeof(struct node));
	printf("请输入需要插入的新节点的数据:");
	scanf("%d", &p->data);
	printf("请输入那个需要插入到它之后的节点数据:");
	scanf("%d", &data);
	while (1)
	{
		if (data == p1->data)
		{
			if (p1->next == NULL)
			{
				p1->next = p;
				p->previous = p1;
				p->next = NULL;
			}
			else
			{
				p->next = p1->next;
				p->previous = p1;
				p1->next->previous = p;
				p1->next = p;
			}
			printf("INSERT data%d\n", p->data);
			break;
		}
		else if (p1->next == NULL)
		{
			printf("找不到你要指定的节点！\n");
			break;
		}
		p1 = p1->next;
	}
	return head;
}
int main()
{
	int i;
	printf("请输入数据的个数:");
	scanf("%d", &i);
	creat(i);
	ergodic();
	Insert();
	ergodic();
	Delete();
	ergodic();
	system("pause");
	return 0;
}