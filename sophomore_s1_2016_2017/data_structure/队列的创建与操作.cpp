#include <iostream>
#include <Windows.h>
#include <malloc.h>
#define Maxsize 10
#define NULL 0
using namespace std;
struct queue
{
	int rear;
	int front;
	int data[Maxsize];
};
int isEmpty(queue *Q) //判空
{
	if (Q->front == Q->rear)
		return 1;
	return 0;
}
int isFull(queue *Q) //判满
{
	if ((Q->rear + 1) % Maxsize == Q->front)
		return 1;
	return 0;
}
void AddQ(queue *Q, int item)
{
	if (isFull(Q) == 1)
	{
		cout << "队列空间已满!\n"
			 << endl;
		return;
	}
	Q->data[Q->rear] = item;
	Q->rear = (Q->rear + 1) % Maxsize;
}
int DeleteQ(queue *Q)
{
	if (isEmpty(Q) == 1)
	{
		cout << "队列为空" << endl;
		return ERROR;
	}
	Q->front = (Q->front + 1) % Maxsize;
	return Q->data[Q->front];
}
void PrintQ(queue *Q)
{
	int i;

	if (Q->rear > Q->front)
	{
		cout << "队列元素:";
		for (i = Q->front; i < Q->rear; i++)
			cout << Q->data[i] << " ";
	}
	else if (Q->rear == Q->front)
		cout << "队列为空";
	else
	{
		cout << "队列元素:";
		for (i = Q->front; i < Maxsize; i++)
			cout << Q->data[i] << " ";
		for (i = 0; i < Q->rear; i++)
			cout << Q->data[i] << " ";
	}
	cout << endl;
}
int main()
{
	queue *Q = NULL;
	int item, i, j;
	Q = (queue *)malloc(sizeof(queue));
	Q->rear = Q->front = 0;
	cout << "1.增加数据" << endl
		 << "2.删除数据" << endl
		 << "3.退出" << endl;
	while (cin >> i && i != 3)
	{
		switch (i)
		{
		case 1:
			cin >> item;
			AddQ(Q, item);
			PrintQ(Q);
			break;
		case 2:
			DeleteQ(Q); //该函数返回了队列的头数据，必要时可以调用
			PrintQ(Q);
			break;
		default:
			cout << "请输入1~3!" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
