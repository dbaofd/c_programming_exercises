#include <iostream>

using namespace std;
int main()
{
	int T;
	int N;
	int maxsum = 0;
	int cmp;
	int temp;
	int a[100][100];
	cin >> T;
	for (int p = 0; p < T; p++)
	{
		cin >> N;
		maxsum = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i = 1; i < N; i++)
			for (int j = 0; j <= i; j++)
			{
				if (j == 0)
				{
					a[i][j] += a[i - 1][j];
				}
				else if (j == i)
				{
					a[i][j] += a[i - 1][j - 1];
					maxsum = a[i][j] > a[i][j - 1] ? a[i][j] : a[i][j - 1];
				}
				else
				{
					if (a[i - 1][j - 1] > a[i - 1][j])
						a[i][j] += a[i - 1][j - 1];
					else
						a[i][j] += a[i - 1][j];
					maxsum = a[i][j] > a[i][j - 1] ? a[i][j] : a[i][j - 1];
				}
			}
		for (int i = 0; i < N - 1; i++)
			for (int j = 0; j < N - 1 - i; j++)
				if (a[N - 1][j] < a[N - 1][j + 1])
				{
					temp = a[N - 1][j];
					a[N - 1][j] = a[N - 1][j + 1];
					a[N - 1][j + 1] = temp;
				}
		maxsum = a[N - 1][0];
		cout << maxsum << endl;
	}

	return 0;
}
