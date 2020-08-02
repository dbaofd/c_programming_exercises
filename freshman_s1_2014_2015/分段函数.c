#include <stdio.h>
#include <math.h>
double fenduan(double x)
{
	double y;
	if (x >= 0)
	{
		y = sqrt(x);
	}
	else
	{
		y = pow(x + 1, 2) + x * 2 + 1 / x;
	}
	return y;
}
int main()
{
	double x;
	scanf("%lf", &x);
	printf("f(%.2lf) = %.2lf\n", x, fenduan(x));
	return 0;
}