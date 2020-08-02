
// #include<stdio.h>
// int main()
// {
// 	int m,k=0,i;
// 	scanf("%d",&m);
// 	for(i=2;i<m;i++)
// 	if(m%i==0)
// 	k++;
// 	if(k==0)
// 	printf("%d是素数\n",m);
// 	else
// 	printf("%d不是素数\n",m);
// 	return 0;
// }

//一定区间统计素数个数
#include <stdio.h>
#include <math.h>
int main()
{
	int m, n, i, j, k = 0, sum = 0, count = 0, flag;
	scanf("%d %d", &m, &n);
	for (i = m; i <= n; i++)
	{
		flag = 1;
		for (j = 2; j <= sqrt(i); j++) //（1）用sqrt可以减少程序运行时间
		{
			if (i % j == 0)
				flag = 0;
		}
		if (flag == 1 && i != 1) //1不是素数
		{
			sum += i;
			count++;
			k++;
			printf("%4d", i);
			if (k % 5 == 0 && i != n) //要满足i!=n，是因为当正好有四的倍数的个数的时候，不加这个条件就会额外执行一个换行。
				printf("\n");
		}
	}
	printf("\n");
	printf("sum = %d,count = %d\n", sum, count);
	return 0;
}
// （1)处有个需要特别注意如果要用srqt来减少程序运行时间，就必须要j<=sqrt(i),否则像25这样的数根号一下
// 等于5，而你却不取等号，j就取不到5，因而25就会得不到25%j==0的结论，便会将25当成素数，导致统计的失误。
// 如果非要用j<i,那就不需要加等号，因为每个数与自身除余都会是0。

// 函数方法
// #include<stdio.h>
// int sushu(int x)
// {
// 	int i,flag=1,j,k;
//     if(x==1)
//     	return 0;
//     for(i=2;i<x;i++)
//     	if(x%i==0)
//     		{
//     			flag=0;
//     			break;
//     		}
//     return flag;
// }
// int main()
// {
// 	int i,j,k,m,sum=0,count=0,n;
// 	scanf("%d %d",&m,&n);
// 	for(i=m;i<=n;i++)
// 		if(sushu(i)==1)
//         {
//         	sum+=i;
//         	count++;
//         	printf("%3d",i);
// 			k++;
// 			if(k%5==0)
// 			printf("\n");
//         }
//     printf("%d %d\n",sum,count);
//     return 0;
// }