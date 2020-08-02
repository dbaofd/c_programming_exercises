#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct Node
{
	char data[100];
} node;
node n[100001];
int min, count;
int flag[100001];
int PUT(node n[])
{
	char ch[100];
	int i;
	scanf("%s %d", ch, &i);
	if (i <= min)
		min = i;
	strcpy(n[i].data, ch);
	flag[i] = 1;
	count++;
	return 0;
}
int GET(node n[])
{
	int j;
	if (count == 0)
	{
		printf("EMPTY QUEUE!\n");
		return 0;
	}
	count--;
	printf("%s\n", n[min].data);
	flag[min] = 0;
	for (j = min; j < 100001; j++)
	{
		if (flag[j] == 1)
		{
			min = j;
			break;
		}
	}
	return 0;
}
int main()
{
	int N;
	int i, j, k;
	count = 0;
	char commond[10];
	scanf("%d", &N);
	min = 100000;
	memset(flag, 0, sizeof(int) * 100001);
	for (i = 0; i < N; i++)
	{
		scanf("%s", commond);
		switch (commond[0])
		{
		case 'P':
			PUT(n);
			break;
		case 'G':
			GET(n);
			break;
		}
	}
	system("pause");
	return 0;
}
