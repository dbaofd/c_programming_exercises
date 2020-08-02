#include <iostream>
#include <Windows.h>
using namespace std;
#define MaxVertexNum 1000
#define INFINTY 65535
typedef int EdgeType;
typedef char VertexType;
typedef struct M
{
	VertexType Vertices[MaxVertexNum];
	EdgeType Edges[MaxVertexNum][MaxVertexNum];
	int vum;
	int eum;
} MGraph;								   //邻接矩阵
void CreateMGraph(MGraph *G, int N, int M) //邻接矩阵
{
	int i, j, k, w;
	G->vum = N;
	G->eum = M;
	for (i = 0; i < G->vum; i++) //初始化邻接矩阵
		for (j = 0; j < G->vum; j++)
			G->Edges[i][j] = 1000000;
	for (k = 0; k < G->eum; k++)
	{
		cin >> i >> j >> w;
		G->Edges[i - 1][j - 1] = w;
		G->Edges[j - 1][i - 1] = w;
	}
}
int FindMin(int LowCost[], int n, int *sum)
{
	int j, k, MinCost = 1000000;
	for (k = 0, j = 0; j < n; j++)
	{
		if (LowCost[j] && LowCost[j] < MinCost)
		{
			MinCost = LowCost[j];
			k = j;
		}
	}
	*sum += MinCost;
	return k;
}
void Prim(MGraph *G, int Parent[])
{
	int LowCost[MaxVertexNum];
	int i, j, k;
	int *sum = new int();
	*sum = 0;
	int flag = 1;
	for (i = 1; i < G->vum; i++)
	{
		LowCost[i] = G->Edges[0][i];
		Parent[i] = 0;
	}
	LowCost[0] = 0;
	Parent[0] = -1;
	for (i = 1; i < G->vum; i++)
	{
		k = FindMin(LowCost, G->vum, sum);
		if (k)
		{
			LowCost[k] = 0;
			for (j = 1; j < G->vum; j++)
				if (LowCost[j] && G->Edges[k][j] < LowCost[j])
				{
					LowCost[j] = G->Edges[k][j];
					Parent[j] = k;
				}
		}
		else
		{
			cout << "-1" << endl;
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		cout << *sum << endl;
}
int main()
{
	int N, M;
	cin >> N >> M;
	int i, j, k;
	int *Parent = new int[N];
	MGraph *G = new MGraph();
	CreateMGraph(G, N, M);
	Prim(G, Parent);
	system("pause");
	return 0;
}
