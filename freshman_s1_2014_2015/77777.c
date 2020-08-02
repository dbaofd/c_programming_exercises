#include <stdio.h>
int main()
{
	int i, j, n = 7;
	while (n > 0)
	{
		for (i = 1; i <= (7 - n) / 2; i++)
			printf(" ");
		for (j = 1; j <= n; j++)
			printf("%d", n);
		printf("\n");
		n += -2;
	}
	return 0;
}

// 方法二
// #include<stdio.h>
// int main()
// {
// 	int i,j,k,m=7;
// 	for(m=7;m>0;m+=-2)
// 	  {for(j=1;j<=(7-m)/2;j++)
// 	   printf(" ");
// 	   for(k=1;k<=m;k++)
// 	   printf("%d",m);
// 	   printf("\n");
// 	  }
// 	  return 0;
// }