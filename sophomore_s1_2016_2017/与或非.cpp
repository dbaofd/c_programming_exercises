#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
typedef struct S
{
	char data[100];
	int top;
} stack;

char Precede(char a, char b)
{
	int i = 0, j = 0;
	char pre[][3] = {
		/*运算符之间的优先级制作成一张表格*/
		{'>', '>', '>'},

		{'<', '>', '>'},

		{'>', '>', '<'},
	};
	switch (a)
	{
	case '+':
		i = 0;
		break;
	case '*':
		i = 1;
		break;
	case '(':
		i = 2;
		break;
	}
	switch (b)
	{
	case '+':
		j = 0;
		break;
	case '*':
		j = 1;
		break;
	case '(':
		j = 2;
		break;
	}
	return pre[i][j];
}
stack transform(char zz[])
{
	stack ex, fu;
	int i;
	//int flag;
	ex.top = -1;
	fu.top = -1;
	//flag = 0;
	for (i = 0; i < strlen(zz); i++)
	{
		if (zz[i] >= '0' && zz[i] <= '9')
		{
			ex.data[++ex.top] = zz[i];
			if ((zz[i + 1] > '9' || zz[i + 1] < '0'))
				ex.data[++ex.top] = ' ';
		}
		else if (zz[i] == '=')
		{
			while (fu.top != -1)
			{
				ex.data[++ex.top] = fu.data[fu.top--];
				//fu.top--;
			}
			ex.data[++ex.top] = zz[i];
			ex.data[++ex.top] = '\0';
		}
		else if (fu.top == -1)
			fu.data[++fu.top] = zz[i];
		else if (zz[i] == '(')
			fu.data[++fu.top] = zz[i];
		else if (zz[i] == ')')
		{
			while (fu.data[fu.top] != '(')
			{
				ex.data[++ex.top] = fu.data[fu.top];
				fu.top--;
			}
			fu.top--;
		}
		else if (Precede(fu.data[fu.top], zz[i]) == '<')
		{
			ex.data[++ex.top] = fu.data[fu.top];
			while (Precede(fu.data[--fu.top], zz[i]) == '<')
				ex.data[++ex.top] = fu.data[fu.top];
			fu.data[++fu.top] = zz[i];
			//flag = 0;
		}
		else if (Precede(fu.data[fu.top], zz[i]) == '>')
			fu.data[++fu.top] = zz[i];
	}
	return ex;
}
double readnumber(char f[], int *i)
{
	double x = 0;
	int k = 0;
	while (f[*i] >= '0' && f[*i] <= '9')
	{
		x = x * 10 + (f[*i] - '0');
		(*i)++;
	}
	return x;
}
double evalpost(char f[]) //求解后缀表达式
{
	double obst[100]; //存放double型的数，进行运算
	int top = 0;
	int i = 0;
	double x1, x2;
	while (f[i] != '=')
	{
		if (f[i] >= '0' && f[i] <= '9')
		{
			obst[top] = readnumber(f, &i);
			top++;
		}
		else if (f[i] == ' ')
			i++;
		else if (f[i] == '+')
		{
			x2 = obst[--top];
			x1 = obst[--top];
			obst[top] = x1 + x2;
			top++;
			i++;
		}
		else if (f[i] == '*')
		{
			x2 = obst[--top];
			x1 = obst[--top];
			obst[top] = x1 * x2;
			top++;
			i++;
		}
	}
	return obst[0];
}
int main()
{
	char zz[100];
	int k = 0;
	char yufei[200];
	char ch[200];
	stack *ex;
	int t;
	for (int j = 0; j < 20; j++)
	{
		gets(ch);
		t = 0;
		for (int i = 0; i < strlen(ch); i++)
		{
			if (ch[i] == '!')
			{
				if (ch[i + 1] == 'V')
				{
					yufei[t++] = '0';
					i += 2;
				}
				else if (ch[i + 1] == 'F')
				{
					yufei[t++] = '1';
					i += 2;
				}
			}
			else if (ch[i] == 'V')
				yufei[t++] = '1';
			else if (ch[i] == 'F')
				yufei[t++] = '0';
			else if (ch[i] == '|')
				yufei[t++] = '+';
			else if (ch[i] == '&')
				yufei[t++] = '*';
			else if (ch[i] == '(')
				yufei[t++] = '(';
			else if (ch[i] == ')')
				yufei[t++] = ')';
		}
		yufei[t++] = '=';
		yufei[t++] = '\0';
		ex = &transform(yufei);
		if (evalpost((*ex).data) == 1)
			printf("Expression %d: V\n", j);
		else
			printf("Expression %d: F\n", j);
	}
	system("pause");
	return 0;
}