#include <iostream>
#include <windows.h>
#include <malloc.h>
#define null 0
#define maxsize 100
using namespace std;
struct treenode
{
	char data;
	treenode *lchild;
	treenode *rchild;
};
struct queue
{
	int rear;
	int front;
	treenode *data[maxsize];
};
int addq(treenode *bt, queue &q)
{
	if ((q.rear + 1) % maxsize == q.front)
	{
		cout << "队列已满" << endl;
		return error;
	}
	q.data[q.rear] = bt;
	q.rear = (q.rear + 1) % maxsize;
	return 0;
}
treenode *deleteq(queue &q)
{
	if (q.front == q.rear)
	{
		cout << "队列为空" << endl;
		return 0;
	}
	treenode *t;
	t = q.data[q.front];
	q.front = (q.front + 1) % maxsize;
	return t;
}
treenode *levelcreatetree()
{
	treenode *bt, *t;
	queue q;
	char ch;
	q.rear = q.front = 0;
	bt = (treenode *)malloc(sizeof(treenode));
	cin >> bt->data;
	addq(bt, q);
	while (q.rear != q.front)
	{
		t = deleteq(q);
		cin >> ch;
		if (ch != '#')
		{
			t->lchild = (treenode *)malloc(sizeof(treenode));
			t->lchild->data = ch;
			addq(t->lchild, q);
		}
		else
			t->lchild = null;

		cin >> ch;
		if (ch != '#')
		{
			t->rchild = (treenode *)malloc(sizeof(treenode));
			t->rchild->data = ch;
			addq(t->rchild, q);
		}
		else
			t->rchild = null;
	}
	return bt;
}
int preorder(treenode *t) //先序遍历
{
	if (t)
	{
		cout << t->data;
		preorder(t->lchild);
		preorder(t->rchild);
	}
	return 0;
}
int main()
{
	treenode *bt;
	bt = levelcreatetree();
	preorder(bt);
	cout << endl;
	system("pause");
	return 0;
}