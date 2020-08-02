#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#define LEN sizeof(struct student)
#define len sizeof(struct POLYGON)
#define NULL 0
int FindNum()
{
	int i, sn = 0, tn = 0;
	for (i = 1; i <= 9; i++)
	{
		sn = (30 + i) * 6237;
		tn = (i * 10 + 3) * 3564;
		if (sn == tn)
		{
			printf("%d", i);
			break;
		}
	}
	printf("\n");
	return 0;
}
int FindRoot(int a, int b, int c)
{
	float X, D, E, X1, X2;
	scanf("%d %d %d", &a, &b, &c);
	D = b * b - 4 * a * c;
	if (D < 0)
		printf("此方程无解\n");
	else if (D == 0)
	{
		X = (-b) / (2 * a);
		printf("%.2f\n", X);
	}
	else
	{
		E = sqrt(D);
		X1 = (-b + E) / (2 * a);
		X2 = (-b - E) / (2 * a);
		printf("X1=%.2f X2=%.2f\n", X1, X2);
	}
	return 0;
}
int Detective()
{
	int i, j, k, s;
	for (i = 0; i <= 9; i++)
		for (j = 0; j <= 9; j++)
		{
			s = i * 1000 + i * 100 + j * 10 + j;
			for (k = 32; k <= 99; k++)
				if (s == k * k)
					printf("%d%d%d%d\n", i, i, j, j);
		}
	return 0;
}
int Bear()
{
	int a = 1, b, i;
	for (i = 0; i < 9; i++)
	{
		a = (a + 1) * 2;
		b = a;
	}
	printf("%d\n", b);
	return 0;
}
void Diamond()
{
	int i, j, k;
	for (i = 0; i < 6; i++)
	{
		for (j = 1; j < 6 - i; j++)
			printf(" ");
		for (k = 0; k < i * 2 + 1; k++)
			printf("*");
		printf("\n");
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j <= i; j++)
			printf(" ");
		for (k = 0; k < (5 - i) * 2 - 1; k++)
			printf("*");
		printf("\n");
	}
}
int Shoumaiji()
{
	int i, n, m = 1, t1 = 0, t2 = 0, t3 = 0, t4 = 0, a = 1, b;
	float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum = 0, k, j, p, r;
	while (1)
	{
		printf("**************************************\n");
		printf("1.价格查询系统         2.自动售卖系统 \n ");
		printf("**************************************\n");
		printf("请选择您要进行的操作\n");
		scanf("%d", &i);
		switch (i) //主switch，选择系统
		{
		case 1:
			printf("欢迎使用价格查询系统！\n");
			printf("**************************\n");
			printf("1.薯片\n");
			printf("2.爆米花\n");
			printf("3.巧克力\n");
			printf("4.可乐\n");
			printf("5.退出\n");
			printf("**************************\n");
			for (; m <= 5; m++) //控制查询次数上限
			{
				if (n == 5) //在没有达到查询上限就想要结束服务就选case5
					break;
				printf("请输入您要查询的食品的编号或者退出（查询5次后自动退出）\n");
				scanf("%d", &n);
				switch (n) //分switch,选择查询商品种类
				{
				case 1:
					printf("薯片的价格为3.0元\n");
					break;
				case 2:
					printf("爆米花的价格为2.0元\n");
					break;
				case 3:
					printf("巧克力的价格为4.0元\n");
					break;
				case 4:
					printf("可乐的价格为3.5元\n");
					break;
				case 5:
					printf("Thanks for using the system!\n");
					break;
				}
			}
			break; //跳出主switch,重新进入系统选择界面；
		case 2:
			printf("欢迎使用自动售卖系统！\n");
			printf("**************************\n");
			printf("1.薯片\n");
			printf("2.爆米花\n");
			printf("3.巧克力\n");
			printf("4.可乐\n");
			printf("5.结束购买\n");
			printf("**************************\n");
			for (; a <= 5; a++)
			{
				if (b == 5)
					break;
				printf("请输入你要购买的食品或退出\n");
				scanf("%d", &b);
				switch (b)
				{
				case 1:
					printf("薯片的价格为3.0元\n");
					printf("请输入你要购买的数量:");
					scanf("%d", &t1);
					sum1 = 3 * t1;
					break;
				case 2:
					printf("爆米花的价格为2.0元\n");
					printf("请输入你要购买的数量:");
					scanf("%d", &t2);
					sum2 = 2 * t2;
					break;
				case 3:
					printf("巧克力的价格为4.0元\n");
					printf("请输入你要购买的数量:");
					scanf("%d", &t3);
					sum3 = 4 * t3;
					break;
				case 4:
					printf("可乐的价格为3.5元\n");
					printf("请输入你要购买的数量:");
					scanf("%d", &t4);
					sum4 = 3.5 * t4;
					break;
				case 5:
					printf("谢谢购买！\n");
					break;
				}
			}
			sum = sum1 + sum2 + sum3 + sum4;
			printf("请付款%.2f元\n", sum);
			scanf("%f", &k);
			if (k > sum)
			{
				j = k - sum;
				printf("***************************************\n");
				printf("您的账单如下:\n");
				if (t1 != 0)
					printf("薯  片:3.0元 数量:%d,总计%.2f元\n", t1, sum1);
				if (t2 != 0)
					printf("爆米花:2.0元 数量:%d,总计%.2f元\n", t2, sum2);
				if (t3 != 0)
					printf("巧克力:4.0元 数量:%d,总计%.2f元\n", t3, sum3);
				if (t4 != 0)
					printf("可  乐:3.5元 数量:%d,总计%.2f元\n", t4, sum4);
				printf("***************************************\n");
				printf("找零%.2f元，欢迎下次光临！\n", j);
			}
			else if (k == sum)
			{
				printf("***************************************\n");
				printf("您的账单如下:\n");
				if (t1 != 0)
					printf("薯  片:3.0元 数量:%d,总计%.2f元\n", t1, sum1);
				if (t2 != 0)
					printf("爆米花:2.0元 数量:%d,总计%.2f元\n", t2, sum2);
				if (t3 != 0)
					printf("巧克力:4.0元 数量:%d,总计%.2f元\n", t3, sum3);
				if (t4 != 0)
					printf("可  乐:3.5元 数量:%d,总计%.2f元\n", t4, sum4);
				printf("***************************************\n");
				;
				printf("交易完成，欢迎下次光临！\n");
			}
			else
			{
				p = sum - k;
				printf("支付的现金不足，请再付%.2f元\n", p);
				scanf("%f", &r);
				if (r == p)
				{
					printf("***************************************\n");
					printf("您的账单如下:\n");
					if (t1 != 0)
						printf("薯  片:3.0元 数量:%d,总计%.2f元\n", t1, sum1);
					if (t2 != 0)
						printf("爆米花:2.0元 数量:%d,总计%.2f元\n", t2, sum2);
					if (t3 != 0)
						printf("巧克力:4.0元 数量:%d,总计%.2f元\n", t3, sum3);
					if (t4 != 0)
						printf("可  乐:3.5元 数量:%d,总计%.2f元\n", t4, sum4);
					printf("***************************************\n");
					printf("交易完成，欢迎下次光临！\n");
				}
			}
		}
		if (b == 5)
			break;
	}
	return 0;
}
struct score //成绩系统
{
	int a;
	int b;
	int c;
};
struct student
{
	long num;
	char name[10];
	struct score fen;
};
int N;
struct student *E;
int *A, *B, *C, *Y;
int formax(int a[], int N)
{
	int i, j, temp;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - 1 - i; j++)
			if (*(a + j) > *(a + j + 1))
			{
				temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}
	return *(a + N - 1);
}
int forIFa(int X, int N)
{
	int i;
	for (i = 0; i < N; i++)
		if (X == E[i].fen.a)
			printf("%ld %s %d\n", E[i].num, E[i].name, E[i].fen.a);
	return 0;
}
int forIFb(int X, int N)
{
	int i;
	for (i = 0; i < N; i++)
		if (X == E[i].fen.b)
			printf("%ld %s %d\n", E[i].num, E[i].name, E[i].fen.b);
	return 0;
}
int forIFc(int X, int N)
{
	int i;
	for (i = 0; i < N; i++)
		if (X == E[i].fen.c)
			printf("%ld %s %d\n", E[i].num, E[i].name, E[i].fen.c);
	return 0;
}
int forIFabc(int X, int N)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (X == (E[i].fen.a + E[i].fen.b + E[i].fen.c))
			printf("%ld %s %d %d %d %d\n", E[i].num, E[i].name, E[i].fen.a,
				   E[i].fen.b, E[i].fen.c, E[i].fen.a + E[i].fen.b + E[i].fen.c);
	}
	return 0;
}
int Gradesystem()
{
	int i;
	float suma = 0, sumb = 0, sumc = 0, sumy = 0;
	printf("请输入学生人数:");
	scanf("%d", &N);
	A = (int *)calloc(N, sizeof(int));
	B = (int *)calloc(N, sizeof(int));
	C = (int *)calloc(N, sizeof(int));
	Y = (int *)calloc(N, sizeof(int));
	E = (struct student *)calloc(N, sizeof(struct student));
	for (i = 0; i < N; i++)
	{
		scanf("%ld%s%d%d%d", &E[i].num, &E[i].name, &E[i].fen.a, &E[i].fen.b, &E[i].fen.c);
		A[i] = E[i].fen.a;
		B[i] = E[i].fen.b;
		C[i] = E[i].fen.c;
		Y[i] = A[i] + B[i] + C[i];
		suma += A[i];
		sumb += B[i];
		sumc += C[i];
		sumy += Y[i];
	}
	printf("A课程:average %.2f分数最高的同学信息\n", suma / N);
	forIFa(formax(A, N), N);
	printf("B课程:average %.2f分数最高的同学信息\n", sumb / N);
	forIFb(formax(B, N), N);
	printf("C课程:average %.2f分数最高的同学信息\n", sumc / N);
	forIFc(formax(C, N), N);
	printf("总分:average %.2f最高的同学信息\n", sumy / N);
	forIFabc(formax(Y, N), N);
	return 0;
} //成绩系统
struct POLYGON
{
	float x;
	float y;
	struct POLYGON *next;
};
struct POLYGON *CREAT(int N)
{
	struct POLYGON *p1, *p2, *head;
	int i, n = 0;
	head = NULL;
	for (i = 0; i < N - 1; i++)
	{
		n++;
		if (n == 1)
		{
			p1 = p2 = (struct POLYGON *)malloc(len);
			scanf("%f%f", &p1->x, &p1->y);
			head = p1;
		}
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct POLYGON *)malloc(len);
		scanf("%f%f", &p1->x, &p1->y);
	}
	p2->next = p1;
	p2 = p1;
	p1->next = head;
	return head;
}
float forS(float x, float y, struct POLYGON *p0)
{
	int i;
	float a, b, c, p, s = 0, sum = 0;
	struct POLYGON *p1, *p2;
	p1 = p2 = p0;
	for (i = 0; i < N; i++)
	{
		p2 = p1;
		p1 = p1->next;
		a = sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
		b = sqrt((p1->x - x) * (p1->x - x) + (p1->y - y) * (p1->y - y));
		c = sqrt((p2->x - x) * (p2->x - x) + (p2->y - y) * (p2->y - y));
		p = (a + b + c) / 2;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		sum += s;
	}
	return sum;
}
int Tuarea()
{
	struct POLYGON *p;
	int i;
	float m, n;
	printf("Enter the number of edges of the polygon:");
	scanf("%d", &N);
	printf("Let's creat the polygon\n");
	p = CREAT(N);
	scanf("%f%f", &m, &n);
	printf("The area of the polygon is:%.2f\n", forS(m, n, p));
	return 0;
}
int Houziwang()
{
	int monkey[1000] = {0}, count, N, i, j = 1, k;
	scanf("%d", &N);
	count = N;
	while (count != 1)
	{
		for (i = 0; i < N; i++)
		{
			if (monkey[i] == 1)
				continue;
			if (j == 3)
			{
				monkey[i] = 1;
				count--;
				j = 0;
			}
			j++;
		}
	}
	for (i = 0; i < N; i++)
		if (monkey[i] == 0)
			printf("第%d个猴子称王\n", i + 1);
	return 0;
}
int Rik()
{
	double a, b, c, d;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	if (a == d)
	{
		if (b == a && c == a)
			printf("R-Cross\n");
		else if (b <= a && c <= d)
			printf("R-Cross with Lower Shadow\n");
		else if (b >= a && c >= a)
			printf("R-Cross with Upper Shadow\n");
		else
			printf("R-Cross with Lower Shadow and Upper Shadow\n");
	}
	else if (a > d)
	{
		if (c >= d && c <= a && b >= d && b <= a)
			printf("BW-Solid\n");
		else if ((b > a || c > a) && b >= d && c >= d)
			printf("BW-Solid with Upper Shadow\n");
		else if ((b < d || c < d) && b <= a && c <= a)
			printf("BW-Solid with Lower Shadow\n");
		else
			printf("BW-Solid with Lower Shadow and Upper Shadow\n");
	}
	else
	{
		if (c >= a && c <= d && b >= a && b <= d)
			printf("R-Hollow\n");
		else if ((b > d || c > d) && b >= a && c >= a)
			printf("R-Hollow with Upper Shadow\n");
		else if ((b < a || c < a) && b <= d && c <= d)
			printf("R-Hollow with Lower Shadow\n");
		else
			printf("R-Hollow with Lower Shadow and Upper Shadow\n");
	}
	return 0;
}
int Jubuzuida()
{
	int row, clumn, i, j, count = 0;
	int a[100][100];
	scanf("%d %d", &row, &clumn);
	for (i = 0; i < row; i++)
		for (j = 0; j < clumn; j++)
			scanf("%d", &a[i][j]);
	for (i = 1; i < row - 1; i++)
		for (j = 1; j < clumn - 1; j++)
			if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1])
			{
				printf("%d %d %d\n", a[i][j], i + 1, j + 1);
				count++;
			}
	if (count == 0)
		printf("none %d %d\n", row, clumn);
	return 0;
}
int main()
{
	int m, e, f, g, i = 1;
	printf("*******************************\n");
	printf("1.FindNum\n");
	printf("2.FindFoot\n");
	printf("3.Detective\n");
	printf("4.Bear\n");
	printf("5.Diamond\n");
	printf("6.Shoumaiji\n");
	printf("7.Gradesystem\n");
	printf("8.Tuarea\n");
	printf("9.Houziwang\n");
	printf("10.Rik\n");
	printf("11.Jubuzuida\n");
	printf("12.Exit\n");
	printf("*******************************\n");
	while (~scanf("%d", &m))
	{
		switch (m)
		{
		case 1:
			FindNum();
			break;
		case 2:
			FindRoot(e, f, g);
			break;
		case 3:
			Detective();
			break;
		case 4:
			Bear();
			break;
		case 5:
			Diamond();
			break;
		case 6:
			Shoumaiji();
			break;
		case 7:
			Gradesystem();
			break;
		case 8:
			Tuarea();
			break;
		case 9:
			Houziwang();
			break;
		case 10:
			Rik();
			break;
		case 11:
			Jubuzuida();
			break;
		case 12:
			break;
		}
		printf("(按回车键清屏)\n");
		system("pause");
		system("CLS");
		printf("*******************************\n");
		printf("1.FindNum\n");
		printf("2.FindFoot\n");
		printf("3.Detective\n");
		printf("4.Bear\n");
		printf("5.Diamond\n");
		printf("6.Shoumaiji\n");
		printf("7.Gradesystem\n");
		printf("8.Tuarea\n");
		printf("9.Houziwang\n");
		printf("10.Rik\n");
		printf("11.Jubuzuida\n");
		printf("12.Exit\n");
		printf("*******************************\n");
	}
	return 0;
}