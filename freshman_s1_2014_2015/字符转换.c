#include <stdio.h>
int main()
{
	char a;
	int j, num = 0;
	for (j = 0; (a = getchar()) != '\n'; j++)
		if (a >= '0' && a <= '9')
			num = num * 10 + a - '0';
	printf("%d", num);
	return 0;
}