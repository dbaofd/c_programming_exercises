#include <iostream>
#include <Windows.h>
using namespace std;
typedef struct Su
{
	char name[20];
	double grade;
	double credit;
} subjects;
FILE *mygrade;
subjects my[200];
void updateGrade()
{
	char name[50];
	double grade;
	double credit;
	int n;
	mygrade = fopen("c:\\mygrade.txt", "a");
	cout << "请输入你想要更新的成绩的门数" << endl;
	cin >> n;
	cout << "名称 成绩 学分\n"
		 << endl;
	for (int i = 0; i < n; i++)
	{
		scanf("%s %lf %lf", name, &grade, &credit);
		fprintf(mygrade, "%s %lf %lf\n", name, grade, credit);
	}
	fclose(mygrade);
	cout << "更新完毕!" << endl;
}
int readGrade(subjects my[200])
{
	int fileend = 0;
	int i = 0;
	if ((mygrade = fopen("c:\\mygrade.txt", "r")) == NULL)
		cout << "无法打开文件" << endl;
	while (fileend == feof(mygrade))
	{
		fscanf(mygrade, "%s %lf %lf", my[i].name, &my[i].grade, &my[i].credit);
		i++;
	}
	return i;
}
void calforGpa(subjects my[200])
{
	int count = readGrade(my);
	int i;
	double sumgrade = 0;
	double sumcredit = 0;
	for (i = 0; i < count; i++)
	{
		sumgrade += (my[i].grade * my[i].credit);
		sumcredit += my[i].credit;
	}
	double ave = sumgrade / sumcredit;
	double gpa = 5 - (95 - ave) / 10;
	printf("均分:%.2lf\n", ave);
	printf("绩点:%.2lf\n", gpa);
}
void print(subjects my[200])
{
	int count = readGrade(my);
	cout << "科目/成绩/学分" << endl;
	for (int i = 0; i < count - 1; i++)
		cout << my[i].name << " " << my[i].grade << " " << my[i].credit << endl;
}
int main()
{

	int slect;
	cout << "1.更新成绩 2.均分绩点 3.打印成绩单 4.退出" << endl;
	while (cin >> slect, slect <= 4 && slect >= 1)
	{
		switch (slect)
		{
		case 1:
			updateGrade();
			break;
		case 2:
			calforGpa(my);
			break;
		case 3:
			print(my);
			break;
		}
	}
	system("pause");
	return 0;
}
