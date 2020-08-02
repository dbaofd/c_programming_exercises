#include <stdio.h>
int main()
{
	int i, m, n, k = 0, a[100];
	printf("请输入数组元素的个数\n");
	scanf("%d", &m);
	printf("请输入数组元素\n");
	for (i = 0; i < m; i++)
		scanf("%d", &a[i]);
	printf("请输入要查找的元素\n");
	scanf("%d", &n);
	for (i = 0; i < m; i++)
		if (a[i] == n)
		{
			printf("输入的数的在数组中的序号是%-4d\n", i);
			k++;
		}
	if (k == 0)
		printf("数组中没有这个数%d\n", n);
	else
		printf("数组中有%d个%d\n", k, n);
	return 0;
}