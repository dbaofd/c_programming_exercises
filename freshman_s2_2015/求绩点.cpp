#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
double forAve()
{
	int a, b, c, d, e, f, g, h, i, j;
	double ave;
	cout << "请输入近代史成绩:";
	cin >> a;
	cout << "请输入英语成绩:";
	cin >> b;
	cout << "请输入微积分II成绩:";
	cin >> c;
	cout << "请输入物理II成绩:";
	cin >> d;
	cout << "请输入物理实验成绩:";
	cin >> e;
	cout << "请输入形势与政策I成绩:";
	cin >> f;
	cout << "请输入大学生职业规划成绩:";
	cin >> g;
	cout << "请输入离散数学成绩:";
	cin >> h;
	cout << "请输入体育II成绩:";
	cin >> i;
	cout << "请输入c程序实验成绩:";
	cin >> j;
	ave = (a * 2.5 + b * 4 + c * 5 + d * 2.5 + e + f + g * 0.5 + h * 3 + i + j) / 21.5;
	cout << "你的总分为:";
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << ave * 21.5 << endl;
	cout << "你的平均分为:";
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << ave << endl;
	return 0;
}
double forGpa()
{
	double a, b, c, d, e, f, g, h, i, j, gpa;
	cout << "请输入近代史绩点:";
	cin >> a;
	cout << "请输入英语绩点:";
	cin >> b;
	cout << "请输入微积分II绩点:";
	cin >> c;
	cout << "请输入物理II绩点:";
	cin >> d;
	cout << "请输入物理实验绩点:";
	cin >> e;
	cout << "请输入形势与政策I绩点:";
	cin >> f;
	cout << "请输入大学生职业规划绩点:";
	cin >> g;
	cout << "请输入离散数学绩点:";
	cin >> h;
	cout << "请输入体育II绩点:";
	cin >> i;
	cout << "请输入c程序实验绩点:";
	cin >> j;
	gpa = (a * 2.5 + b * 4 + c * 5 + d * 2.5 + e + f + g * 0.5 + h * 3 + i + j) / 21.5;
	cout << "你的加权绩点为:";
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << gpa << endl;
	return 0;
}
int main()
{
	int sle;
	cout << "1.求平均分" << endl
		 << "2.求加权绩点" << endl
		 << "3.退出" << endl;
	while (cin >> sle, sle != 3)
	{

		switch (sle)
		{
		case 1:
			forAve();
			break;
		case 2:
			forGpa();
			break;
		}
		system("PAUSE");
		system("CLS");
		cout << "1.求平均分" << endl
			 << "2.求加权绩点" << endl
			 << "3.退出" << endl;
	}
	return 0;
}