#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#define NULL 0
struct treeNode
{
	int data;
	treeNode *lchild;
	treeNode *rchild;
};
treeNode *createTree(treeNode *T)
{
	int ch;
	scanf("%d", &ch);
	if (ch == -1)
		T = NULL;
	else
	{
		T = (treeNode *)malloc(sizeof(treeNode));
		T->data = ch;
		T->lchild = createTree(T->lchild);
		T->rchild = createTree(T->rchild);
	}
	return T;
}
int preorder(treeNode *T) //先序遍历
{
	if (T)
	{
		printf("%d ", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
	return 0;
}
int postorder(treeNode *T) //后序遍历
{
	if (T)
	{
		preorder(T->lchild);
		preorder(T->rchild);
		printf("%d ", T->data);
	}
	return 0;
}
int inorder(treeNode *T) //中序遍历
{
	if (T)
	{
		preorder(T->lchild);
		printf("%d ", T->data);
		preorder(T->rchild);
	}
	return 0;
}
int main()
{
	treeNode *T = NULL;
	T = createTree(T);
	preorder(T);
	printf("\n");
	postorder(T);
	printf("\n");
	inorder(T);
	system("pause");
	return 0;
}
