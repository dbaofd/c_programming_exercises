#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
using namespace std;
int red()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	return 0;
}
int white()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	return 0;
}
double forAve()
{
	int a, b, c, d, e, f, g, h, i, j;
	double ave, ave1, avet;

	cout << "Please input the score of China Modern History :";
	red();
	cin >> a;
	white();
	cout << "Please input the score of College English II:";
	red();
	cin >> b;
	white();
	cout << "Please input the score of Calculus II(A):";
	red();
	cin >> c;
	white();
	cout << "Please input the score of College Physics II(B):";
	red();
	cin >> d;
	white();
	cout << "Please input the score of Physical Experiment of college:";
	red();
	cin >> e;
	white();
	cout << "Please input the score of Situation and Policy I:";
	red();
	cin >> f;
	white();
	cout << "Please input the score of Career Planning for College Students:";
	red();
	cin >> g;
	white();
	cout << "Please input the score of Discrete Mathematics:";
	red();
	cin >> h;
	white();
	cout << "Please input the score of PE(Billiards)I:";
	red();
	cin >> i;
	white();
	cout << "Please input the score of Comprehensive Training of Program Design in C :";
	red();
	cin >> j;
	white();
	cout << "Please input the Weighted Average Score of the last term:";
	red();
	cin >> ave1;
	ave = (a * 2.5 + b * 4 + c * 5 + d * 2.5 + e + f + g * 0.5 + h * 3 + i + j) / 21.5;
	avet = (ave * 21.5 + ave1 * 25) / 46.5;
	//cout<<"你的总分为:";
	//cout <<setiosflags(ios::fixed);
	//cout<<setprecision(2)<<ave*21.5<<endl;
	white();
	cout << "The Weighted Average Score u get in this term is :";
	red();
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << ave << endl;
	white();
	cout << "The Weighted Average Score of freshman year u get is :";
	red();
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << avet << endl;
	white();
	return 0;
}
double forGpa()
{
	double a, b, c, d, e, f, g, h, i, j, gpa, gpa1, gpat;
	cout << "Please input the gpa of China Modern History :";
	red();
	cin >> a;
	white();
	cout << "Please input the gpa of College English II:";
	red();
	cin >> b;
	white();
	cout << "Please input the gpa of Calculus II(A):";
	red();
	cin >> c;
	white();
	cout << "Please input the gpa of College Physics II(B):";
	red();
	cin >> d;
	white();
	cout << "Please input the gpa of Physical Experiment of college:";
	red();
	cin >> e;
	white();
	cout << "Please input the gpa of Situation and Policy I:";
	red();
	cin >> f;
	white();
	cout << "Please input the gpa of Career Planning for College Students:";
	red();
	cin >> g;
	white();
	cout << "Please input the gpa of Discrete Mathematics:";
	red();
	cin >> h;
	white();
	cout << "Please input the gpa of PE(Billiards)I:";
	red();
	cin >> i;
	white();
	cout << "Please input the gpa of Comprehensive Training of Program Design in C :";
	red();
	cin >> j;
	white();
	cout << "Please input the gpa of the last term:";
	red();
	cin >> gpa1;
	gpa = (a * 2.5 + b * 4 + c * 5 + d * 2.5 + e + f + g * 0.5 + h * 3 + i + j) / 21.5;
	gpat = (gpa * 21.5 + gpa1 * 25) / 46.5;
	white();
	cout << "The gpa u get in this term is :";
	red();
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << gpa << endl;
	white();
	cout << "The gpa u get in freshman year is :";
	red();
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << gpat << endl;
	white();
	return 0;
}
int main()
{
	int sle;
	cout << "1.Evaluate the Weighted Average Score" << endl
		 << "2.Evaluate the GPA" << endl
		 << "3.Exit" << endl;
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
		cout << "1.Evaluate the Weighted Average Score" << endl
			 << "2.Evaluate the GPA" << endl
			 << "3.Exit" << endl;
	}
	return 0;
}