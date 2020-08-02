//1.2/1+3/2+5/3+8/5+.
#include <stdio.h>
int main()
{
	int n;
	double t, k, i = 1, j = 2, s = 0;
	scanf("%d", &n);
	for (k = 0; k < n; k++)
	{
		s += j / i;
		t = i + j;
		i = j;
		j = t;
	}
	printf("%.2lf", s);
	return 0;
}
// 2.2/1+3/2+4/3+
// #include<stdio.h>
// int main()
// {
// 	int n;
// 	double t,k,i=1,j=2,s=0;
// 	scanf("%d",&n);
// 	for(k=0;k<n;k++)
// 	{s+=j/i;
// 	t=i+2;
// 	i=j;
// 	j=t;}
// 	printf("%.2lf",s);
// 	return 0;
// }

// 3.1-2/3+3/5-4/7+5/9-6/11+..
// #include<stdio.h>
// int main()
// {
// 	int N;
// 	double s1=0,s2=0,n1=1,n2=3,n3=2,n4=1,t1,t2,i,j;
// 	scanf("%d",&N);
// 	if(N%2==0)
// 	{
// 		for(i=0;i<N/2;i++)
// 		{
// 			s1+=n4/n1;
// 			n4=n4+2;
// 			n1=n1+4;
// 			s2+=n3/n2;
// 			n3=n3+2;
// 			n2=n2+4;
// 		}
// 		printf("%.3lf\n",s1-s2);
// 	}
// 	else
// 	{
// 		for(i=0;i<(N+1)/2;i++)
// 		{
// 			s1+=n4/n1;
// 			n4=n4+2;
// 			n1=n1+4;
// 		}
// 		for(j=0;j<(N-1)/2;j++)
// 		{
// 			s2+=n3/n2;
// 			n3=n3+2;
// 			n2=n2+4;
// 		}
// 		printf("%.3lf\n",s1-s2);
// 	}
// 	return 0;
// }
// 3.方二
// #include<stdio.h>
// int main()
// {
// 	int i,n;
// 	double s,j=1,t=1,k=3,p=2;
// 	scanf("%d",&n);
// 	for(i=1;i<=n;i++)
// 	{
// 		if(i%2!=0)
// 		{
//  	        s+=t/j;
// 			j=j+4;
// 			t=t+2;
// 		}
// 		else
// 		{
// 			s-=p/k;
// 			p=p+2;
// 			k=k+4;
// 		}
// 	}
// 	printf("sum = %.2lf\n",s);
// 	return 0;
// }
// 4.1！+2！+3！。。
// #include<stdio.h>
// int main()
// {
// 	int n,s=0,t=1,i;
// 	scanf("%d",&n);
// 	for(i=1;i<=n;i++)
// 	{t=t*i;
// 	s=s+t;}
// 	printf("%d\n",s);
// 	return 0;
// }

// 5.1-1/4+1/7-1/10+1/13..
// #include <stdio.h>

// int main(void)
// {
// 	int n,i;
// 	double sum=0;
// 	scanf("%d",&n);
// 	for(i=1;i<=n;i++)
// 	{
// 		if(i % 2 != 0)
// 			sum += 1.0/(1+3*(i-1));
// 		else
// 			sum -= 1.0/(1+3*(i-1));
// 	}
// 	printf("sum = %.3lf",sum);
// 	return 0;
// }
