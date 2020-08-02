#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct TNode
{
	char data;
	TNode *LeftChild;
	TNode *RightChild;
};
#define LEN sizeof(TNode)
#define NULL 0
void create(string post, string mid, struct TNode *Proot)
{
	string midL, midR, postL, postR;
	struct TNode *left, *right;
	int rootpos, len;
	char root;
	len = post.size();
	root = post[len - 1];
	rootpos = mid.find(root);
	Proot->data = root;
	Proot->LeftChild = NULL;
	Proot->RightChild = NULL;
	if (len > 1)
	{
		if (len - rootpos - 1 > 0)
		{ //右孩子存在
			postR = post.substr(rootpos, len - 1 - rootpos);
			midR = mid.substr(rootpos + 1, len - 1 - rootpos);
			right = (struct TNode *)malloc(LEN);
			Proot->RightChild = right;
			create(postR, midR, right);
		}
		if (rootpos > 0)
		{ //左孩子存在
			postL = post.substr(0, rootpos);
			midL = mid.substr(0, rootpos);
			left = (struct TNode *)malloc(LEN);
			Proot->LeftChild = left;
			create(postL, midL, left);
		}
	}
}
string getPre(struct TNode *Proot)
{
	string pre = "";
	if (Proot != NULL)
	{
		pre += Proot->data;
		pre += getPre(Proot->LeftChild);
		pre += getPre(Proot->RightChild);
	}
	return pre;
}
void deleteTree(struct TNode *Proot)
{
	if (Proot->LeftChild != NULL)
	{
		deleteTree(Proot->LeftChild);
		free(Proot->LeftChild);
		Proot->LeftChild = NULL;
	}
	if (Proot->RightChild != NULL)
	{
		deleteTree(Proot->RightChild);
		free(Proot->RightChild);
		Proot->RightChild = NULL;
	}
}
void print(string out)
{
	cout << out << endl;
}
int main()
{
	string post, pre, mid;
	struct TNode *Proot = NULL;
	while (cin >> post >> mid)
	{
		Proot = (struct TNode *)malloc(LEN);
		create(post, mid, Proot);
		pre = getPre(Proot);
		print(pre);
		deleteTree(Proot);
		free(Proot);
	}
	system("pause");
	return 0;
}
