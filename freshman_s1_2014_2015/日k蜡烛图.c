// 股票价格涨跌趋势，常用蜡烛图技术中的K线图来表示，分为按日的日K线、按周的周K线、
// 按月的月K线等。以日K线为例，每天股票价格从开盘到收盘走完一天，对应一根蜡烛小图，
// 要表示四个价格：开盘价格Open（早上刚刚开始开盘买卖成交的第1笔价格）、收盘价格Close
// （下午收盘时最后一笔成交的价格）、中间的最高价High和最低价Low。

// 如果Close<Open，表示为“BW-Solid”（即“实心蓝白蜡烛”）；如果Close>Open，
// 表示为“R-Hollow”（即“空心红蜡烛”）；如果Open等于Close，则为“R-Cross”
// （即“十字红蜡烛”）。如果Low比Open和Close低，称为“Lower Shadow”（即“有下影线”），
// 如果High比Open和Close高，称为“Upper Shadow”（即“有上影线”）。请编程序，根据给定的
// 四个价格组合，判断当日的蜡烛是一根什么样的蜡烛。

// 输入格式：

// 输入在一行中给出4个正实数，分别对应Open、High、Low、Close，其间以空格分隔。

// 输出格式：

// 在一行中输出日K蜡烛的类型。如果有上、下影线，则在类型后加上“with 影线类型”。
// 如果两种影线都有，则输出“with Lower Shadow and Upper Shadow”。

// 代码如下：
#include <stdio.h>
int main()
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