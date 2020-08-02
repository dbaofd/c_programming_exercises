#include <iostream>
#include <windows.h>
using namespace std;
struct student
{
	char name[10];
	long int birthday;
	char phonenum[20];
};
int main()
{
	int n;
	student *p, tmp;
	cin >> n;
	p = (struct student *)malloc(n * sizeof(struct student));
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].name >> p[i].birthday >> p[i].phonenum;
	}
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i; j < n - i - 1; j++)
		{
			if (p[j].birthday >= p[j + 1].birthday)
			{
				tmp = p[j + 1];
				p[j + 1] = p[j];
				p[j] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << p[i].name << " " << p[i].birthday << " " << p[i].phonenum << endl;
	}
	system("pause");
	return 0;
}