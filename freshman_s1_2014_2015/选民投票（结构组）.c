
#include<stdio.h>
#include<string.h>
struct houxuanren
{
	char name[20];
	int count;
};
int main()
{
	int i,j;
	char L_name[20];
	struct houxuanren leader[3]={{"sunyang",0},{"yeshiwen",0},{"yaoming",0}};
	printf("请各位开始投票\n");
	for(i=0;i<5;i++)
	{scanf("%s",&L_name);
	for(j=0;j<3;j++)
	if(strcmp(L_name,leader[j].name)==0)
	leader[j].count++;
	}
	for(i=0;i<3;i++)
	printf("%s  %d\n",leader[i].name,leader[i].count);
	return 0;
}