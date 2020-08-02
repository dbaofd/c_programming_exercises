#include<stdio.h>
int main()
{
	int n,y,r,t=0;
	char c1,c2;
	while(~scanf("%d%c%d%c%d",&n,&c1,&y,&c2,&r))
	{
		if(y==1)
		t=r;
		else if(y==2)
		t=31+r;
		else if(y==3)
		t=60+r;
		else if(y==4)
		t=91+r;
		else if(y==5)
		t=121+r;
		else if(y==6)
		t=152+r;
		else if(y==7)
		t=182+r;
		else if(y==8)
		t=213+r;
		else if(y==9)
		t=244+r;
		else if(y==10)
		t=274+r;
		else if(y==11)
		t=305+r;
		else 
		t=335+r;
		if(y==1||y==2)
		printf("%d\n",t);
		else
		{
		  if((n%100!=0&&n%4==0)||(n%400==0))
		  printf("%d\n",t);
		  else
		  printf("%d\n",t-1);
		}
	}
	return 0;
} 