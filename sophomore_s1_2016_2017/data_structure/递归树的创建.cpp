#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#define null 0
struct treenode
{
	int data;
	treenode *lchild;
	treenode *rchild;
};
treenode *createtree(treenode *t)
{
	int ch;
	scanf("%d", &ch);
	if (ch == -1)
		t = null;
	else
	{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = createtree(t->lchild);
		t->rchild = createtree(t->rchild);
	}
	return t;
}
int preorder(treenode *t) //先序遍历
{
	if (t)
	{
		printf("%d ", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
	return 0;
}
int postorder(treenode *t) //后序遍历
{
	if (t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%d ", t->data);
	}
	return 0;
}
int inorder(treenode *t) //中序遍历
{
	if (t)
	{
		inorder(t->lchild);
		printf("%d ", t->data);
		inorder(t->rchild);
	}
	return 0;
}
int main()
{
	treenode *t = null;
	t = createtree(t);
	printf("先序遍历:");
	preorder(t);
	printf("\n");
	printf("后序遍历:");
	postorder(t);
	printf("\n");
	printf("中序遍历:");
	inorder(t);
	system("pause");
	return 0;
}