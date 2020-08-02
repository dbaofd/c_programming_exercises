#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree CreatBinTree() /* 实现细节忽略 */
{
	BinTree t = NULL;
	char th;
	cin >> th;
	if (th == '#')
		t = NULL;
	else
	{
		t = (BinTree)malloc(sizeof(BinTree));
		t->Data = th;
		t->Left = CreatBinTree();
		t->Right = CreatBinTree();
	}
	return t;
}
int GetHeight(BinTree BT)
{
	int hl, hr, maxh;
	if (BT)
	{
		hl = GetHeight(BT->Left);
		hr = GetHeight(BT->Right);
		maxh = hl > hr ? hl : hr;
		return maxh + 1;
	}
	else
		return 0;
}
void pfleaves(BinTree t) //打印叶节点
{
	if (t)
	{
		if (t->Left == NULL && t->Right == NULL)
			printf("%c ", t->Data);
		pfleaves(t->Left);
		pfleaves(t->Right);
	}
}
int main()
{
	BinTree BT = CreatBinTree();
	pfleaves(BT);
	printf("%d\n", GetHeight(BT));
	system("pause");
	return 0;
}
