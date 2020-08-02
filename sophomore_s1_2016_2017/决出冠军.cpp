// There are two components to a team's score. The first is the number of problems solved.
//  The second is penalty points, which reflects the amount of time and incorrect submissions
// made before the problem is solved. For each problem solved correctly, penalty points are

// charged equal to the time at which the problem was solved plus 20 minutes for each incorrect
//  submission. No penalty points are added for problems that are never solved.
// So if a team solved problem one on their second submission at twenty minutes, they are charged
// 40 penalty points. If they submit problem 2 three times, but do not solve it, they are charged
// no penalty points. If they submit problem 3 once and solve it at 120 minutes, they are charged
// 120 penalty points. Their total score is two problems solved with 160 penalty points.

// The winner is the team that solves the most problems. If teams tie for solving the most problems,
// then the winner is the team with the fewest penalty points.

// input
// 4
// Stars 2 20 5 0 4 190 3 220
// Rockets 5 180 1 0 2 0 3 100
// Penguins 1 15 3 120 1 300 4 0
// Marsupials 9 0 3 100 2 220 3 80

// output Penguins 3 475

#include <iostream>
#include <malloc.h>
#include <Windows.h>
using namespace std;
typedef struct node
{
	char name[30];
	int p1Sub;
	int p1Time;
	int p2Sub;
	int p2Time;
	int p3Sub;
	int p3Time;
	int p4Sub;
	int p4Time;
	int sum;
	int right;
} oppo;
int main()
{
	int N;
	cin >> N;
	oppo *peo = (oppo *)malloc(sizeof(oppo) * N);
	for (int i = 0; i < N; i++)
	{
		peo[i].sum = 0;
		peo[i].right = 0;
		cin >> peo[i].name >> peo[i].p1Sub >> peo[i].p1Time >> peo[i].p2Sub >> peo[i].p2Time >> peo[i].p3Sub >> peo[i].p3Time >> peo[i].p4Sub >> peo[i].p4Time;
		if (peo[i].p1Time != 0)
		{
			peo[i].sum += peo[i].p1Time + (peo[i].p1Sub - 1) * 20;
			peo[i].right++;
		}
		if (peo[i].p2Time != 0)
		{
			peo[i].sum += peo[i].p2Time + (peo[i].p2Sub - 1) * 20;
			peo[i].right++;
		}
		if (peo[i].p3Time != 0)
		{
			peo[i].sum += peo[i].p3Time + (peo[i].p3Sub - 1) * 20;
			peo[i].right++;
		}
		if (peo[i].p4Time != 0)
		{
			peo[i].sum += peo[i].p4Time + (peo[i].p4Sub - 1) * 20;
			peo[i].right++;
		}
	}
	int i, j;
	oppo temp;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - 1 - i; j++)
			if (peo[j].right < peo[j + 1].right)
			{
				temp = peo[j];
				peo[j] = peo[j + 1];
				peo[j + 1] = temp;
			}
	int m;
	for (i = 0; i < N; i++)
		if (peo[0].right != peo[i].right)
		{
			m = i;
			break;
		}
	for (i = 0; i < m - 1; i++)
		for (j = 0; j < m - 1 - i; j++)
			if (peo[j].sum > peo[j + 1].sum)
			{
				temp = peo[j];
				peo[j] = peo[j + 1];
				peo[j + 1] = temp;
			}
	cout << peo[0].name << " " << peo[0].right << " " << peo[0].sum << endl;
	system("pause");
	return 0;
}