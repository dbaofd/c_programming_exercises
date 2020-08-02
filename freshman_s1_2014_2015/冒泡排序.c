#include <stdio.h>
int main()
{
	int n, j, i, temp, a[100];
	printf("请输入数组的元素个数\n");
	scanf("%d", &n);
	printf("请输入数组的元素\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	printf("将数组从小到大排序:\n");
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	return 0;
}
// #include<stdio.h>
// int main()
// {
// 	int N,K,i,j,temp,a[100];
// 	scanf("%d %d",N,K);
// 	for(i=0;i<N;i++)
// 	scanf("%d",&a[i]);
// 	for(i=0;i<K;i++)
// 	 for(j=0;j<K-i;j++)
// 	 if(a[j]>a[j+1])
// 	 {
//  	   temp=a[j];
// 	   a[j]=a[j+1];
// 	   a[j+1]=temp;
//  	}
//  	for(i=0;i<N;i++)
//  	printf("%d",a[i]);
//  	printf("\n");
//  	return 0;
// }

// #include<stdio.h>
//  int main()
//  {
//  	int N,K,j,i,temp,a[100];
//  	scanf("%d %d",&N,&K);
//  	for(i=0;i<N;i++)
//  	scanf("%d",&a[i]);
//  	for(i=0;i<K;i++)
//  	  for(j=0;j<K-i;j++)
//  	  if(a[j]>a[j+1])
//  	  {
//   	 	temp=a[j];
//   	 	a[j]=a[j+1];
//   	 	a[j+1]=temp;
//   	 }
//   	 for(i=0;i<N;i++)
//   	 printf("%d",a[i]);
//   return 0;
//  }

// 控制比较轮数，最后不能有空格
// #include<stdio.h>
// int main()
// {
// 	int i,N,j,k,temp,a[101];
// 	scanf("%d %d",&N,&k);
// 	for(i=0;i<N;i++)
// 	scanf("%d",&a[i]);
// 	for(i=0;i<k;i++)
// 	  for(j=0;j<N-1-i;j++)
// 	  if(a[j]>a[j+1])
// 	  {
//   		temp=a[j];
//   		a[j]=a[j+1];
//   		a[j+1]=temp;
// 	   }
//   	for(i=0;i<N-1;i++)
//       printf("%d ",a[i]);
//       printf("%d",a[N-1]);
//   	return 0;
// }

// for (i = 0; i < n - 1; i++)
// 		{
// 			for (j = 0; j < n - 1 - i; j++)
// 			{
// 				if (a[j][0] >= a[j + 1][0])
// 				{
// 					if (a[j][0] == a[j + 1][0])
// 					{
// 						if (a[j][1] > a[j + 1][1])
// 						{
// 							temp[j][1] = a[j][1];
// 							a[j][1] = a[j + 1][1];
// 							a[j + 1][1] = temp[j][1];
// 						}
// 					}
// 					else
// 					{
// 						temp[j][0] = a[j][0];
// 						a[j][0] = a[j + 1][0];
// 						a[j + 1][0] = temp[j][0];
// 						temp[j][1] = a[j][1];
// 						a[j][1] = a[j + 1][1];
// 						a[j + 1][1] = temp[j][1];
// 					}
// 				}
// 			}
// 		}
