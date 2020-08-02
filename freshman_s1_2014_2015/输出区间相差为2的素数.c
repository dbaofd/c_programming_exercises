#include<stdio.h>
#include<math.h> 
int main()
{
	int m,n,i,j,k,t=0,flag=1,a[100];
	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i++)
	{
         flag=1;
         if(i==1)
         	flag=0;
         for(j=2;j<=sqrt(i);j++)
         	if(i%j==0)
         		flag=0;
         if(flag==1)
         	{
         		a[t]=i;
         		t++;
         	}
  	}
  	for(i=0;i<t;i++)
  		for(j=0;j<t;j++)
  			if(a[i]-a[j]==2)
  				printf("(%d,%d) ",a[j],a[i]);
    return 0;
}