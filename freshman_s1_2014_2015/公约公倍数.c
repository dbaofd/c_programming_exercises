#include <stdio.h>
int gongyue(int m, int n)
{
	int i;
	for (i = m; i >= 0; i--)
		if ((m % i == 0) && (n % i == 0))
			break;
	return i;
}
int gongbei(int m, int n, int h)
{
	h = gongyue(m, n);

	return m * n / h;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("最大公约数为%d\n", gongyue(a, b));
	printf("最小公倍数为%d\n", gongbei(a, b, gongyue(a, b)));
	return 0;
}