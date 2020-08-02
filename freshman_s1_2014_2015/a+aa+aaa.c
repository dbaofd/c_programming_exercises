#include <stdio.h>
int main()
{
	int sn = 0, tn = 0, a, n, i = 1;
	scanf("%d %d", &a, &n);
	while (i <= n)
	{
		tn += a;
		sn += tn;
		a = a * 10;
		++i;
	}
	printf("a+aa+aaa+...=%d\n", sn);
	return 0;
}
// （也可以用for循环做）

// #include<stdio.h>
// int aaa(int a,int n)
// {
// 	int tn=0,sn=0,i=1;
//     while(i<=n)
// 	{
// 	tn+=a;
// 	sn+=tn;
// 	a=a*10;
// 	++i;
// 	}
// 	return sn;
// }
// int main()
// {
// 	int a,n;
// 	scanf("%d %d",&a,&n);
// 	printf("%d\n",aaa(a,n));
//     return 0;
// }

// 终极版
// #include<stdio.h>
// int main()
// {
// 	int a,i,j,n,s=0,t=0;
// 	scanf("%d%d",&a,&n);
// 	while(n>0)
// 	{
// 		t=t+a;
// 		a=a*10;
// 		if(n!=1)
// 		printf("%d+",t);
// 		else
// 		printf("%d=",t);
// 		s=s+t;
// 		n--;
// 	}
// 	printf("%d\n",s);
// 	return 0;
// }