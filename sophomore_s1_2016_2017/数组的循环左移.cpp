#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	int N, i, j, temp;
	;
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "请输入数组循环左移的位数:";
	cin >> N;
	for (i = 0; i < N; i++)
	{
		temp = a[0];
		for (j = 0; j < 10; j++)
		{
			if (j == 9)
				a[j] = temp;
			else
				a[j] = a[j + 1];
		}
	}
	for (i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
}