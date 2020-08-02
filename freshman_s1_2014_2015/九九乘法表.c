#include <stdio.h>
int main()
{
      int i, j;
      for (i = 1; i <= 9; i++)
      {
            for (j = 1; j <= i; j++)
                  printf("%d*%d=%-3d", j, i, j * i);
            printf("\n");
      }
      return 0;
}

// #include<stdio.h>
// int main()
// {
// 	int i,j,N;
// 	scanf("%d",&N);
// 	for(i=1;i<=N;i++)
//       {for(j=1;j<=i;j++)
// 	  printf("%d*%d=%-4d",j,i,j*i);
// 	  printf("\n");
//       }
// 	  return 0;
// }