#include <stdio.h>
#include <string.h>
int main()
{
	int n, i, j, sumA, sumE, sumI, sumO, sumU;
	char ch;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		sumA = 0, sumE = 0, sumI = 0, sumO = 0, sumU = 0;
		for (; (ch = getchar()) != '\n';)
		{
			if (ch == 'a')
				sumA++;
			else if (ch == 'e')
				sumE++;
			else if (ch == 'i')
				sumI++;
			else if (ch == 'o')
				sumO++;
			else if (ch == 'u')
				sumU++;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", sumA, sumE, sumI, sumO, sumU);
		if (i != n - 1)
			printf("\n");
	}
	return 0;
}