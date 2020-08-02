// 有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
// 找规律，其实就是斐波那契数列
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	int N, i, j, M, a[40] = {0, 1, 1};
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> M;
		for (j = 3; j <= M; j++)
		{
			a[j] = a[j - 1] + a[j - 2];
		}
		printf("%d\n", a[M]);
	}
	system("pause");
	return 0;
}