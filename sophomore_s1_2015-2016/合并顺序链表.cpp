#include <iostream>
#include <Windows.h>
using namespace std;
#define NULL 0
typedef struct node
{
	int x;
	int y;
	node *next;
} node;
node *create(int N)
{
	node *head, *p1, *p2;
	p1 = p2 = new node[1];
	cin >> p1->x >> p1->y;
	head = p1;
	N--;
	while (N--)
	{
		p1 = new node[1];
		cin >> p1->x >> p1->y;
		p2->next = p1;
		p2 = p1;
	}
	p1->next = NULL;
	return head;
}
node *merge(node *l1, node *l2)
{
	node *p11, *rear, *incase, *p21, *p22;
	p11 = rear = l1;
	p21 = p22 = l2;

	while (1)
	{
		if (p11->y < p21->y)
		{
			rear = p11;
			p11 = p11->next;
		}
		else if (p11->y > p21->y)
		{

			if (p11->y == l1->y)
			{
				p21 = p21->next;
				p22->next = p11;
				l1 = p22;
				rear = p22;
				p22 = p21;
			}
			else
			{
				p21 = p21->next;
				p22->next = p11;
				rear->next = p22;
				incase = rear;
				rear = rear->next;
				p22 = p21;
			}
		}
		else
		{
			if (p11->x + p21->x == 0)
			{
				p21 = p21->next;
				p22 = p21;
				rear->next = p11->next;
				delete p11;
				p11 = rear->next;
			}
			else
			{
				p11->x = p11->x + p21->x;
				p21 = p21->next;
				delete (p22);
				p22 = p21;
				incase = rear;
				rear = rear->next;
				p11 = p11->next;
			}
		}
		if (p11 == NULL && p21 != NULL)
		{
			if (rear->y > p21->y)
			{
				incase->next = p21;
				p21->next = rear;
			}
			else if (rear->y < p21->y)
			{
				rear->next = p21;
			}
			else
			{
				if (rear->y + p21->y == 0)
					incase->next = NULL;
				else
				{
					p21->y = rear->y + p21->y; //由于list2长度有可能大于list1，而list1已到最后一个，故将相等项的值
					delete (rear);			   //给list2，然后rear指向它，这会方便很多
					incase->next = p21;
				}
			}
			break;
		}
		else if (p11 != NULL && p21 == NULL)
			break;
		else if (p11 == NULL && p21 == NULL)
			break;
	}
	return l1;
}
int main()
{
	node *List1, *List2, *head;
	int N1, N2;
	cin >> N1 >> N2;
	List1 = create(N1);

	List2 = create(N2);
	head = merge(List1, List2);
	while (head != NULL)
	{
		cout << head->x << " " << head->y << endl;
		head = head->next;
	}
	system("pause");
	return 0;
}