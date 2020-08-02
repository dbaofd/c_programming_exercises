#include <stdio.h>
#include <Windows.h>
int jiafa(double a, double b, double c, double d)
{
	double e, f;
	if (b >= 0)
		printf("(%.1lf+%.1lfi) + ", a, b);
	else
		printf("(%.1lf%.1lfi) + ", a, b);
	if (d >= 0)
		printf("(%.1lf+%.1lfi) = ", c, d);
	else
		printf("(%.1lf%.1lfi) = ", c, d);
	e = a + c;
	f = b + d;
	if ((e < 0.05 && e > 0) || (e < 0 && e > -0.05)) //实部虚部的绝对值判断是否小于0.05.方便保留一位小数位数时清零
		e = 0;
	if ((f < 0.05 && f > 0) || (f < 0 && f > -0.05))
		f = 0;
	if (e == 0 && f == 0)
		printf("0.0\n");
	else if (e == 0 && f != 0)
		printf("%.1lfi\n", f);
	else if (e != 0 && f == 0)
		printf("%.1lf\n", e);
	else
	{
		if (f >= 0)
			printf("%.1lf+%.1lfi\n", e, f);
		else
			printf("%.1lf%.1lfi\n", e, f);
	}
	return 0;
}
int jianfa(double a, double b, double c, double d)
{
	double e, f;
	if (b >= 0)
		printf("(%.1lf+%.1lfi) - ", a, b);
	else
		printf("(%.1lf%.1lfi) - ", a, b);
	if (d >= 0)
		printf("(%.1lf+%.1lfi) = ", c, d);
	else
		printf("(%.1lf%.1lfi) = ", c, d);
	e = a - c;
	f = b - d;
	if ((e < 0.05 && e > 0) || (e < 0 && e > -0.05)) //实部虚部的绝对值判断是否小于0.05.方便保留一位小数位数时清零
		e = 0;
	if ((f < 0.05 && f > 0) || (f < 0 && f > -0.05))
		f = 0;
	if (e == 0 && f == 0)
		printf("0.0\n");
	else if (e == 0 && f != 0)
		printf("%.1lfi\n", f);
	else if (e != 0 && f == 0)
		printf("%.1lf\n", e);
	else
	{
		if (f >= 0)
			printf("%.1lf+%.1lfi\n", e, f);
		else
			printf("%.1lf%.1lfi\n", e, f);
	}
	return 0;
}
int chengfa(double a, double b, double c, double d)
{
	double e, f;
	if (b >= 0)
		printf("(%.1lf+%.1lfi) * ", a, b);
	else
		printf("(%.1lf%.1lfi) * ", a, b);
	if (d >= 0)
		printf("(%.1lf+%.1lfi) = ", c, d);
	else
		printf("(%.1lf%.1lfi) = ", c, d);
	e = a * c - b * d;
	f = b * c + a * d;
	if ((e < 0.05 && e > 0) || (e < 0 && e > -0.05)) //实部虚部的绝对值判断是否小于0.05.方便保留一位小数位数时清零
		e = 0;
	if ((f < 0.05 && f > 0) || (f < 0 && f > -0.05))
		f = 0;
	if (e == 0 && f == 0)
		printf("0.0\n");
	else if (e == 0 && f != 0)
		printf("%.1lfi\n", f);
	else if (e != 0 && f == 0)
		printf("%.1lf\n", e);
	else
	{
		if (f >= 0)
			printf("%.1lf+%.1lfi\n", e, f);
		else
			printf("%.1lf%.1lfi\n", e, f);
	}
	return 0;
}
int chufa(double a, double b, double c, double d)
{
	double e, f;
	if (b >= 0)
		printf("(%.1lf+%.1lfi) / ", a, b);
	else
		printf("(%.1lf%.1lfi) / ", a, b); //虚部小于0就省去+号，题目的格式要求
	if (d >= 0)
		printf("(%.1lf+%.1lfi) = ", c, d);
	else
		printf("(%.1lf%.1lfi) = ", c, d);
	e = (a * c + b * d) / (c * c + d * d);
	f = (b * c - a * d) / (c * c + d * d);
	if ((e < 0.05 && e > 0) || (e < 0 && e > -0.05)) //实部虚部的绝对值判断是否小于0.05.方便保留一位小数位数时清零
		e = 0;
	if ((f < 0.05 && f > 0) || (f < 0 && f > -0.05))
		f = 0;
	if (e == 0 && f == 0)
		printf("0.0\n");
	else if (e == 0 && f != 0)
		printf("%.1lfi\n", f);
	else if (e != 0 && f == 0)
		printf("%.1lf\n", e);
	else
	{
		if (f >= 0)
			printf("%.1lf+%.1lfi\n", e, f);
		else
			printf("%.1lf%.1lfi\n", e, f);
	}
	return 0;
}
int main()
{
	double a, b, c, d, e, f;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	jiafa(a, b, c, d);
	jianfa(a, b, c, d);
	chengfa(a, b, c, d);
	chufa(a, b, c, d);
	system("pause");
	return 0;
}