#include <stdio.h>
#include <math.h>
int qiu(double a, double b, double c)
{
	double de, t, j, k;
	de = b * b - 4 * a * c;
	t = sqrt(de);
	if (de > 0)
		printf("%.2lf\n%.2lf", (-b + t) / (2 * a), (-b - t) / (2 * a));
	else if (de == 0)
		printf("%.2lf\n", -b / (2 * a));
	else
	{
		j = -b / (2 * a);
		t = sqrt(-de);
		k = t / (2 * a);
		if (b != 0)
			printf("%.2lf+%.2lfi\n%.2lf-%.2lfi\n", j, k, j, k);
		else
			printf("%.2lfi\n-%.2lfi\n", k, k);
	}
	return 0;
}
int main()
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a == 0 && b == 0 && c != 0)
		printf("Not An Equation\n");
	else if (a == 0 && b == 0 && c == 0)
		printf("Zero Equation\n");
	else if (a == 0 && b != 0)
	{
		if (c == 0)
			printf("0\n");
		else
			printf("%.2lf\n", -c / b);
	}
	else
	{
		qiu(a, b, c);
	}
	return 0;
}
