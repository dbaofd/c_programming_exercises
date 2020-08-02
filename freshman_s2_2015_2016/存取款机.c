#include <stdio.h>
#include <stdlib.h>
FILE *fp;	  /*宣告档案*/
struct member /*宣告结构*/
{
	int num;
	int ID;
	long int password;
	long int money;
};
int q, n; /*q:数据库内数据数,n:执行程序中第几笔数据*/
struct member guide[100];
int readfile(struct member guide[])
{
	int i = 0;
	int fileend = 0;								  /*fileend  宣告侦测是否已到档案结尾*/
	if ((fp = fopen("c://member2.txt", "r")) == NULL) /*看是否能开启档案*/
	{
		printf("can not open the file"); /*不行的话就显示"can not open the file" */
	}
	while (fileend == feof(fp)) /*feof函数检查是否已到档案结尾，*/
								/*若不是则传回0，若是则传回非0的值*/
	{
		i = i + 1;
		fscanf(fp, "%d", &guide[i].num);	   /*读取档案数据的num*/
		fscanf(fp, "%d", &guide[i].ID);		   /*读取档案数据的ID*/
		fscanf(fp, "%ld", &guide[i].password); /*读取档案数据的password*/
		fscanf(fp, "%ld", &guide[i].money);	   /*读取档案数据的money*/
	}
	return i;
}
int check_id(int id) /*子程序:确认数据库内账号是否存在*/
{
	for (n = 1; n <= q - 1; n++)
	{
		if (id == guide[n].ID) /*账号ID存在传回值1*/
		{
			return 1;
		}
	}
	return 0; /*账号ID不存在传回值0*/
}
int check_PW(long int PW) /*子程序;确认ID密码*/
{
	if (PW == guide[n].password)
		return 1; /*密码正确传回值1*/

	return 0; /*密码不正确传回值0*/
}
void withdraw() /*服务项目子程序*/
{
	long int x; /*x表示提款的金额数目*/
	int T;		/*T表示提款类别*/

	printf("\n1.存簿提款\n");
	printf("2.跨行提款\n");
	printf("3.查询结余\n");
	printf("4.存款\n");
	printf("请输入欲使用的服务类别(1~3):");
	scanf("%d", &T);
	if (T >= 1 && T <= 4) /*选择项目*/
	{
		switch (T)
		{
		case 1:
			printf("请输入欲提款金额:");
			scanf("%ld", &x);
			if (x <= guide[n].money)
			{
				guide[n].money = guide[n].money - x;
				printf("本次提款金额:%d元整\n", x);
				printf("您的余额还有%ld元整\n", guide[n].money);
				printf("谢谢您的使用，欢迎再度利用本局提款。");
			}
			else
				printf("输入金额错误,余额不足\n");
			break;

		case 2:
			printf("请输入欲提款金额:");
			scanf("%ld", &x);
			if (x <= guide[n].money - 6)
			{
				guide[n].money = guide[n].money - x - 6; /*跨行手续费6元*/
				printf("本次提款金额:%d元整\n", x);
				printf("您的余额还有%ld元整\n", guide[n].money);
				printf("谢谢您的使用，欢迎再度利用本局提款。");
			}
			else
				printf("输入金额错误,余额不足\n");
			break;
		case 3:
			x = 0;
			printf("本次提款金额:%d元整\n", x);
			printf("您的余额还有%ld元整\n", guide[n].money);
			printf("谢谢您的使用，欢迎再度利用本局提款。");
			break;
		case 4:
			printf("请输入欲存款的金额:");
			scanf("%ld", &x);
			guide[n].money = guide[n].money + x;
			printf("本次取款金额:%ld元整\n", x);
			printf("您的余额还有%ld元整\n", guide[n].money);
			printf("谢谢您的使用，欢迎再度利用本局提款。");
			break;
		}
	}
}
void writefile(struct member guide[]) /*写文件子程序*/
{
	int i;
	fp = fopen("c:\\member2.txt", "w"); /*开启member2.txt檔*/
	for (i = 1; i <= q - 1; i++)
	{

		fprintf(fp, "%d ", guide[i].num);								/*将矩阵的num写到档案*/
		fprintf(fp, "%d ", guide[i].ID);								/*将矩阵的ID写到档案*/
		fprintf(fp, "%ld ", guide[i].password);							/*将矩阵的password写到档案*/
		fprintf(fp, "%ld\n", guide[i].money); /*将矩阵的money写到档案*/ /*关闭档案*/
	}
	fclose(fp);
}
int main()
{
	long int PW = 0;
	int a, p, i, key; /*a:确认数据库账号和密码传回之值*/
	int id;
	int l, n, N;
	printf("1.注册\n2.登录\n");
	while (~scanf("%d", &key))
	{
		switch (key)
		{
		case 1:
			fp = fopen("c:\\member2.txt", "r");
			if ((fp = fopen("c:\\member2.txt", "r")) == NULL) /*看是否能开启档案*/
			{
				printf("can not open the file"); /*不行的话就显示"can not open the file" */
			};
			q = readfile(guide);
			fclose(fp);
			scanf("%d%d%ld%ld", &guide[q - 1].num, &guide[q - 1].ID, &guide[q - 1].password, &guide[q - 1].money);
			fp = fopen("c:\\member2.txt", "a");
			fprintf(fp, "%d ", guide[q - 1].num);
			fprintf(fp, "%d ", guide[q - 1].ID);
			fprintf(fp, "%ld ", guide[q - 1].password);
			fprintf(fp, "%ld\n", guide[q - 1].money);
			fclose(fp);
		case 2:
			fp = fopen("c:\\member2.txt", "r");
			if ((fp = fopen("c:\\member2.txt", "r")) == NULL) /*看是否能开启档案*/
			{
				printf("can not open the file"); /*不行的话就显示"can not open the file" */
			};
			q = readfile(guide); /*呼叫读文件子程序*/
			fclose(fp);			 /*关档*/
			printf("**********************************\n");
			printf("      欢迎光临此提款机\n");
			printf("**********************************\n");
			for (i = 1; i <= 3; i++)
			{
				printf("请输入提款卡ID:");
				scanf("%d", &id);
				a = check_id(id); /*确认数据库是否有此ID子程序*/
				if (a == 1)
					break;
				else
					printf("ID输入错误\n");
			}
			for (i = 1; i <= 3; i++)
			{
				printf("请输入密码:");
				scanf("%d", &PW);
				a = check_PW(PW); /*确认账号密码子程序*/
				if (a == 1)
					break;
				else
					printf("密码输入错误\n");
				if (i == 3)
				{
					printf("你的卡已经被怪兽吃掉啦!!\n"); /*输入密码错误三次*/
					printf("请带100万元向OSAKADO赎回");
					goto end; /*中断程序*/
				}
			}

			withdraw(); /*选择服务项目*/

			writefile(guide); /*呼叫写文件子程序*/
		end:
			printf("\n");
		}
		system("pause");
		system("cls");
		printf("1.注册\n2.登录\n");
	}
	return 0;
}
