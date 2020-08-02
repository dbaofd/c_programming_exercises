#include<stdio.h>
int main()
{
    int i,j,k,t,n;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
    	for(j=0;j<=i;j++)
    		printf("*");
    	for(k=0;k<(n-1-i)*2;k++)
    		printf(" ");
    	for(j=0;j<=i;j++)
    		printf("*");
    	printf("\n");
    }
    for(j=0;j<2*n;j++)
    	printf("*");
    printf("\n");
    return 0;
}