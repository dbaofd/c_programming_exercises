#include <stdio.h>
struct youli
{
	double rose;
	double baby;
};
int main()
{
	struct youli a1, a2, res;
	scanf("%lf %lf %lf %lf", &a1.rose, &a1.baby, &a2.rose, &a2.baby);
	res.rose = a1.rose + a2.rose;
	res.baby = a1.baby + a2.baby;
	if (res.rose < 0.05)
		res.rose = 0;
	else if (res.baby < 0.05)
		res.baby = 0;
	printf("(%.1lf, %.1lf)\n", res.rose, res.baby);
	return 0;
}

// #include<stdio.h>
// #include<math.h>
// int main()
// {
// 	double x1,y1,x2,y2,x,y;
// 	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
// 	x=x1+x2;
// 	y=y1+y2;
// 	if(fabs(x)<0.05)
// 	x=0;
// 	if(fabs(y)<0.05)
// 	y=0;
// 	printf("��%.1lf, %.1lf��\n",x,y);
// 	return 0;
// }
