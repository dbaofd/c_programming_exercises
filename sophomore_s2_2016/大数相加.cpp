#include <iostream>
#include <string>
using namespace std;
string cal(string sA, string sB);
string myformat(string sC);
int main()
{
	string sA, sB, sC;
	while (cin >> sA >> sB)
	{
		sC = cal(sA, sB);
		sC = myformat(sC);
		cout << sC << endl;
	}
	return 0;
}
string cal(string sA, string sB)
{
	string Ret;
	string temp;
	int lenA, lenB, lenC;
	int sum, cf, i;
	lenA = sA.size();
	lenB = sB.size();
	if (lenA > lenB)
	{
		lenC = lenA;
		temp.resize(lenA - lenB, '0');
		sB = temp + sB;
	}
	else
	{
		lenC = lenB;
		temp.resize(lenB - lenA, '0');
		sA = temp + sA;
	}
	Ret.resize(lenC, '0');
	cf = 0;
	for (i = lenC - 1; i >= 0; i--)
	{
		sum = (sA[i] - '0') + (sB[i] - '0') + cf;
		cf = sum / 10;
		Ret[i] = (char)(sum % 10 + '0');
	}
	if (cf == 1)
	{
		Ret = '1' + Ret;
	}

	return Ret;
}
string myformat(string sC)
{
	string Ret;
	int i = 0;
	;
	while (i < sC.size() && sC[i] == 0)
	{
		i++;
	}
	if (i == sC.size())
		Ret = '0';
	else
	{
		Ret = sC.substr(i, sC.size() - i);
	}
	return Ret;
}
