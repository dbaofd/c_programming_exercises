#include <iostream>
#include <time.h>
#include <iomanip>
#include <string.h>
#include <windows.h>
using namespace std;
void printSt(char a[], bool flag)
{
	int i;
	for (i = 0; i < strlen(a); i++)
	{
		cout << a[i];
		Sleep(25);
	}
	cout << endl;
	if (flag) //布尔类型为真就清屏
	{
		system("pause");
		system("CLS");
	}
	else if (!flag) //为假就sleep一段时间
	{
		Sleep(400);
	}
}
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
int colorful(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	return 0;
}
int loveyou()
{
	char a1[50] = "Hi,Jing! Guess you wonder for what I do this.";
	char a2[55] = "The answer is right know,let me go ahead and tell you.";
	char a3[54] = "You know,everything happens for a reason.";
	char a4[80] = "The reason come from my heart just during these time,it doesn't come by chance.";
	char a5[59] = "Maybe you have known something cause you are a smart girl.";
	char a6[50] = "YEAH,I THINK I AM FALLING IN LOVE WITH YOU.";
	char a7[80] = "Don't say how straight I am,I just follow my heart ok? I can't wait to say so.";
	char a8[100] = "You may sense that everything is going on so quickly that you've lost your step.";
	char a9[100] = "You may feel that all of these happened in a flash and made you be at a loss,";
	char b1[100] = "But whatever,I can be the one there to be with you.";
	char b2[100] = "You may doubt my love is not true to you,cause we are poor in knowing with each other,";
	char b3[100] = "but I dare to say most real love start in this way,";
	char b4[50] = "and the truth is time will prove everything.";
	char b5[100] = "You impressed me most the first time I saw you in temporary classroom,";
	char b6[100] = "your good behavior during military training also makes me feel good to you,";
	char b7[100] = "the way you talk to me,your temperament ,your personality and really something else";
	char b8[50] = "contribute to my love to you.";
	char b9[100] = "My mentor told me that:'Don't let the love prevent you from keeping going in study,";
	char c1[100] = "finding a girl who can study with you is the best.'";
	char c2[100] = "Now I know that you are the right girl I'm looking for who has the belief to study well,";
	char c3[100] = "and the desire to be better.";
	char c4[100] = "You are kind of I like.";
	char c5[100] = "What's more,we do have many things in common just like you know.";
	char c6[100] = "We can help with each other and I trust the love will lead us to a better future.";
	char c7[20] = "GIVE ME A CHANCE.";
	char c8[100] = "I believe my feeling is all right,";
	char c9[100] = "the feeling you give to me is all right.";
	char d1[100] = "I think I deserve a try anyway whatever the result is,";
	char d2[100] = "at least I've tried without any pity left.";
	char d3[100] = "If it was failed,we are the friend still,";
	char d4[100] = "if it was successful,let's go to Mufan coffee to have a cup of cafe Americano。";
	char d5[100] = "It's your treat.";
	printSt(a1, 1);
	printSt(a2, 1);
	printSt(a3, 0);
	printSt(a4, 1);
	printSt(a5, 0);
	red();
	printSt(a6, 0);
	white();
	printSt(a7, 0);
	printSt(a8, 0);
	printSt(a9, 0);
	printSt(b1, 1);
	printSt(b2, 0);
	printSt(b3, 0);
	printSt(b4, 1);
	printSt(b5, 0);
	printSt(b6, 0);
	printSt(b7, 0);
	printSt(b8, 1);
	printSt(b9, 0);
	printSt(c1, 0);
	printSt(c2, 0);
	printSt(c3, 0);
	printSt(c4, 1);
	printSt(c5, 0);
	printSt(c6, 0);
	red();
	printSt(c7, 0);
	white();
	printSt(c8, 0);
	printSt(c9, 1);
	printSt(d1, 0);
	printSt(d2, 0);
	printSt(d3, 0);
	printSt(d4, 0);
	printSt(d5, 1);
	return 0;
}
int coutMylove()
{
	int i = 1;
	clock_t stop = 0, start = 0, t = 0;
	while (1)
	{
		start = clock();
		colorful(i);
		if (i == 15)
			i = 1; //回归起始色
		cout << "        ******                           "
			 << "         **************            ********" << endl;
		cout << "         **                              "
			 << "              **                  **    **" << endl;
		cout << "        **       **                      "
			 << "             **                  ********" << endl;
		cout << "       **       **                       "
			 << "            **                  **    **" << endl;
		cout << "      **       **                        "
			 << "      ************             ********" << endl;
		cout << "     **       **   *****  **   **  ******"
			 << "          **            ********    ********" << endl;
		cout << "    **       **  **   **  **  **  **    "
			 << "          **            **    **    **    **" << endl;
		cout << "   **       **  **   **   ** **  ****** "
			 << "         **            ********    ********" << endl;
		cout << "  **       **  **   **    ****  **      "
			 << "        **            **    **    **    **" << endl;
		cout << "******    **   *****      ***  *******  "
			 << "******************   ********    ********" << endl;
		i++;
		Sleep(100);
		stop = clock();
		t = (double)(stop - start + t);		  //记录打印很多次所用时间，超过限定时间就停止
		if (t / (double)CLOCKS_PER_SEC > 1.5) //超出预设时间就跳出循环
			break;
		system("CLS");
	}
	return 0;
}
int main()
{
	clock_t start, stop;
	start = clock();
	loveyou();
	coutMylove();
	white();
	stop = clock();
	cout << endl
		 << endl;
	cout << "本次表白用时: " << setiosflags(ios::fixed) << setprecision(2) << double(stop - start) / 1000 << "s" << endl;
	cout << "                                                                                          BY 鲍东" << endl;
	system("pause");
	return 0;
}