#include <stdio.h>
#include <Windows.h>
typedef struct TNode *BinTree;
struct TNode
{
	int Data;
	BinTree Left;
	BinTree Right;
};
int a[1000];
int s;
int flag;
BinTree P;
int preorder(BinTree t) //先序遍历
{
	if (t)
	{
		//printf("%d ", t->Data);
		if (t->Data != a[s++])
			flag = 1;
		preorder(t->Left);
		preorder(t->Right);
	}
	return 0;
}
int postorder(BinTree t) //后序遍历
{
	if (t)
	{
		postorder(t->Left);
		postorder(t->Right);
		a[s++] = t->Data;
	}
	return 0;
}
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
		else if (X >= BST->Data)
			BST->Right = Insert(BST->Right, X);
	}
	return BST;
}
BinTree MirrorInsert(BinTree BST, int X) //创建镜像二叉树
{
	if (!BST)
	{
		BST = (BinTree)malloc(sizeof(BinTree));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else
	{
		if (X > BST->Data)
			BST->Left = MirrorInsert(BST->Left, X);
		else if (X <= BST->Data)
			BST->Right = MirrorInsert(BST->Right, X);
	}
	return BST;
}
int main()
{
	BinTree BT = NULL, T = NULL;
	int i, j, k, N;
	s = 0;
	flag = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		BT = Insert(BT, a[i]);
	}
	preorder(BT);
	s = 0;
	if (flag == 1)
	{
		flag = 0;
		for (i = 0; i < N; i++)
			T = MirrorInsert(T, a[i]);
		P = T;
		preorder(T);
		if (flag == 1)
			printf("NO\n");
		else
		{
			printf("YES\n");
			s = 0;
			postorder(T);
			for (i = 0; i < N; i++)
			{
				printf("%d", a[i]);
				if (i != N - 1)
					printf(" ");
				else
					printf("\n");
			}
		}
	}
	else
	{
		printf("YES\n");
		P = BT;
		s = 0;
		postorder(BT);
		for (i = 0; i < N; i++)
		{
			printf("%d", a[i]);
			if (i != N - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
	system("pause");
	return 0;
}
