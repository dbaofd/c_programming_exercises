#include <iostream>
#include <Windows.h>
using namespace std;
#define MAX 1300
#define infinity 1000000
int Graph[MAX][MAX];
int MaxEdge, MinEgde, Edge;
void init();
void creat(int m, int n);
void Cal(int n);
int main()
{
	int n, m;

	while (cin >> n >> m)
	{
		init();
		creat(m, n);
		Cal(n);
		if (Edge == 0)
			cout << "Error !" << endl;
		else
		{
			cout << "Edges=" << Edge << endl;
			cout << "MaxEdge=" << MaxEdge << endl;
			cout << "MinEdge=" << MinEgde << endl;
		}
	}
	system("pause");
	return 0;
}
void init()
{
	memset(Graph, -1, sizeof(Graph));
	Edge = 0;
	MinEgde = infinity;
	MaxEdge = 0;
}
void creat(int m, int n)
{
	int start, end, v;
	for (int i = 1; i <= m; i++)
	{
		cin >> start >> end >> v;
		if (start <= n && end <= n && start >= 1 && end >= 1)
		{
			Graph[start][end] = Graph[end][start] = v;
		}
	}
}
void Cal(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (Graph[i][j] != -1)
			{
				Edge++;
				if (Graph[i][j] > MaxEdge)
					MaxEdge = Graph[i][j];
				if (Graph[i][j] < MinEgde && Graph[i][j] >= 0)
				{
					MinEgde = Graph[i][j];
				}
			}
		}
	}
}