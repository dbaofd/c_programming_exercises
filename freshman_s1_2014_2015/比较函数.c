#include <stdio.h>
int bijiao(char x, char y)
{
	char z;
	z = x > y ? x : y;
	return z;
}
int main()
{

	int a, b, c, d;
	scanf("%c %c %c %c", &a, &b, &c, &d);
	printf("%c\n", bijiao(d, bijiao(c, bijiao(a, b))));
	return 0;
}