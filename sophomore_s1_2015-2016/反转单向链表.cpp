#include <iostream>
#include <malloc.h>
#include <Windows.h>
#define NULL 0
using namespace std;
struct node
{
	int data;
	struct node *next;
};
node *head;
node *creat()
{
	int n = 1, N;
	cout << "请输入数据的个数:";
	cin >> N;
	node *p1, *p2;
	p1 = p2 = (node *)malloc(sizeof(node));
	cin >> p1->data;
	while (N - 1 != 0)
	{
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (node *)malloc(sizeof(node));
		cin >> p1->data;
		N--;
		n++;
	}
	p2->next = p1;
	p1->next = NULL;
	return head;
}
node *rollback(node *head) //反转单链表函数
{
	node *q, *p, *t;
	p = head;
	q = NULL; //q是我们最后要得到的反转链表的开头
	while (p != NULL)
	{
		t = p->next; //
		p->next = q; //单链表的头节点指向反转链表表头
		q = p;		 //将p复制给q，q重新变成反转链表的表头；
		p = t;		 //将t赋值给p，p重新变成单向链表的表头;
	}
	return q;
}
void print(node *p) //打印链表函数
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	node *p1, *p2, *p3;
	p1 = p2 = creat();
	print(p1);
	p3 = rollback(p2);
	print(p3);
	system("pause");
	return 0;
}