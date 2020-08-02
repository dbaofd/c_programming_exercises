//1.
#include <stdio.h>
int main()
{
	int *p, a[100];
	int i, j, k, n;
	scanf("%d", &n);
	p = a;
	for (i = 0; i < n; i++)
		scanf("%d", p++);
	for (p = a, i = 0; i < n; i++)
		printf("%d ", *p++);
	return 0;
}
// 2.
// #include<stdio.h>
// int main()
// {
// 	int *p,a[100];
// 	int i,j,k,n;
// 	scanf("%d",&n);
// 	p=a;
// 	for(i=0;i<n;i++)
// 	scanf("%d",p++);
// 	for(p=a,i=0;i<n;i++,p++)
// 	printf("%d ",*p);
// 	return 0;
// }
// 3.
// #include<stdio.h>
// int main()
// {
// 	int *p,a[100];
// 	int i,j,k,n;
// 	scanf("%d",&n);
// 	p=a;
// 	for(i=0;i<n;i++)
// 	scanf("%d",p++);
// 	for(p=a;p<a+n;i++,p++)
// 	printf("%d ",*p);
// 	return 0;
// }
// 4.
// #include<stdio.h>
// int main()
// {
// 	int a[100];
// 	int i,j,k,n;
// 	scanf("%d",&n);
// 	for(i=0;i<n;i++)
// 	scanf("%d",a+i);
// 	for(i=0;i<n;i++)
// 	printf("%d ",*(a+i));
// 	return 0;
// }
// 5.
// #include<stdio.h>
// int main()
// {
// 	int a[100],*p;
// 	int i,j,k,n;
// 	scanf("%d",&n);
// 	for(i=0,p=a;i<n;i++)
// 	scanf("%d",p++);
// 	for(i=0;i<n;i++)
// 	printf("%d ",*(a+i));
// 	return 0;
// }