#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
typedef struct TNode *BinTree;
struct TNode
{
	int Data;
	BinTree Left;
	BinTree Right;
};
int flag;
BinTree Insert(BinTree BST, int X)
{
	if (!BST)
	{
		BST = (BinTree)malloc(sizeof(BinTree));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else
	{
		if (X < BST->Data)
			BST->Left = Insert(BST->Left, X);
		else if (X > BST->Data)
			BST->Right = Insert(BST->Right, X);
	}
	return BST;
}
BinTree judge(BinTree BST, BinTree T, int X)
{
	if (!BST)
	{
		BST = (BinTree)malloc(sizeof(BinTree));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
		if (T != NULL)
		{
			if (X != T->Data)
			{
				flag = 1;
			}
		}
	}
	else
	{
		if (X < BST->Data)
			BST->Left = judge(BST->Left, T->Left, X);
		else if (X > BST->Data)
			BST->Right = judge(BST->Right, T->Right, X);
	}
	return BST;
}

int main()
{
	int N, L;
	int i, j, k, a[10], b[10];
	BinTree BT = NULL, BST = NULL;
	while (~scanf("%d", &N) && N != 0)
	{
		scanf("%d", &L);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &a[i]);

			BT = Insert(BT, a[i]);
		}
		for (j = 0; j < L; j++)
		{
			flag = 0;
			for (i = 0; i < N; i++)
				scanf("%d", &b[i]);
			for (i = 0; i < N && flag == 0; i++)
				BST = judge(BST, BT, b[i]);
			if (flag == 1)
				printf("No\n");
			else
				printf("Yes\n");
			BST = NULL;
		}
		BT = NULL;
	}
	system("pause");
	return 0;
}