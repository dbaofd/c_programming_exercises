#include<stdio.h>
int main()
{
	int m=0,n=0;
	char ch;
	printf("请输入一串字符:\n");
	for(;(ch=getchar())!='\n';m++)
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	n++;
	printf("字符数为%d\n",m);
	printf("英文字符数为%d\n",n);
	return 0;
	
}
 
#include<stdio.h>
int main()
{
	int n,i,count;
	char ch;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		count=0;
		if(n==0)
		break;
		while((ch=getchar())!='\n')
		{
			if(ch>='0'&&ch<='9')
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}