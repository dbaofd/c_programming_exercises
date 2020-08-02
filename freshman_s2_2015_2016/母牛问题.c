//1 2 3 4 5 6 7 1 2 3 4 6 9 13

#include <iostream>
#include <windows.h>
	using namespace std;
int cal(int n)
{
	int i;
	if (n > 0, n < 5)
		return n;
	else
	{
		for (i = n; i > 0; i--)
			return cal(i - 3) + cal(i - 1);
	}
}
int main()
{
	int n, a[100], i, j, count, t, flag, sum;
	while (cin >> n, n != 0)
	{
		cout << cal(n) << endl;
	}
	system("pause");
	return 0;
}