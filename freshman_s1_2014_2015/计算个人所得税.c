#include<stdio.h>
int main()
{int m;
 double p;
 scanf("%d",&m);
 if(m<=1600&&m>0)
 {p=0;
  printf("%.2lf\n",p);
 }
 else if(m>1600&&m<=2500)
 {p=0.05*(m-1600);
  printf("%.2lf\n",p);
 }
  else if(m>2500&&m<=3500)
 {p=0.10*(m-1600);
  printf("%.2lf\n",p);
 }
  else if(m>3500&&m<=4500)
 {p=0.15*(m-1600);
  printf("%.2lf\n",p);
 }
  else 
 {p=0.20*(m-1600);
  printf("%.2lf\n",p);
 }
 return 0;
}