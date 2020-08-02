#include<stdio.h>
int main()
{
	char ch;
	int word=0,i,num=0;
	while((ch=getchar())!='\n')
	{
		if(ch==' ')
			word=0;
		else if(word==0)
		{
			word=1;
			num++;
		}
	}
	printf("%d\n",num);
	return 0;
}