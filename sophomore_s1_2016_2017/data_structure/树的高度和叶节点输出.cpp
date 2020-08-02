#include <iostream>
#include <windows.h>
#include <malloc.h>
#define null 0
using namespace std;
struct treenode
{
	char data;
	treenode *lchild;
	treenode *rchild;
};
treenode *createtree()
{
	treenode *t = null;
	char t;
	cin >> t;
	if (t == '#')
		t = null;
	else
	{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = t;
		t->lchild = createtree();
		t->rchild = createtree();
	}
	return t;
}
void pfleaves(treenode *t) //打印叶节点
{
	if (t)
	{
		if (t->lchild == null && t->rchild == null)
			cout << t->data;
		pfleaves(t->lchild);
		pfleaves(t->rchild);
	}
}
int getheight(treenode *t)
{
	int hl, hr, maxh;
	if (t)
	{
		hl = getheight(t->lchild);
		hr = getheight(t->rchild);
		maxh = hl > hr ? hl : hr;
		return maxh + 1;
	}
	else
		return 0;
}
int main()
{
	treenode *bt = null;
	bt = createtree();
	pfleaves(bt);
	cout << endl;
	cout << getheight(bt);
	cout << endl;
	system("pause");
	return 0;
}