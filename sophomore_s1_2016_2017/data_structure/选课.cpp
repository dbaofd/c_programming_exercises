#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include "algorithm"
using namespace std;
typedef struct Course
{
	int num;
	int numop;
	char name[40000][5];
} course;
int main()
{
	int N, K;

	cin >> N >> K;
	int *co = new int[K];
	char guest[40000][5];
	course *bao = new course[K];
	int i, j, k;
	for (i = 0; i < K; i++)
	{
		cin >> bao[i].num >> bao[i].numop;
		for (j = 0; j < bao[i].numop; j++)
			scanf("%s", bao[i].name[j]);
	}
	for (i = 0; i < N; i++)
		scanf("%s", guest[i]);
	for (i = 0; i < N; i++)
	{
		int n = 0;
		int count = 0;
		for (j = 0; j < K; j++)
			for (int k = 0; k < bao[j].numop; k++)
				if (strcmp(guest[i], bao[j].name[k]) == 0)
				{
					count++;
					co[n++] = bao[j].num;
					break;
				}
		sort(co, co + n);
		cout << guest[i] << " " << count << " ";
		for (int p = 0; p < n; p++)
		{
			cout << co[p];
			if (p != n - 1)
				cout << " ";
			else
				cout << endl;
		}
	}
	system("pause");
	return 0;
}
