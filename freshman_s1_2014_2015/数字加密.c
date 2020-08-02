// 输入一个四位数，将其加密后输出。方法是将该数每一位上的数字加9，
// 然后除以10取余，做为该位上的新数字，最后将千位和十位上的数字互
// 换，百位和个位上的数字互换，组成加密后的新四位数。例如输入1257
// ，经过加9取余后得到新数字0146，再经过两次换位后得到4601
#include <stdio.h>
int main()
{
    int m, i, n, j, k, s = 0;
    scanf("%d", &m);
    i = (m % 10 + 9) % 10;
    j = (m % 100 / 10 + 9) % 10;
    k = (m % 1000 / 100 + 9) % 10;
    n = (m / 1000 + 9) % 10;
    printf("The encrypted number is %d%d%d%d\n", j, i, n, k);
    return 0;
}