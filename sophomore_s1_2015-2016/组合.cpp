#include <iostream>
#include <Windows.h>
using namespace std;
int a[1000];
void zuhe(int m, int k) //从m个元素中取出k个元素的组合
{
	int i, j;
	for (i = m; i >= k; i--)
	{
		a[k] = i; //最后一个位置的元素可以取m,m-1,m-2.....k
		if (k > 1)
			zuhe(i - 1, k - 1); //递归调用
		else
		{
			for (j = 1; j <= m; j++)
				printf("%d ", a[j]);
			printf("\n");
		}
	}
}
int main()
{
	int N, i, j, k, temp;

	int sum;
	int count = 0;
	while (cin >> N && N != 0)
	{
		for (i = 0; i < N; i++)
			cin >> a[i];
		for (i = 0; i < N - 1; i++)
			for (j = 0; j < N - 1 - i; j++)
				if (a[j] > a[j + 1])
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
		zuhe(N, 3);
		while (i >= 3 && count == 2)
		{
			sum = a[i - 1];
			count = 0;
			for (j = i - 2; j >= 0; j--)
			{
				sum += a[j];
				if (sum > a[i])
					sum -= a[j];
				else if (sum == a[i] && count == 0)
					sum -= a[j];
				else if (sum < a[i])
					count++;
				else if (sum == a[i] && count == 1)
					break;
			}
			if (count != 2)
				i--;
		}
		if (count == 2)
			cout << a[i];
		else
			cout << "no solution" << endl;
	}
	system("pause");
	return 0;
}
