#include<stdio.h>
int main()
{
	int i,j,k;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6-i;j++)
		printf(" ");
		for(k=0;k<=i;k++)
		printf(" *");
		printf("\n");	
	}
	 for(i=1;i<6;i++)
	{
		for(j=0;j<=i;j++)
		printf(" ");
		for(k=0;k<6-i;k++)
		printf(" *");
		printf("\n");	
	}

	return 0;
} 


超级1
#include<stdio.h>
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
    {
  	    for(j=1;j<n-i;j++)
		  printf(" ");
		for(k=1;k<=i*2+1;k++)
		printf("*");
		printf("\n");	
  	}
  		for(i=0;i<n-1;i++)
    {
  	    for(j=0;j<=i;j++)
		  printf(" ");
		for(k=1;k<=(n-1-i)*2-1;k++)
		printf("*");
		printf("\n");	
  	}
  	return 0;
}

超级2，最后不含空格
#include<stdio.h>
int main()
{
	int i,j,k,sum=0,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=1;j<n-i;j++)
		printf(" ");
		for(k=0;k<=i;k++)
		{if(sum!=0)
		printf(" ");
		printf("*");
		sum++;}	
		printf("\n");	
	}
		for(i=0;i<n-1;i++)
	{
		sum=0;
		for(j=0;j<=i;j++)
		printf(" ");
		for(k=0;k<n-1-i;k++)
		{if(sum!=0)
		printf(" ");
		printf("*");
		sum++;}	
		printf("\n");	
	}
	return 0;
}