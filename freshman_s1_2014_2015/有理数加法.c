// 在一行中按照“a/b”的格式输出两个有理数的和。
// 注意必须是该有理数的最简分数形式，若分母为1，则只输出分子。
// 输入1/3 1/6输出1/2     输入2/3 4/3输出2
#include <stdio.h>
int main()
{
	int a1, b1, a2, b2, i;
	double s, t;
	char c1, c2;
	scanf("%d%c%d %d%c%d", &a1, &c1, &b1, &a2, &c2, &b2);
	for (i = a1 * b2 + a2 * b1; i >= 0; i--)
		if ((a1 * b2 + a2 * b1) % i == 0 && (b1 * b2) % i == 0)
			break;
	if ((a1 * b2 + a2 * b1) % (b1 * b2) == 0)
		printf("%d\n", ((a1 * b2 + a2 * b1) / i) / ((b1 * b2) / i));
	else
		printf("%d/%d\n", (a1 * b2 + a2 * b1) / i, (b1 * b2) / i);
	return 0;
}

// 函数和结构体解决方案
// #include <stdio.h>
// int getNum(int a, int b)
// {
// 	int i;
// 	for(i=a>b?b:a;i>=1;i--)
// 	{
// 		if(a % i == 0 && b % i == 0)
// 		{
// 			return i;
// 		}
// 	}
// 	return 0;
// }
// int main()
// {
// 	struct fs{
// 	int fz;
// 	int fm;
// 	};
// 	struct fs r1, r2, res;
// 	int my;
// 	scanf("%d/%d %d/%d", &r1.fz, &r1.fm, &r2.fz, &r2.fm);
// 	res.fz = r1.fz * r2.fm + r2.fz * r1.fm;
// 	res.fm = r1.fm * r2.fm;
// 	my = getNum(res.fz, res.fm);
// 	if(my != 0)
// 	{
// 		res.fz /= my;
// 		res.fm /= my;
// 	}
// 	if(res.fm == 1)
// 		printf("%d", res.fz);
// 	else
// 		printf("%d/%d", res.fz, res.fm);

// 	return 0;
// }