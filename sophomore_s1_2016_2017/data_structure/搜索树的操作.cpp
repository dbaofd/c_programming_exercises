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
int DeleteQ(treenode *bt, int x) //删除节点
{
	treenode *t1, *T, *tmp, *pre;
	if (bt == null)
		cout << "空的搜索树!" << endl;
	while (bt)
	{
		if (x > bt->data)
		{
			pre = bt;
			bt = bt->rchild;
		}
		else if (x < bt->data)
		{
			pre = bt;
			bt = bt->lchild;
		}
		else
		{
			T = bt; //找到要删除的对象
			break;
		}
	}
	if (bt == null)
		cout << "没有找到要删除的对象!" << endl;
	else if (T->lchild && T->rchild) //两个孩子都有
	{

		t1 = T->lchild;					//被删除节点两个孩子都有，在他左子树中挑一个最大的或者在右子树中挑最小的，我选择了第一个方案
		if (!t1->lchild && !t1->rchild) //左子树只有根节点
		{
			T->data = t1->data;
			T->lchild = null;
			free(t1);
		}
		else if (!t1->rchild) //左子树根节点没有右孩子
		{
			T->data = t1->data;
			T->lchild = t1->lchild;
			free(t1);
		}
		else
		{
			while (t1->rchild) //t就是左子树的根节点
			{
				pre = t1;		 //记录最大左孩子的parent,在寻找对象时，pre已经被赋值，当此时的左子树只有一个根节点时，这个
				t1 = t1->rchild; //while循环没有执行
			}
			T->data = t1->data; //找到左子树最大值，将其覆盖要删除的节点
			if (t1->lchild)		//判断左子树中最大的孩子是否有左孩子（它一定没有右孩子，有的话他就不是最大的了）
				pre->rchild = t1->lchild;
			else
				pre->rchild = null;
			free(t1);
		}
	}
	else if (T->lchild || T->rchild) //要删除的节点只有一个孩子,这个“或“的条件范围比较广，要放在&&后面，不然总是执行这一步
	{
		if (T->lchild) //存在左子树
		{
			if (T->data > pre->data) //判断被删除的节点是左孩子还是右
				pre->rchild = T->lchild;
			else
				pre->lchild = T->lchild;
		}
		else //存在右子树
		{
			if (T->data > pre->data)
				pre->rchild = T->rchild;
			else
				pre->lchild = T->rchild;
		}
		free(T);
	}
	else //一个孩子都没有
	{
		if (T->data > pre->data) //pre是被删除节点的parent
			pre->rchild = null;
		else
			pre->lchild = null;
		free(T);
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