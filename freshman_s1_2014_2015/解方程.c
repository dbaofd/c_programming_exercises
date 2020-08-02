#include<stdio.h>
int main()
{
	int x,y,N,i=0;
	printf("请输入N(N<=10000)\n");
	scanf("%d",&N);
	for(x=1;x<=100;x++)
	  {for(y=1;y<=x;y++)
	  if(x*x+y*y==N)
	  {printf("%d %d",y,x);
	  printf("\n");
	  i=1;
	  }
	  }
	  if(i!=1)
	  printf("no solution\n");
    return 0;
}