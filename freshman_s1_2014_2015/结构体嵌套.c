#include<stdio.h>
struct birthday
{
	int year;
	int month;
	int day;
} ;
struct xuanshou
{
	char name[20];
	int age;
	struct birthday bd;
};
int main()
{
	struct xuanshou leader[3]={{"sunyang",19,1990,7,9},
	{"baodong",19,1995,7,7},{"yeshiwen",16,1998,9,12}};
	int i;
	for(i=0;i<3;i++)
	printf("%s %d %d %d %d\n",leader[i].name,leader[i].age,
	leader[i].bd.year,leader[i].bd.month,leader[i].bd.day);
	return 0;
}