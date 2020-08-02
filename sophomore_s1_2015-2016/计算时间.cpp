#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	int h, m, s, n;
	char ch1, ch2;
	cin >> h >> ch1 >> m >> ch2 >> s;
	cin >> n;
	if (s + n >= 60)
	{
		m += (s + n) / 60;
		s = (s + n) % 60;
		if (m >= 60)
		{
			h += m / 60;
			m = m % 60;
			if (h >= 24)
			{
				h = h % 24;
				if (h < 10)
					cout << "0" << h << ":";
				else
					cout << h << ":";
				if (m < 10)
					cout << "0" << m << ":";
				else
					cout << m << ":";
				if (s < 10)
					cout << "0" << s << endl;
				else
					cout << s << endl;
			}
			else
			{
				if (h < 10)
					cout << "0" << h << ":";
				else
					cout << h << ":";
				if (m < 10)
					cout << "0" << m << ":";
				else
					cout << m << ":";
				if (s < 10)
					cout << "0" << s << endl;
				else
					cout << s << endl;
			}
		}
		else
		{
			if (h < 10)
				cout << "0" << h << ":";
			else
				cout << h << ":";
			if (m < 10)
				cout << "0" << m << ":";
			else
				cout << m << ":";
			if (s < 10)
				cout << "0" << s << endl;
			else
				cout << s << endl;
		}
	}
	else
	{
		s = s + n;
		if (h < 10)
			cout << "0" << h << ":";
		else
			cout << h << ":";
		if (m < 10)
			cout << "0" << m << ":";
		else
			cout << m << ":";
		if (s < 10)
			cout << "0" << s << endl;
		else
			cout << s << endl;
	}
	system("pause");
	return 0;
}