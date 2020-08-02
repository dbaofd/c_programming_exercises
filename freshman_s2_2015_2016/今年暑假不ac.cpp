// 作为球迷，一定想看尽量多的完整的比赛，当然，作为新时代的好青年，你一定还会看一些其它的节目，比如新闻联播（永远不要忘记关心国家大事）、非常6+7、超级女生，以及王小丫的《开心辞典》等等，假设你已经知道了所有你喜欢看的电视节目的转播时间表，你会合理安排吗？（目标是能看尽量多的完整节目）
// 输入数据包含多个测试实例，每个测试实例的第一行只有一个整数n(n<=100)，表示你喜欢看的节目的总数，然后是n行数据，每行包括两个数据Ti_s,Ti_e (1<=i<=n)，分别表示第i个节目的开始和结束时间，为了简化问题，每个时间都用一个正整数表示。n=0表示输入结束，不做处理。
#include <iostream>
#include <Windows.h>
#include <algorithm>
using namespace std;
int main()
{
	int n, j, i, count;
	int a[100][2];
	while (cin >> n)
	{
		if (n)
		{
			count = 1;
			for (i = 0; i < n; i++)
			{
				cin >> a[i][0];
				cin >> a[i][1];
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n - 1 - i; j++)
				{
					if (a[j][1] > a[j + 1][1])
					{
						swap(a[j][0], a[j + 1][0]);
						swap(a[j][1], a[j + 1][1]);
					}
				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 1; j < n; j++)
				{
					if (a[i][1] <= a[j][0])
					{
						count++;
						i = j;
					}
				}
			}
			cout << count << endl;
		}
	}
	system("pause");
	return 0;
}