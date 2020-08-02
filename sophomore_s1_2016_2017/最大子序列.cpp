#include <iostream>
#include <Windows.h>
using namespace std;
typedef struct stack
{
	int data[100];
	int top;
} stark;
int Maxsumseq(int List[], int N, stark *s)
{
	int maxSum, thisSum;
	int i, j = 0, flag = 0;
	thisSum = maxSum = 0;
	for (i = 0; i < N; i++)
	{
		thisSum += List[i];
		if (thisSum > maxSum && flag == 1) //在出现过小于0的子序列之后，再次出现大于maxsum的序列
		{
			s->top = -1;					 //则将原有序列在堆栈中清除，存入新的子序列
			for (int k = j; k <= i; k++)	 //j是出现小于0子序列后，记录了那时下一个数的位置
				s->data[++s->top] = List[k]; //此时将这个位置之后到i位置的数全部存入堆栈
			j = i;							 //记录这个位置
			flag = 0;						 //将flag重新标记为0
			maxSum = thisSum;				 //用新的最大值取代旧的
		}
		else if (thisSum > maxSum)
		{
			maxSum = thisSum;
			if (j != i)							//序列中间会夹杂负数，而每次读取负数时，是不会执行这个else if语句的，等到过了负数，之后子序列仍然比
			{									//现在大，就把在负数出现之前的位置到现在的i位置中的数全部推到堆栈中
				for (int k = j + 1; k < i; k++) //将中途的负数一系列入栈
					s->data[++s->top] = List[k];
			}
			s->data[++s->top] = List[i];
			j = i; //标记现在的位置
		}
		else if (thisSum <= 0)
		{
			thisSum = 0;
			j = i + 1; //
			flag = 1;  //标记出现了小于0的子序列
		}
	}
	return maxSum;
}
int main()
{
	int a[50];
	int N;
	stark *st = new stark[1]; //用指针定义堆栈有好处，我放到函数跑一下，在函数中产生的数据会被保存下来这些数据是我需要的
	st->top = -1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	cout << Maxsumseq(a, N, st) << endl;
	for (int i = 0; i <= st->top; i++)
	{
		cout << st->data[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
