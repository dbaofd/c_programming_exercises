#include <stdio.h>
int main()
{
	int large(int x, int y);
	int a[100], b[100], i, j, k = 0, s = 0, t = 0, N;
	scanf("%d", &N);
	printf("Enter array a\n");
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);
	printf("Enter array b\n");
	for (i = 0; i < N; i++)
		scanf("%d", &b[i]);
	printf("Let's compare a&b!\n");
	for (j = 0; j < N; j++)
	{
		if (large(a[j], b[j]) == 1)
			k++;
		else if (large(a[j], b[j]) == 0)
			t++;
		else
			s++;
	}
	printf("a[i]>b[i]:%dtimes\na[i]<b[i]:%dtimes\na[i]=b[i]:%dtimes\n", k, t, s);
	if (k > t)
		printf("a[i] is larger than b[i]\n");
	else if (k < t)
		printf("b[i] is larger than a[i]\n");
	else
		printf("a[i] is equal to b[i]\n");
	return 0;
}

int large(int x, int y)
{
	int flag = 0;
	if (x > y)
		flag = 1;
	else if (x == y)
		flag = -1;
	else
		flag = 0;
	return flag;
}
