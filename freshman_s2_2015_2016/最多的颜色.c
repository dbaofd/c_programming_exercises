#include <stdio.h>
#include <string.h>
int main()
{
	int N, i, j, count, k, max;
	char ch[1010][20];
	while (scanf("%d", &N) && N != 0)
	{
		max = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%s", &ch[i]);
		}
		for (i = 0; i < N; i++)
		{
			count = 1;
			for (j = i + 1; j < N; j++)
			{
				if (strcmp(ch[i], ch[j]) == 0)
					count++;
				if (max <= count)
				{
					max = count;
					k = i;
				}
			}
		}
		printf("%s\n", ch[k]);
	}
	return 0;
}