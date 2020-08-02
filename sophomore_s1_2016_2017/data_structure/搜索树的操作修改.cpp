#include <iostream>
#include <windows.h>
#include <malloc.h>
#define null 0
using namespace std;
struct treenode
{
	int data;
	treenode *lchild;
	treenode *rchild;
};
treenode *creat() //先序创建树
{
	int ch;
	treenode *t = null;
	scanf("%d", &ch);
	if (ch == -1)
	{
		t = null;
	}
	else
	{
		t = (treenode *)malloc(sizeof(treenode));
		t->data = ch;
		t->lchild = creat();
		t->rchild = creat();
	}
	return t;
}
treenode *findd(int x, treenode *bt) //递归查找元素
{
	if (!bt)
		return null;
	if (x > bt->data)
		return findd(x, bt->rchild);
	else if (x < bt->data)
		return findd(x, bt->lchild);
	else
		return bt;
}
treenode *findf(int x, treenode *bt) //非递归查找元素
{
	while (bt)
	{
		if (x > bt->data)
			bt = bt->rchild;
		else if (x < bt->data)
			bt = bt->lchild;
		else
			return bt;
	}
	return null;
}
treenode *findmind(treenode *bt)
{
	if (!bt)
		return null;
	else if (!bt->lchild)
		return bt;
	else
		return findmind(bt->lchild);
}
treenode *findmaxd(treenode *bt)
{
	if (!bt)
		return null;
	else if (!bt->rchild)
		return bt;
	else
		return findmaxd(bt->rchild);
}
treenode *findminf(treenode *bt)
{
	if (!bt)
		return null;
	while (bt->lchild)
		bt = bt->lchild;
	return bt;
}
treenode *findmaxf(treenode *bt)
{
	if (!bt)
		return null;
	while (bt->rchild)
		bt = bt->rchild;
	return bt;
}
treenode *insert(treenode *bt, int x) //插入元素
{
	if (!bt)
	{
		bt = (treenode *)malloc(sizeof(treenode));
		bt->data = x;
		bt->lchild = bt->rchild = null;
	}
	else
	{
		if (x < bt->data)
			bt->lchild = insert(bt->lchild, x);
		else if (x > bt->data)
			bt->rchild = insert(bt->rchild, x);
		else
			cout << "x元素已经存在" << endl;
	}
	return bt;
}
treenode *DeleteQ(treenode *bt, int x) //删除节点
{
	treenode *tmp;
	if (!bt)
		cout << "要删除的元素未找到" << endl;
	else
	{
		if (x < bt->data)
			bt->lchild = DeleteQ(bt->lchild, x);
		else
		{
			if (x > bt->data)
				bt->rchild = DeleteQ(bt->rchild, x);
			else
			{
				if (bt->lchild && bt->rchild)
				{
					tmp = findminf(bt->rchild);
					bt->data = tmp->data;
					bt->rchild = DeleteQ(bt->rchild, bt->data);
				}
				else
				{
					tmp = bt;
					if (!bt->lchild)
						bt = bt->rchild;
					else if (!bt->rchild)
						bt = bt->lchild;
					free(tmp);
				}
			}
		}
	}
	return bt;
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
void title() //菜单
{
	cout << "1.递归查找元素" << endl
		 << "2.非递归查找元素" << endl
		 << "3.查找最大元素(非递归)" << endl;
	cout << "4.查找最小元素（非递归）" << endl
		 << "5.查找最大元素（递归）" << endl
		 << "6.查找最小元素（递归）" << endl;
	cout << "7.插入元素" << endl
		 << "8.删除元素" << endl
		 << "9.退出" << endl;
	;
}
int main()
{
	treenode *t1, *T, *t2;
	int element, i, x;
	cout << "请创建树:" << endl;
	t1 = T = creat();
	title();
	while (cin >> i && i != 9)
	{
		switch (i)
		{
		case 1:
			cout << "请输入要查找的元素:";
			cin >> element;
			t2 = findd(element, T);
			if (t2 == null)
				cout << "没有找到" << endl;
			else
				cout << t2->data << endl;
			break;
		case 2:
			cout << "请输入要查找的元素:";
			cin >> element;
			t2 = findf(element, T);
			if (t2 == null)
				cout << "没有找到" << endl;
			else
				cout << t2->data << endl;
			break;
		case 3:
			t2 = findmaxf(T);
			if (t2 == null)
				cout << "搜索树为空" << endl;
			else
				cout << t2->data << endl;
			break;
		case 4:
			t2 = findminf(T);
			if (t2 == null)
				cout << "搜索树为空" << endl;
			else
				cout << t2->data << endl;
			break;
		case 5:
			t2 = findmaxd(T);
			if (t2 == null)
				cout << "搜索树为空" << endl;
			else
				cout << t2->data << endl;
			break;
		case 6:
			t2 = findmind(T);
			if (t2 == null)
				cout << "搜索树为空" << endl;
			else
				cout << t2->data << endl;
			break;
		case 7:
			cout << "请输入要插入的数:";
			cin >> x;
			insert(T, x);
			cout << "中序遍历:";
			inorder(T);
			cout << endl;
			break;
		case 8:
			cout << "请输入要删除的元素:";
			cin >> x;
			DeleteQ(T, x);
			cout << "中序遍历:";
			inorder(t1);
			cout << endl;
		default:
			break;
		}
		system("pause");
		system("cls");

		title();
	}
	system("pause");
	return 0;
}
