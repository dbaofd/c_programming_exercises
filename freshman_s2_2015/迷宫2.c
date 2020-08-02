#include <stdio.h>
#include <malloc.h>
#include <windows.h>
struct location //定义迷宫结构体
{
	int row;
	int column;
};
struct stack //定义堆栈
{
	location data[100]; //可以记录100个位置
	int top;
};
int h, l, R, C, r, c; //分别代表迷宫行、列、出口坐标、入口坐标
int **a, **mark;	  //定义二维数组，分别代表迷宫数组，标记数组，轨迹数组
char **k;
stack road;		// 定义一个迷宫堆栈，用来记录走过的位置信息
int creatMaze() //创建迷宫函数
{
	int i, j;
	printf("请输入迷宫个的行数与列数:");
	scanf("%d%d", &h, &l);
	a = (int **)malloc(sizeof(int *) * h); //使用malloc申请二维数组空间
	for (i = 0; i < h; i++)
		a[i] = (int *)malloc(sizeof(int) * l);
	mark = (int **)malloc(sizeof(int *) * h);
	for (i = 0; i < h; i++)
		mark[i] = (int *)malloc(sizeof(int) * l);
	k = (char **)malloc(sizeof(char *) * h);
	for (i = 0; i < h; i++)
		k[i] = (char *)malloc(sizeof(char) * l);
	for (i = 0; i < h; i++) //标记数组和轨迹数组赋值0
	{
		for (j = 0; j < l; j++)
		{
			mark[i][j] = 0;
			k[i][j] = '.';
		}
	}
	printf("请设置迷宫的入口坐标:");
	scanf("%d%d", &r, &c);
	printf("请输入迷宫的出口坐标:");
	scanf("%d%d", &R, &C);
	printf("开始创建迷宫:\n");
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < l; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	return 0;
}
int judge() //判断所处位置的下一个位置是否可以走
{
	int count;
	count = 0;
	if (a[r][c + 1] == 0 && mark[r][c + 1] == 0) //判断东方向是否可走
	{
		road.top++;						//堆栈进入下一个内存空间，用来记录位置
		c++;							//往东走一格，c加1即可
		road.data[road.top].row = r;	//堆栈记录行信息
		road.data[road.top].column = c; //堆栈记录列信息
		mark[r][c] = 1;					//标记这个位置的信息为1，为1说明这个位置到达过
	}
	else if (a[r + 1][c] == 0 && mark[r + 1][c] == 0) //判断南方向是否可走
	{
		road.top++;
		r++;
		road.data[road.top].row = r;
		road.data[road.top].column = c;
		mark[r][c] = 1;
	}
	else if (a[r][c - 1] == 0 && mark[r][c - 1] == 0) //判断西方向是否可走
	{
		road.top++;
		c--;
		road.data[road.top].row = r;
		road.data[road.top].column = c;
		mark[r][c] = 1;
	}
	else if (a[r - 1][c] == 0 && mark[r - 1][c] == 0) //判断北方向是否可走
	{
		road.top++;
		r--;
		road.data[road.top].row = r;
		road.data[road.top].column = c;
		mark[r][c] = 1;
	}
	else
		count = 1; //count=1用来判别该位置东南西北均不可走，不是1说明有方向可走
	return count;
}
int main()
{
	int i, j, Y, x, y;
	creatMaze();
	road.top = 0; //初始化堆栈，存入迷宫入口信息
	road.data[road.top].row = r;
	road.data[road.top].column = c;
	while (1)
	{
		Y = judge();
		if (Y != 1 && (r != R || c != C)) //四个方向有方向可走，并且现处位置满足行或列不等于出口数值
			continue;					  //满足条件继续执行如上步骤
		else if ((r != R || c != C) && Y == 1)
		{
			road.top--;					 //四个方向均不可走，堆栈就删除该 位置信息，退回到上一个位置
			r = road.data[road.top].row; //用堆栈上一个位置信息给现处位置赋值
			c = road.data[road.top].column;
		}
		else //剩下的条件就是现处位置等于出口位置，则跳出循环
			break;
	}
	printf("路线如图:\n");
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < l; j++)
		{
			for (x = 0; x <= road.top; x++)
				if (i == road.data[x].row && j == road.data[x].column) // 利用堆栈记录的位置信息，来给轨迹数组赋值
					k[i][j] = '*';
		}
	}
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < l; j++)
		{
			printf("%c ", k[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

// 迷宫加强版

// #include <stdio.h>
// #include <malloc.h>
// #include <windows.h>
// struct location //定义迷宫结构体
// {
// 	int row;
// 	int column;
// };
// struct stack //定义堆栈
// {
// 	location data[100]; //可以记录100个位置
// 	int top;
// };
// int h, l, R, C, r, c; //分别代表迷宫行、列、出口坐标、入口坐标
// int **a, **mark;	  //定义二维数组，分别代表迷宫数组，标记数组，轨迹数组
// char **k;
// stack road; // 定义一个迷宫堆栈，用来记录走过的位置信息
// int myR, myC;
// int creatMaze() //创建迷宫函数
// {
// 	int i, j;
// 	printf("请输入迷宫个的行数与列数:");
// 	scanf("%d%d", &h, &l);
// 	a = (int **)malloc(sizeof(int *) * h); //使用malloc申请二维数组空间
// 	for (i = 0; i < h; i++)
// 		a[i] = (int *)malloc(sizeof(int) * l);
// 	mark = (int **)malloc(sizeof(int *) * h);
// 	for (i = 0; i < h; i++)
// 		mark[i] = (int *)malloc(sizeof(int) * l);
// 	k = (char **)malloc(sizeof(char *) * h);
// 	for (i = 0; i < h; i++)
// 		k[i] = (char *)malloc(sizeof(char) * l);
// 	for (i = 0; i < h; i++) //标记数组和轨迹数组赋值0
// 	{
// 		for (j = 0; j < l; j++)
// 		{
// 			mark[i][j] = 0;
// 			k[i][j] = '.';
// 		}
// 	}
// 	printf("请设置迷宫的入口坐标:");
// 	scanf("%d%d", &r, &c);
// 	myR = r;
// 	myC = c;
// 	printf("请输入迷宫的出口坐标:");
// 	scanf("%d%d", &R, &C);
// 	printf("开始创建迷宫:\n");
// 	for (i = 0; i < h; i++)
// 	{
// 		for (j = 0; j < l; j++)
// 		{
// 			scanf("%d", &a[i][j]);
// 		}
// 	}
// 	return 0;
// }
// int judge() //判断所处位置的下一个位置是否可以走
// {
// 	int count;
// 	int flagEast = 1;
// 	int flagSouth = 1;
// 	int flagWest = 1;
// 	int flagNorth = 1;
// 	int flagOrder = 1; //一旦被修改为0说明四个方向中的某一个已经满足了条件
// 	count = 0;
// 	//printf("%d %d\n", r, c);
// 	if (c + 1 > l - 1) //判断东边的那一格会不会越界
// 		flagEast = 0;
// 	if (r + 1 > h - 1)
// 		flagSouth = 0;
// 	if (c - 1 < 0)
// 		flagWest = 0;
// 	if (r - 1 < 0)
// 		flagNorth = 0;
// 	if (flagEast == 1)
// 	{
// 		if (a[r][c + 1] == 0 && mark[r][c + 1] == 0) //判断东方向是否可走
// 		{
// 			road.top++;						//堆栈进入下一个内存空间，用来记录位置
// 			c++;							//往东走一格，c加1即可
// 			road.data[road.top].row = r;	//堆栈记录行信息
// 			road.data[road.top].column = c; //堆栈记录列信息
// 			mark[r][c] = 1;					//标记这个位置的信息为1，为1说明这个位置到达过
// 			flagOrder = 0;
// 		}
// 	}
// 	if (flagSouth == 1)
// 	{
// 		if (a[r + 1][c] == 0 && mark[r + 1][c] == 0 && flagOrder == 1) //判断南方向是否可走
// 		{
// 			road.top++;
// 			r++;
// 			road.data[road.top].row = r;
// 			road.data[road.top].column = c;
// 			mark[r][c] = 1;
// 			flagOrder = 0;
// 		}
// 	}
// 	if (flagWest == 1)
// 	{
// 		if (a[r][c - 1] == 0 && mark[r][c - 1] == 0 && flagOrder == 1) //判断西方向是否可走
// 		{
// 			road.top++;
// 			c--;
// 			road.data[road.top].row = r;
// 			road.data[road.top].column = c;
// 			mark[r][c] = 1;
// 			flagOrder = 0;
// 		}
// 	}
// 	if (flagNorth == 1)
// 	{
// 		if (a[r - 1][c] == 0 && mark[r - 1][c] == 0 && flagOrder == 1) //判断北方向是否可走
// 		{
// 			road.top++;
// 			r--;
// 			road.data[road.top].row = r;
// 			road.data[road.top].column = c;
// 			mark[r][c] = 1;
// 			flagOrder = 0;
// 		}
// 	}
// 	if (flagOrder == 1)
// 		count = 1; //count=1用来判别该位置东南西北均不可走，不是1说明有方向可走
// 	return count;
// }
// int main()
// {
// 	int i, j, Y, x, y;
// 	creatMaze();
// 	road.top = 0; //初始化堆栈，存入迷宫入口信息
// 	road.data[road.top].row = r;
// 	road.data[road.top].column = c;
// 	int myflag = 1;
// 	while (1)
// 	{
// 		Y = judge();
// 		//printf("%d %d %d %d %d",r, c,Y,myR,myC);
// 		if (Y != 1 && (r != R || c != C)) //四个方向有方向可走，并且现处位置满足行或列不等于出口数值
// 			continue;					  //满足条件继续执行如上步骤
// 		else if (((r == myR) && (c == myC)) && (Y == 1))
// 		{
// 			myflag = 0;
// 			break;
// 		}
// 		else if ((r != R || c != C) && Y == 1)
// 		{
// 			road.top--;					 //四个方向均不可走，堆栈就删除该 位置信息，退回到上一个位置
// 			r = road.data[road.top].row; //用堆栈上一个位置信息给现处位置赋值
// 			c = road.data[road.top].column;
// 		}
// 		else //剩下的条件就是现处位置等于出口位置，则跳出循环
// 			break;
// 	}
// 	if (myflag == 1)
// 	{
// 		printf("路线如图:\n");
// 		for (i = 0; i < h; i++)
// 		{
// 			for (j = 0; j < l; j++)
// 			{
// 				for (x = 0; x <= road.top; x++)
// 					if (i == road.data[x].row && j == road.data[x].column) // 利用堆栈记录的位置信息，来给轨迹数组赋值
// 						k[i][j] = '*';
// 			}
// 		}
// 		for (i = 0; i < h; i++)
// 		{
// 			for (j = 0; j < l; j++)
// 			{
// 				printf("%c ", k[i][j]);
// 			}
// 			printf("\n");
// 		}
// 		printf("%d\n", road.top);
// 	}
// 	else
// 	{
// 		printf("走不出去！");
// 	}
// 	system("pause");
// 	return 0;
// }
