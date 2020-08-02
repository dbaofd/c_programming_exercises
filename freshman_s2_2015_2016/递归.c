#include <stdio.h>
int a, b;
int fun(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else
		return (fun(n - 1) * a + fun(n - 2) * b) % 7;
}
int main()
{
	int n;
	while (~scanf("%d%d%d", &a, &b, &n))
	{
		if (a == 0 && b == 0 && n == 0)
			break;
		printf("%d\n", fun(n % 49));
	}
	return 0;
}