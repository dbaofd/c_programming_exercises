#include<stdio.h>
int main()
{
	int n,i=0;
	for(n=100;n<=200;n++)
	{
	  if(n%3!=0&&n%5!=0)
      {printf("%4d",n);
      i++;
      if(i%10==0)
      printf("\n");}
	}
	return 0;
}