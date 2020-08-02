#include<stdio.h>
#include<math.h>
int FindNum()
 {int i,sn=0,tn=0;
 for(i=1;i<=9;i++)

   { sn=(30+i)*6237;
    tn=(i*10+3)*3564;
     if(sn==tn)
     {printf("%d",i);
     break;
     }
   }
   printf("\n");
   return i;
 }
 int FindRoot(int a,int b,int c)
{
float X,D,E,X1,X2;
scanf("%d %d %d",&a,&b,&c);
D=b*b-4*a*c;
if(D<0)
printf("此方程无解\n");
else if(D==0)
{X=(-b)/(2*a);
printf("%.2f\n",X);
}
else
{E=sqrt(D);
X1=(-b+E)/(2*a);
X2=(-b-E)/(2*a);
printf("X1=%.2f X2=%.2f\n",X1,X2);
}
return 0;
}
int Detective()
{int i,j,k,s;
for(i=0;i<=9;i++)
  for(j=0;j<=9;j++)
  {s=i*1000+i*100+j*10+j;
  for(k=32;k<=99;k++)
  if(s==k*k)
  printf("%d%d%d%d\n",i,i,j,j);
  }
  return 0;
}
int Bear()
{int a=1,b,i;
  for(i=0;i<9;i++)
  {a=(a+1)*2;
  b=a;
  }
  printf("%d\n",b);
  return b;
}
void Diamond()
{int i,j,k;
for(i=0;i<6;i++)
{for(j=1;j<6-i;j++)
printf(" ");
for(k=0;k<i*2+1;k++)
printf("*");
printf("\n");
}
for(i=0;i<5;i++)
{for(j=0;j<=i;j++)
printf(" ");
for(k=0;k<(5-i)*2-1;k++)
printf("*");
printf("\n");
}
}
int main()
{int m,e,f,g,i=1;
printf("*******************************\n");
printf("1.FindNum\n");
printf("2.FindFoot\n");
printf("3.Detective\n");
printf("4.Bear\n");
printf("5.Diamond\n");
printf("6.Exit\n");
printf("*******************************\n");
while((i<=6)&&(m!=6))
{i++;
scanf("%d",&m);
switch(m)
{case 1:FindNum();printf("\n");break;
 case 2:FindRoot(e,f,g);printf("\n");break;
 case 3:Detective();printf("\n");break;
 case 4:Bear();printf("\n");break;
 case 5:Diamond();printf("\n");break;
 case 6:break;
}
}
return 0;
}