#include<stdio.h>
int main()
{
	int a[2][3]={{1,2,3},{4,5,6}};
	int b[3][2];
	int i,j;
	printf("array a\n");
	for(i=0;i<2;i++)
	  {for(j=0;j<3;j++)
	  {
  		printf("%2d",a[i][j]);
  		b[j][i]=a[i][j];
  	}
  	printf("\n");
	  }
  	printf("array b\n");
  	for(i=0;i<3;i++)
  	  {for(j=0;j<2;j++)
  	  printf("%2d",b[i][j]);
  	  printf("\n"); 
		}
    return 0;	
}

自定义矩阵
#include<stdio.h>
int main()
{
	int a[100][100];
	int i,j,m,n,b[100][100];
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
	  scanf("%d",&a[i][j]);
	printf("Array a\n");
	for(i=0;i<m;i++)
	  {
	    for(j=0;j<n;j++)
	  {
	     printf("%3d",a[i][j]);
	     b[j][i]=a[i][j];
	  }
	  printf("\n");
	  }
    printf("Array b\n");
    for(i=0;i<n;i++)
	  {
	    for(j=0;j<m;j++)
	    printf("%3d",b[i][j]);
	    printf("\n");
	  }
 return 0;
}