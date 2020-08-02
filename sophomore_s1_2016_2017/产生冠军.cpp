这题给我的教训就是，malloc不能用来动态申请string类型的变量，要用new
	这题的算法就是，用标记法标记输过的人，最后统计没输过的，有一个就说明能产生
#include <iostream>
#include <string>
#include <stdlib.h>
#include <malloc.h>
#include <Windows.h>
	using namespace std;
typedef struct xuanshou
{
	string name;
	int num;
} XS;
int main()
{
	int N, count;
	string a, b;
	while (cin >> N && N != 0)
	{
		XS *t = new XS[2 * N];
		count = 0;
		int flag = -1, fa, fb;
		for (int i = 0; i < N; i++)
		{
			fa = 0;
			fb = 0;
			if (i == 0)
			{
				cin >> a >> b;
				t[++flag].name = a;
				t[flag].num = 1;
				t[++flag].name = b;
				t[flag].num = 0;
			}
			else
			{
				cin >> a >> b;
				for (int j = 0; j <= flag; j++)
				{
					if (a == t[j].name)
					{
						fa = 1;
						continue;
					}
					if (b == t[j].name)
					{
						t[j].num = 0;
						fb = 1;
						continue;
					}
				}
				if (fa == 0)
				{
					t[++flag].name = a;
					t[flag].num = 1;
				}
				if (fb == 0)
				{
					t[++flag].name = b;
					t[flag].num = 0;
				}
			}
		}
		for (int i = 0; i <= flag; i++)
		{
			if (t[i].num == 1)
				count++;
		}
		if (count == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	system("pause");
	return 0;
}
