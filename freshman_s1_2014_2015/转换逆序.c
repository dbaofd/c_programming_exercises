#include<stdio.h>
int main()
{
	int a[9],i;
	for(i=0;i<9;i++)
	a[i]=i+1;
	printf("原数列为:\n");
	for(i=0;i<9;i++)
	printf("%d",a[i]);
	printf("\n");
	printf("处理过后的数列为:\n");
	for(i=8;i>=0;i--)
	printf("%d",a[i]);
	printf("\n");
	return 0;	
} 

字符串逆序输出方一
#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char a[100];
	gets(a);
	for(i=strlen(a)-1;i>=0;i--)
	printf("%c",a[i]);
	return 0;
}

方二
#include<stdio.h>

int main()
{
	int i,j;
	char a[100];
    for(i=0;(a[i]=getchar())!='\n';i++)
    ;
    for(j=i-1;j>=0;j--)
    printf("%c",a[j]);
	
	return 0;
}
