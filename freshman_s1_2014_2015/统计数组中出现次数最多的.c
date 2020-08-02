#include<stdio.h>
int main()
{
	int a[100],i,j,k,n,max,count[100]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
			for(j=i;j<n;j++)
			if(a[i]==a[j]&&j!=i)
			 count[i]++;
		max=0;
		j=0;
    for(i=0;i<n;i++)
           if(count[i]>max)
           	{
			   max=count[i];
			   j=i;
           	}
    printf("%d %d",a[j],max+1);
    return 0;
}