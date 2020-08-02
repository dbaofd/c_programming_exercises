#include <iostream>
#include <Windows.h>
#include <malloc.h>
#define NULL 0
using namespace std;
struct Qnode //链表节点
{
	int data;
	Qnode *next;
};
struct queue //队列
{
	Qnode *rear;
	Qnode *front;
};
void AddQ(queue &Q) //增加数据的函数
{
	Qnode *D = NULL;
	D = (Qnode *)malloc(sizeof(Qnode));
	cout << "请输入数据:";
	cin >> D->data;
	if (Q.front == NULL)	  //如果队列空
		Q.rear = Q.front = D; //队头队尾的地址都等于第一个值的地址，也就是让队头当链式队列的头指针
	else
	{
		Q.rear->next = D; //作为队尾节点，需要增加节点从队尾插入
		Q.rear = Q.rear->next;
	}
	Q.rear->next = NULL; //将队尾节点的next置NULL
}
int DeleteQ(queue &Q) //删除数据的函数
{
	Qnode *p;
	int z;
	if (Q.front == NULL)
	{
		cout << "链队列为空!" << endl;
		return ERROR;
	}
	if (Q.front == Q.rear)
	{
		Q.front = Q.rear = NULL;
		cout << "链队列为空!" << endl;
	}
	else
	{
		p = Q.front;
		z = p->data;
		Q.front = Q.front->next;
		free(p);  //释放被删除节点的内存
		return z; //返回被删除节点的数据，有需要就调用
	}
	return 0;
}
int PrintQ(Qnode *P) //打印队列的函数
{
	Qnode *E;
	E = P;
	if (E == NULL) //队列为空停止打印
		return ERROR;
	cout << "队列为:";
	while (E != NULL)
	{
		cout << E->data << " ";
		E = E->next;
	}
	cout << endl;
}
void Initialize(queue &Q) //初始化对头队尾节点
{
	Q.front = Q.rear = NULL;
}
int main()
{
	queue Q;
	int i;
	Initialize(Q);
	cout << "1.增加数据" << endl
		 << "2.删除数据" << endl
		 << "3.退出" << endl;
	while (cin >> i)
	{
		switch (i)
		{
		case 1:
			AddQ(Q);
			PrintQ(Q.front);
			break;
		case 2:
			DeleteQ(Q);
			PrintQ(Q.front);
			break;
		default:
			cout << "请输入1~3" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}