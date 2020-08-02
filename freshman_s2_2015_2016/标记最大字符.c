#include <stdio.h>
#include <string.h>
int main()
{
	char a[101];
	int i, j, k, m;
	while (~scanf("%s", &a))
	{
		m = a[0];
		for (i = 0; i < strlen(a); i++)
		{
			m = m > a[i + 1] ? m : a[i + 1];
		}
		for (i = 0; i < strlen(a); i++)
		{
			if (a[i] == m)
				printf("%c(max)", a[i]);
			else
				printf("%c", a[i]);
		}
		printf("\n");
	}
	return 0;
}