#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
typedef struct
{
	char data[100];
	int top;
} stack;
int judge(char a[]) //判断表达式是否正确
{
	int k = 0, t = 0, j = 0, i;
	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] == ')')
			k++;
		else if (a[i] == '(')
			t++;
		else if (a[i] == '/' && a[i + 1] == '0' && a[i + 2] != '.')
			j = 1;
	}
	if (k == t && j == 0)
		return 1;
	else
		return 0;
}
char Precede(char a, char b) //判断运算符的优先级，a为操作符栈中的运算符，b为将要进入操作符栈中的运算符
{
	int i = 0, j = 0;
	char pre[][5] = {
		/*运算符之间的优先级制作成一张表格*/
		{'>', '>', '>', '>', '>'},
		{'<', '<', '>', '>', '>'},
		{'<', '<', '>', '>', '>'},
		{'<', '<', '<', '<', '>'},
		{'>', '>', '>', '>', '<'},
	};
	switch (a)
	{
	case '+':
		i = 0;
		break;
	case '-':
		i = 1;
		break;
	case '*':
		i = 2;
		break;
	case '/':
		i = 3;
		break;
	case '(':
		i = 4;
		break;
	}
	switch (b)
	{
	case '+':
		j = 0;
		break;
	case '-':
		j = 1;
		break;
	case '*':
		j = 2;
		break;
	case '/':
		j = 3;
		break;
	case '(':
		j = 4;
		break;
	}
	return pre[i][j];
}
stack transform(char zz[]) //将中缀表达式转换成后缀表达式
{
	stack ex, fu; //ex是用来存放后缀值的堆栈，fu是用来存放操作符的堆栈
	int i;
	//int flag;
	ex.top = -1; //初始化这些堆栈
	fu.top = -1;
	//flag = 0;
	for (i = 0; i < strlen(zz); i++)
	{
		if (zz[i] >= '0' && zz[i] <= '9' || zz[i] == '.') //是数字直接入后缀值栈
		{
			ex.data[++ex.top] = zz[i];
			if ((zz[i + 1] > '9' || zz[i + 1] < '0') && zz[i + 1] != '.') //如果数字后面就是运算符，就在后缀值栈中加一个空格，排除数字后面是小数点的情况
				ex.data[++ex.top] = ' ';
		}
		else if (zz[i] == '=') //是‘#’号就将操作符栈中的剩余运算符弹到后缀值栈中
		{
			while (fu.top != -1) //直到将操作符栈中的操作符弹光
			{
				ex.data[++ex.top] = fu.data[fu.top--];
				//fu.top--;
			}
			ex.data[++ex.top] = zz[i]; //'#'号弹入后缀值栈
			ex.data[++ex.top] = '\0';  //后缀值栈录结束要在字符串末尾加结束字符'\0'
		}
		else if (zz[i] == '-' && (zz[i - 1] == '-' || zz[i - 1] == '+' || zz[i - 1] == '*' || zz[i - 1] == '/' || i - 1 == -1 || zz[i - 1] == '('))
		//判断运算符是负号还是减号，减号如果是第一个，在或条件中会有i-1=-1即可通过此条件判断负号，如果不是首个，则看其前一个是否是运算符
		{
			ex.data[++ex.top] = '0'; //满足条件就将0和空格加入后缀值栈
			ex.data[++ex.top] = ' ';
			fu.data[++fu.top] = zz[i]; //无需经过与操作符栈中的运算符比较优先级，直接入运算符栈
									   //flag = 1;//标记存在负数
		}
		else if (fu.top == -1) //当操作符栈里面是空栈，就将第一个运算符弹进去
			fu.data[++fu.top] = zz[i];
		else if (zz[i] == '(') //遇到左括号就让其直接入操作符栈
			fu.data[++fu.top] = zz[i];
		else if (zz[i] == ')') //遇到右括号就把操作符栈中的截止到左括号的运算符弹到后缀值栈
		{
			while (fu.data[fu.top] != '(')
			{
				ex.data[++ex.top] = fu.data[fu.top];
				fu.top--;
			}
			fu.top--; //删除左括号
		}
		else if (Precede(fu.data[fu.top], zz[i]) == '<')
		//字符串中的运算符优先级小于操作符栈顶的运算符，小于则将操作符栈顶运算符弹入后缀值栈
		{
			ex.data[++ex.top] = fu.data[fu.top]; //先将操作符栈顶运算符弹入后缀值栈
			while (Precede(fu.data[--fu.top], zz[i]) == '<')
			//直到发现字符串中的那个运算符的优先级大于操作符栈中的，就停止向后缀值栈弹入优先级高的运算符
			{
				ex.data[++ex.top] = fu.data[fu.top];
				if (fu.top == 0)
				{ //这个else里面本来有个bug，会使数组下标为-1，导致越界
					fu.top--;
					break;
				}
			}
			fu.data[++fu.top] = zz[i]; //停止后就将这个字符串中的那个字符弹入操作符栈中
									   //flag = 0;
		}
		else if (Precede(fu.data[fu.top], zz[i]) == '>')
			//字符串中的那个运算符的优先级大于操作符栈中的，大于则直接将这个字符串中的运算符弹入操作符栈
			fu.data[++fu.top] = zz[i];
	}
	return ex; //将最后得到的后缀值栈返回
} //ps:之所以将遇到'#','(',')'三种情况放在调用Precede之前，是因为避免这三个运算符和其他运算符进行优先级比较
double readnumber(char f[], int *i) //将后缀值栈中的数由字符型转化成double型
{
	double x = 0;
	int k = 0;
	while (f[*i] >= '0' && f[*i] <= '9')
	{
		x = x * 10 + (f[*i] - '0');
		(*i)++;
	}
	if (f[*i] == '.')
	{
		(*i)++;
		while (f[*i] >= '0' && f[*i] <= '9')
		{
			x = x * 10 + (f[*i] - '0');
			(*i)++;
			k++; //小数点后位数统计
		}
	}
	while (k != 0)
	{
		x = x / 10.0;
		k = k - 1; //小数点后有多少位就要除几次10
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
		else if (f[i] == '-')
		{
			x2 = obst[--top];
			x1 = obst[--top];
			obst[top] = x1 - x2;
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
		else if (f[i] == '/')
		{
			x2 = obst[--top];
			x1 = obst[--top];
			obst[top] = x1 / x2;
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
	stack *ex;
	printf("请输入表达式(按Ctrl+z终止程序)\n");
	while (gets(zz))
	{
		ex = &transform(zz);
		if (judge(zz) == 1)
		{
			printf("后缀表达式如下:\n");
			puts((*ex).data);
			k = 1;
		}
		else
			printf("表达式错误！\n");
		if (k == 1)
			printf("值=%.2lf\n", evalpost((*ex).data));
		system("pause");
		system("CLS");
		printf("请输入表达式(每个数结束后跟一个空格,按Ctrl+z终止程序)\n");
	}
	system("pause");
	return 0;
}

// 1.应用范围：本程序支持负数，浮点数的简单的混合四则运算，支持的运算符有'+','-','*','/','(',')'，终止输入需要按'#'结束，本程序不支持大数运算。
// 2.知识运用：本程序运用堆栈知识解决
// 3.程序函数介绍
// judge：判断表达式正确与否的函数，功能局限于判定左右括号数目是否相等，不能判断左右括号的互换，还能判断除号后面不能是0；
// Precede：判断原字符串数组中的运算符与操作符栈中的运算符的优先级；
// transform：将中缀表达式转换成后缀表达式；
// readnumber：读取后缀值栈中的数字，由char转换成double；
// evalpost：求解后缀表达式；
// 4.程序运行原理
// 本程序开始定义了两个栈，分别用来存放操作符和后缀值
// 首先说明是如何支持负数运算的，在tranform函数之中，程序区别了负号和减号
