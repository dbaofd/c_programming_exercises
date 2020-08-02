#include <stdio.h>
#include <string.h>
int main()
{
	int i, j, K, N;
	char str[101][11] = {{0}}, temp[11];
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)
		scanf("%s", &str[i]);
	for (i = 0; i < K; i++)
		for (j = 0; j < N - 1 - i; j++)
			if (strcmp(str[j], str[j + 1]) > 0)
			{
				strcpy(temp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], temp);
			}
	for (i = 0; i < N; i++)
		printf("%s\n", str[i]);
	return 0;
}
