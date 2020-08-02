#include<stdio.h> 
int main()
 {
 	int n,j,i,k,temp,a[100];
 	printf("请输入数组的元素个数\n");
 	scanf("%d",&n);
 	printf("请输入数组的元素\n");
 	for(i=0;i<n;i++)
 	scanf("%d",&a[i]);
 	for(i=0;i<=n-1;i++)
       {k=i;
       for(j=i+1;j<=n-1;j++)
       if(a[j]<a[k])
       k=j;
       if(k!=i)
       {
       	temp=a[i];
       	a[i]=a[k];
       	a[k]=temp;
       }
       }
       printf("将这个数组由小到大排列\n");
      	for(i=0;i<n;i++) 
      	printf("%5d",a[i]);
      	printf("\n");
   	return 0;
 }