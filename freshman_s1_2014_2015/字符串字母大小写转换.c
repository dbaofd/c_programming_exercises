#include <stdio.h>
int main()
{
	int i, k = 0;
	char ch, str[41];
	while ((ch = getchar()) != '#')
	{
		if (ch >= 'a' && ch <= 'z')
			ch -= 32;
		else if (ch >= 'A' && ch <= 'Z')
			ch += 32;
		str[k] = ch;
		k++;
	}
	str[k] = '\0';
	printf("%s\n", str);
	return 0;
}