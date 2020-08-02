#include <iostream>
#include <windows.h>
#include <malloc.h>
#include <iomanip>
#define NULL 0
using namespace std;
struct grade
{
	double score;
	grade *next;
};
int main()
{
	int N, N1, n = 0;
	grade *p1, *p2, *head;
	head = NULL;
	cin >> N;
	N1 = N;
	while (1)
	{

		n++;
		N--;
		if (n == 1)
		{
			p1 = p2 = (struct grade *)malloc(sizeof(struct grade));
			cin >> p1->score;
			head = p1;
		}
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct grade *)malloc(sizeof(struct grade));
		cin >> p1->score;
		if (N == 1)
			break;
	}
	p2->next = p1;
	p1->next = NULL;
	p1 = head;
	double max = p1->score;
	double min = p1->score;
	double sum = p1->score;
	while (p1->next != NULL)
	{
		if ((p1->next->score) >= max)
			max = p1->next->score;
		else if ((p1->next->score) <= min)
			min = p1->next->score;
		sum += p1->next->score;
		p1 = p1->next;
	}
	cout << "average = " << setiosflags(ios::fixed) << setprecision(2) << sum / N1 << endl;
	cout << "max = " << setiosflags(ios::fixed) << setprecision(2) << max << endl;
	cout << "min = " << setiosflags(ios::fixed) << setprecision(2) << min << endl;
	system("pause");
	return 0;
}