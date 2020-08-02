// 一个六位数的电话号码，在首位数字和第二位之间加上8，变成七位
// 电话号码，之后再首位之前加上2变成八位号码，之后发现这个八位号码
// 是原来六位号码的81倍，求原来的号码为多少？
#include <stdio.h>
int main()
{
	int num, newnum, i, j, k;
	for (num = 259260; num < 399999; num++)
	{
		i = num / 100000;
		j = num % 100000;
		newnum = 20000000 + i * 1000000 + 800000 + j;
		if ((double)newnum / num == 81)
		{
			printf("num=:%d\nnewnum:%d", num, newnum);
		}
	}
	return 0;
}