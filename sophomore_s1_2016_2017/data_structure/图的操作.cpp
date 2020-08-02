#include <iostream>
#include <Windows.h>
using namespace std;
#define MaxVertexNum 100
#define INFINTY 65535
typedef int EdgeType;
typedef char VertexType;
enum GraphType
{
	DG,
	UG,
	DN,
	UN
};
typedef struct EdgeN //边表
{
	EdgeType AdjV;
	struct EdgeN *next;
} EdgeNode;
typedef struct //顶点表
{
	VertexType vertex;
	EdgeNode *FirstEdge;
} VertexNode;
typedef struct //邻接表
{
	VertexNode ADjlist[MaxVertexNum];
	int vnm;
	int enm;
	enum GraphType GType;
} ALGraph;
void CreateALGraph(ALGraph *G, enum GraphType GType) //有向图（邻接表）
{
	int i, j, k;
	EdgeNode *edge;
	G->GType = DG;
	cout << "请输入顶点数和边数" << endl;
	cin >> G->vnm >> G->enm;
	cout << "请输入顶点信息" << endl;
	for (i = 0; i < G->vnm; i++)
	{
		cin >> G->ADjlist[i].vertex;
		G->ADjlist[i].FirstEdge = NULL;
	}
	cout << "请输入边的信息" << endl;
	for (k = 0; k < G->enm; k++)
	{
		cin >> i >> j;
		edge = new EdgeNode[1];
		edge->AdjV = j;
		edge->next = G->ADjlist[i].FirstEdge;
		G->ADjlist[i].FirstEdge = edge;
		if (GType == UG)
		{
			edge = new EdgeNode[1];
			edge->AdjV = i;
			edge->next = G->ADjlist[j].FirstEdge;
			G->ADjlist[j].FirstEdge = edge;
		}
	}
}
typedef struct
{
	VertexType Vertices[MaxVertexNum];
	EdgeType Edges[MaxVertexNum][MaxVertexNum];
	int vum;
	int eum;
	enum GraphType GType;
} MGraph;										   //邻接矩阵
void CreateMGraph(MGraph *G, enum GraphType GType) //邻接矩阵
{
	int i, j, k, w;
	G->GType = UN;
	cout << "请输入顶点数和边数" << endl;
	cin >> G->vum >> G->eum;
	cout << "请输入顶点信息" << endl;
	for (i = 0; i < G->vum; i++)
		cin >> G->Vertices[i];
	for (i = 0; i < G->vum; i++) //初始化邻接矩阵
		for (j = 0; j < G->vum; j++)
			G->Edges[i][j] = INFINITY;
	cout << "请输入每条边对应的两个顶点和权值，输入格式为 i j w" << endl;
	for (k = 0; k < G->eum; k++)
	{
		cin >> i >> j >> w;
		G->Edges[i][j] = w;
		if (GType == UN)
			G->Edges[j][i] = w;
	}
}
void printALGraph(ALGraph *G) //打印邻接表
{
	EdgeNode *M;
	for (int i = 0; i < G->vnm; i++)
	{
		cout << G->ADjlist[i].vertex << " ";
		M = G->ADjlist[i].FirstEdge;
		while (M != NULL)
		{
			cout << M->AdjV;
			M = M->next;
			if (M != NULL)
				cout << "->";
		}
		cout << endl;
	}
}
void printMGraph(MGraph *G)
{
	for (int i = 0; i < G->vum; i++)
	{
		for (int j = 0; j < G->vum; j++)
			cout << G->Edges[i][j] << " ";
		cout << endl;
	}
}
bool visited[MaxVertexNum]; //访问标记
//深度优先遍历
void DFS(ALGraph *G, int v) //访问邻接点
{
	EdgeNode *W;
	cout << G->ADjlist[v].vertex;
	visited[v] = true;
	for (W = G->ADjlist[v].FirstEdge; W; W = W->next)
		if (!visited[W->AdjV])
			DFS(G, W->AdjV);
}
void DFS_ALG(ALGraph *G) //将顶点表从位置0开始访问，沿途访问改点的邻点
{
	int i;
	for (i = 0; i < G->vnm; i++)
		visited[i] = false;
	for (i = 0; i < G->vnm; i++)
		if (!visited[i])
			DFS(G, i);
}
//广度优先遍历
typedef struct
{
	EdgeType Data[MaxVertexNum];
	int rear;
	int front;
} Queue;
void AddQ(Queue *q, int i)
{
	q->Data[q->front++] = i;
}
int DeleteQ(Queue *q)
{
	return q->Data[q->rear++];
}
int isempty(Queue *q)
{
	if (q->front == q->rear)
		return 1;
	return 0;
}
void BFS(ALGraph *G)
{
	Queue *q = new Queue[1];
	q->front = q->rear = 0; //初始化队列
	int i, v;
	EdgeNode *w;
	for (i = 0; i < G->vnm; i++)
		visited[i] = false;
	for (i = 0; i < G->vnm; i++)
		if (!visited[i])
		{
			visited[i] = true;
			cout << G->ADjlist[i].vertex;
			AddQ(q, i);
			while (!isempty(q))
			{
				v = DeleteQ(q);
				for (w = G->ADjlist[v].FirstEdge; w; w = w->next) //访问某个顶点表中的每个邻接点
					if (!visited[w->AdjV])						  //结束之后对每个邻接点所对应的顶点的每个邻接点再进行访问
					{
						visited[w->AdjV] = true;
						cout << G->ADjlist[w->AdjV].vertex;
						AddQ(q, w->AdjV);
					}
			}
		}
}
int main()
{
	int select, t;
	enum GraphType GType;
	ALGraph *G = new ALGraph[1];
	MGraph *g = new MGraph[1];
	cout << "1.有向图(DG)" << endl
		 << "2.无向图(UG)" << endl;
	cout << "3.有向网图(DN)" << endl
		 << "4.无向网图(UN)" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		CreateALGraph(G, DG);
		printALGraph(G);
		cout << endl
			 << "1.深度优先遍历" << endl
			 << "2.广度优先遍历" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			DFS_ALG(G);
			break;
		case 2:
			BFS(G);
			break;
		}
		cout << endl;
		break;
	case 2:
		CreateALGraph(G, UG);
		printALGraph(G);
		cout << endl
			 << "1.深度优先遍历" << endl
			 << "2.广度优先遍历" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			DFS_ALG(G);
			break;
		case 2:
			BFS(G);
			break;
		}
		cout << endl;
		break;
	case 3:
		CreateMGraph(g, DN);
		printMGraph(g);
		break;
	case 4:
		CreateMGraph(g, UN);
		printMGraph(g);
		break;
	}
	delete (G);
	delete (g);
	system("pause");
	return 0;
}
