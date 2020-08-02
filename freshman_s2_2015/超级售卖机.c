#include <stdio.h>
int main()
{
	int i, n, m = 1, t1 = 0, t2 = 0, t3 = 0, t4 = 0, a = 1, b;		   //定义变量 系统选择码  查询时的商品种类 查询次数控制量 薯片、爆米花、巧克力、可乐的数量 购买次数控制量 售卖时商品种类
	float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum = 0, k, j, p, r; //薯片，爆米花，巧克力，可乐的各自总价 所有购买的商品的总价 付款金额 找零金额 补付金额 二次付款金额
	while (1)														   //该无限循环终止的条件就是结束售卖服务按下case5所决定的
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
		if (b == 5) //这里对于m，n的不作要求，查询过价格按5退出查询系统或者查询满5次退出查询系统，为了实用，真正要关闭系统，结束
			//服务，则在售卖系统操作完成后方可结束，而售卖系统结束时必定会按5键结束购买，所以最后将b的值作为系统结束服务的指令。 break;
	}
	return 0;
}

// 本超级售卖系统集价格查询和自动售卖系统为一体，运用switch嵌套，while与for循环，if语句
// 	等知识。其中一个总的switch是用来提供系统选择，另外两个switch分别用于各自系统的程序需要，两个
// 		分switch分别位于一个for循环内，跳出for循环需要用if语句进行限制，另外跳出第一个for循
// 			环的n均为5，n为5不仅跳出分switch，而且跳出for循环，一跳出第一个for，就意味着跳出总的
// 				switch，随后进入底层审判，底层审判通过即跳出while，而此时为了退回系统选择界面，唯一
// 					方法就是让while循环继续，所以底层审判用if语句来约束，条件之一就是n不等于5才可跳出
// 						这样n只会等于5，所以跳不出while，这样就可以在你查询过商品价格后退出查询系统，再次
// 							进入系统选择界面选择自动售卖系统，继而保持了系统的实用性。