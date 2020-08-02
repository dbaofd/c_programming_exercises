#include<stdio.h>
int main()
{
	int i,n;
	scanf("%d",&n);
	if((n<2001)||n>2100)
	printf("Invaild year!\n");
    else
	{for(i=2001;i<=n;i++)
	{if((i%4==0&&1%100!=0)||(i%400==0))
	printf("%d是闰年\n",i);
	}
	}
	return 0;	
}


方法二
#include<stdio.h>
int main()
{
  int n,i;
  scanf("%d",&n);
  printf("\n");
  if((n>2000)&&(n<=3000))
  {for(i=2001;i<=n;i++)
   if((i%100!=0&&i%4==0)||(i%400==0))
   printf("%d\n",i);
  }
  else
  printf("Invalid year!\n");
  return 0;
}