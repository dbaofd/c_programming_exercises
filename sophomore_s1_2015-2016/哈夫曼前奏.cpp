#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#define NULL 0
using namespace std;
struct store //存储字符以及其权值的结构体，为哈夫曼树做准备
{
	char ch;
	int weight;
	struct store *next;
};
store *head;
store *returnTr(char str[])
{
	int i, j = 0, k, flag; //j:链表节点的个数;flag:标记是否在节点的数据中找到相同的字符
	store *p1, *p2, *p3;
	head = p1 = p2 = p3 = (struct store *)malloc(sizeof(struct store));
	for (i = 0; i < strlen(str); i++)
	{
		if (i == 0) //i=0时，将字符串的首字符复制给链表头节点的ch
		{
			head->ch = str[0];
			head->weight = 0; //权值先初始化，这里既然出现了一次这个字符，权值为何是0？是由于下面i=0时权值还是会自加一次
			p1 = p2 = head;	  //head刚刚得到了数据赋值，将其数据给p1，p2
		}
		flag = 0;				 //由于字符串中每个字符都要进行链表的遍历比对，所以这个flag每次作用结束都要重新归零，方便下一个字符的标记
		p3 = head;				 //由于是链表遍历，每一次遍历结束后p3的数据都会发生变化，所以每次遍历开始重置p3数据
		for (k = 0; k <= j; k++) //j在这里是动态变化的，j+1是节点数量，遍历就是要访问每个节点
		{
			if (str[i] == p3->ch) //如果字符串中的字符和链表当中的ch有一致的话，该节点的权值自加
			{
				p3->weight++;
				flag = 1; //标记在链表节点的ch中找到一样的
				break;
			}
			p3 = p3->next;
		}
		if (flag == 0)
		{
			j++; //执行此语句说明这个字符是链表中没有的数据，所以需要将其加入
			p1 = (store *)malloc(sizeof(store));
			p1->ch = str[i];
			p1->weight = 1;
			p2->next = p1;
			p2 = p1;
		}
	}
	p1->next = NULL;
	p1 = head;
	return head;
}
int main()
{
	store *p1, *p2;
	int i, k, j, count = 0;
	store *node, temp;
	char str[100];
	cout << "请输入字符串" << endl;
	cin >> str;
	p1 = p2 = returnTr(str);
	while (p1 != NULL)
	{
		count++; //计算出节点数量，为了数组的大小
		p1 = p1->next;
	}
	node = (store *)malloc(sizeof(store) * count); //节省内存
	i = 0;
	while (p2 != NULL) //将链表的数据传给数组
	{
		node[i].weight = p2->weight;
		node[i].ch = p2->ch;
		i++;
		p2 = p2->next;
	}
	/*TEST for (i = 0; i < count; i++)
	{
		cout << node[i].ch << ":"<<node[i].weight<<endl;
	}*/
	for (i = 0; i < count - 1; i++)
		for (j = 0; j < count - i - 1; j++)
		{
			if (node[j].weight > node[j + 1].weight)
			{
				temp = node[j];
				node[j] = node[j + 1];
				node[j + 1] = temp;
			}
		}
	for (i = 0; i < count; i++)
	{
		cout << node[i].ch << ":" << node[i].weight << endl;
	}
	system("pause");
	return 0;
}