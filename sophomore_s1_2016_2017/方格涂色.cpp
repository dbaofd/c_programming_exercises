// 有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green) 三色涂每个格子，每格涂一色，
// 要求任何相邻的方格不能同色，且首尾两格也不同色．求全部的满足要求的涂法.注意这里的longlongint，
// 当达到50时数据是非常大的
#include <iostream>
#include <Windows.h>
#include <math.h>
	using namespace std;
int main()
{
	long long int N, i, way, a[52] = {0, 3, 6, 6};
	while (cin >> N)
	{
		if (N <= 3)
			cout << a[N] << endl;
		else
		{
			for (i = 4; i <= N; i++)
				a[i] = a[i - 1] + a[i - 2] * 2;
			cout << a[N] << endl;
		}
	}
	system("pause");
	return 0;
}