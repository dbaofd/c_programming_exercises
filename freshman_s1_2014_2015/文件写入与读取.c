#include <stdio.h>
#include <stdlib.h>
int main()
{
	char ch;
	FILE *bd;
	bd = fopen("c://bd002.txt", "w");
	if (bd == NULL)
	{
		printf("can not open this file\n");
		exit(0);
	}
	while ((ch = getchar()) != '\n')
		fputc(ch, bd);
	if (fclose(bd) == 0)
		printf("OK!\n");
	else
		printf("file close error\n");
	bd = fopen("c://bd002.txt", "a");
	if (bd == NULL)
	{
		printf("can not open this file\n");
		exit(0);
	}
	while ((ch = getchar()) != '\n')
		fputc(ch, bd);
	if (fclose(bd) == 0)
		printf("OK!\n");
	else
		printf("file close error\n");
	bd = fopen("c://bd002.txt", "r");
	if (bd == NULL)
	{
		printf("can not open this file\n");
		exit(0);
	}
	while (!feof(bd))
	{
		ch = fgetc(bd);
		putchar(ch);
	}
	if (fclose(bd) == 0)
		printf("OK!\n");
	else
		printf("file close error\n");
	return 0;
}
