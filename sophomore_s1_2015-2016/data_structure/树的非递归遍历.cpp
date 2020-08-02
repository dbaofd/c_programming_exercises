#include <iostream>
#include <windows.h>
#include <malloc.h>
using namespace std;
#define null 0
#define maxsize 100
struct treenode //树的节点
{
	int data;
	treenode *lchild;
	treenode *rchild;
};
struct stack //用来存储结点指针地址的堆栈
{
	treenode *data[maxsize];
	int top;
};
treenode *createtree() //先序创建树
{
	int ch;
	treenode *t = null;
	scanf("%d", &ch);
	if (ch == -1)
	{
		t = null;
	}
	else
	{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = createtree();
		t->rchild = createtree();
	}
	return t;
}
int isempty(stack *s) //判空栈
{
	if (s->top == -1)
		return 1;
	return 0;
}
void push(stack *s, treenode *t) //推入栈
{
	if (s->top == maxsize - 1)
		printf("堆栈已满\n");
	else
		s->data[++(s->top)] = t;
}
treenode *pop(stack *s) //出栈
{
	if (s->top == -1)
	{
		printf("堆栈为空\n");
		system("pause");
		exit(0);
	}
	return (s->data[s->top--]);
}
void inorder(treenode *bt) //中序遍历
{
	treenode *t;
	struct stack *s;
	s = (stack *)malloc(sizeof(stack));
	s->top = -1;
	t = null;
	t = bt;
	while (t || !isempty(s))
	{
		while (t)
		{
			push(s, t);
			t = t->lchild;
		}
		t = null;
		if (!isempty(s))
		{
			t = pop(s);
			printf("%d", t->data);
			t = t->rchild;
		}
	}
}
void preorder(treenode *bt) //先序遍历
{
	treenode *t;
	struct stack *s;
	s = (stack *)malloc(sizeof(stack));
	s->top = -1;
	t = null;
	t = bt;
	while (t || !isempty(s))
	{
		while (t)
		{
			push(s, t);
			printf("%d", t->data);
			t = t->lchild;
		}
		t = null;
		if (!isempty(s))
		{
			t = pop(s);
			t = t->rchild;
		}
	}
}
void postorder(treenode *bt) //后序遍历
{
	treenode *t;
	struct stack *s;
	s = (stack *)malloc(sizeof(stack));
	s->top = -1;
	t = null;
	int flag[20];
	t = bt;
	while (t || !isempty(s))
	{
		while (t)
		{
			push(s, t);
			t = t->lchild;
			flag[s->top] = 0;
		}
		while (!isempty(s) && flag[s->top] == 1) //从右孩子回来才能进行输出操作
		{
			t = pop(s);
			printf("%d", t->data);
		}
		if (!isempty(s))
		{
			flag[s->top] = 1;
			t = s->data[s->top];
			t = t->rchild;
		}
		else
			break;
	}
}
struct queue //队列
{
	int rear;
	int front;
	treenode *data[maxsize];
};
int addq(treenode *bt, queue &q) //入队
{
	q.data[q.rear] = bt;
	q.rear = (q.rear + 1) % maxsize;
	if (q.rear == q.front)
	{
		cout << "队列已满" << endl;
		return error;
	}
	return 0;
}
treenode *deleteq(queue &q) //出队，并返回出队的元素
{
	treenode *t;
	if (q.front == q.rear)
	{
		cout << "队列为空" << endl;
		return error;
	}
	t = q.data[q.front];
	q.front = (q.front + 1) % maxsize;
	return t;
}
void levelorder(treenode *bt) //层序遍历
{
	queue q;
	treenode *t;
	if (!bt)
		return;
	q.rear = q.front = 0;
	addq(bt, q);
	while (q.rear != q.front)
	{
		t = deleteq(q);
		cout << t->data;
		if (t->lchild)
			addq(t->lchild, q);
		if (t->rchild)
			addq(t->rchild, q);
	}
	cout << endl;
}
int main()
{
	stack s;
	treenode *bt = null;
	bt = createtree();
	printf("中序遍历:");
	inorder(bt);
	printf("\n先序遍历:");
	preorder(bt);
	printf("\n后序遍历");
	postorder(bt);
	printf("\n层序遍历");
	levelorder(bt);
	system("pause");
	return 0;
}