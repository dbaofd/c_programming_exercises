#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;
struct BTreeNode
{
	char e;
	BTreeNode *left;
	BTreeNode *right;
};
typedef BTreeNode *BTree;
BTreeNode *createBTreeNode(char e)
{
	BTreeNode *nd = new BTreeNode;
	nd->e = e;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}
int findChar(const char *str, int s1, int s2, char c)
{
	if (!str || s2 < s1 || s1 < 0 || s2 >= strlen(str))
		return -1;
	for (int i = s1; i <= s2; i++)
	{
		if (str[i] == c)
			return i;
	}
	return -1;
}
BTreeNode *getRoot(char *pre, int p1, int p2, char *in, int i1, int i2)
{
	char rootCh = pre[p1];
	if (!pre || p2 < p1 || p1 < 0 || p2 >= strlen(pre) || !in || i2 < i1 || i1 < 0 || i2 >= strlen(in))
	{
		return NULL;
	}
	int tmp = findChar(in, i1, i2, rootCh);
	if (tmp < 0)
	{
		return NULL;
	}
	BTreeNode *nd = createBTreeNode(rootCh);
	nd->left = getRoot(pre, p1 + 1, p1 + tmp - i1, in, i1, tmp - 1);
	nd->right = getRoot(pre, p1 + tmp - i1 + 1, p2, in, tmp + 1, i2);
	return nd;
}
BTree createBTree(char *pre, char *in)
{
	if (!pre || !in)
		return NULL;
	return getRoot(pre, 0, strlen(pre) - 1, in, 0, strlen(in) - 1);
}
void printPostOrder(BTree t)
{
	if (!t)
		return;
	printPostOrder(t->left);
	printPostOrder(t->right);
	printf("%c", t->e);
}
int main()
{
	char preord[30], inord[30];
	while (~scanf("%s %s", preord, inord))
	{
		BTree t = createBTree(preord, inord);
		printPostOrder(t);
		cout << endl;
	}

	system("pause");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char ch;
	struct Node *left;
	struct Node *right;
} Node;

char mid[27];
char pre[27];
int n = -1;

void make_tree(int i, int j);

int main(void)
{
	int i, j, k;
	while (scanf("%s%s", pre, mid) == 2)
	{
		make_tree(0, strlen(pre) - 1);
		printf("\n");
		n = -1;
	}
	return 0;
}

void make_tree(int i, int j)
{
	int k;
	if (i > j)
		return;
	n++;
	for (k = i; k <= j; k++)
	{
		if (pre[n] == mid[k])
		{
			break;
		}
	}
	make_tree(i, k - 1);
	make_tree(k + 1, j);
	printf("%c", mid[k]);
}