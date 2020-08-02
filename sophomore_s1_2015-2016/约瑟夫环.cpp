#include<iostream>
#include<Windows.h>
#include<malloc.h>
using namespace std;
int main()
{
	int i=0, m, N,NUM,*a,j,k,count=1;
	cout << "请输入人数:";
	cin >> N;
	NUM = N;
	a = (int *)malloc(sizeof(int)*N);
	for (j = 0; j < N; j++)
	{
		a[j] = 0;
	}
	cout<<"请输入终止序号:";
	cin >> m;
	while (N != 1)
	{
		for (j = 0; j < NUM; j++)
		{
			if (a[j] == 1)
				continue;
			if (count == m)
			{
				a[j] = 1;
				count = 0;
				N--;//此处的N不能把它替换for里面的NUM，绝对不可以，因为N是动态的，动态的东西不要用在for里面
			}
			count++;
		}
	}
	for (j = 0; j < NUM; j++)
		if (a[j] == 0)
			cout << "最后一个是"<<j+1 << endl;
	system("pause");
	return 0;
}