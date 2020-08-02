#include <stdio.h>
#include <string.h>
int main()
{
	char a[101];
	int i, j, word, count, m;

	while (gets(a))
	{
		word = 0;
		for (i = 0; i < strlen(a); i++)
		{
			if (a[i] == ' ')
				word = 0;
			else if (word == 0)
			{
				word = 1;
				a[i] = a[i] - 32;
			}
		}
		printf("%s\n", a);
	}
	return 0;
}
