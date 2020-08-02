#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MaxTree 10 /* maximum number of nodes in a tree */
typedef int ElementType;
typedef struct TreeNode *Tree;
struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
};

Tree BuildTree() /* details omitted */
{
	int ch;
	Tree t = NULL;
	scanf("%d", &ch);
	if (ch == -1)
	{
		t = NULL;
	}
	else
	{
		t = (Tree)malloc(sizeof(Tree));
		t->Element = ch;
		t->Left = BuildTree();
		t->Right = BuildTree();
	}
	return t;
}
void PrintNode(Tree NodePtr)
{
	printf(" %d", NodePtr->Element);
}

void Level_order(Tree bt, void (*visit)(Tree ThisNode))
{
	Tree data[100];
	int rear, front;
	Tree t;
	if (!bt)
		return;
	rear = front = 0;
	data[front++] = bt;
	while (rear != front)
	{
		t = data[rear++];
		(*visit)(t);
		if (t->Left)
			data[front++] = t->Left;
		if (t->Right)
			data[front++] = t->Right;
	}
	printf("\n");
}

int main()
{
	Tree T = BuildTree();
	printf("Level-order:");
	Level_order(T, PrintNode);
	system("pause");
	return 0;
}