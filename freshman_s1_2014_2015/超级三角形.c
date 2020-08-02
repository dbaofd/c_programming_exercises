#include<stdio.h>
int main()
{
	int i,j,k,sum=0;
	for(i=0;i<4;i++)
	{sum=0;
	for(k=0;k<i;k++)
	printf(" ");
	for(j=i;j<4;j++)
	{if(sum!=0)
	printf(" ");
	printf("*");
	sum++;}
	printf("\n");
	}
	return 0;
} 