#include<stdio.h>
int main()
{
	int i,m,j,max=0,min=10,a[10];
	float sum=0;
	printf("请各位评委打分（分数在1到10分之间）\n");
	for(i=0;i<10;i++)
	 {scanf("%d",&a[i]);
	 if(a[i]>max)
	 max=a[i];
	 if(a[i]<min)
	 min=a[i];
	 sum+=a[i];
	 }
	 printf("选手的最终得分为%4f\n",(sum-min-max)/8);
	 return 0;
} 

#include<stdio.h>
int main()
{
	int i,n,s,m,max,low;
	while(~scanf("%d",&n))
	{
	     s=0;
		 max=0;
	     low=100;
		 for(i=0;i<n;i++)
	     {
		     scanf("%d",&m);
		     if(m>max)
		     max=m;
		     if(m<low)
		     low=m;
		     s+=m;
	     }
	     printf("%.2lf\n",(double)(s-max-low)/(n-2));
	}
	return 0;
} 