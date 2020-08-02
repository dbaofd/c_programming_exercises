#include <stdio.h>
int main()
{
	int ch[12] = {5, 7, 9, 11, 23, 24, 26, 31, 34, 36, 45, 67};
	int low = 0, mid, high = 11, k, found = 0;
	scanf("%d", &k);
	while ((low <= high) && (found == 0))
	{
		mid = (low + high) / 2;
		if (k > ch[mid])
			low = mid + 1;
		else if (k < ch[mid])
			high = mid - 1;
		else
			found = 1;
	}
	if (found == 1)
		printf("此数组中已找到数%d它的下标为%d\n", k, mid);
	else
		printf("没有这个数\n");
	return 0;
}

//折半查找详细版
// #include<stdio.h>
// int main()
// {
// 	int found=0,low=0,high,mid,i,j,k,a[100],N;
// 	printf("请输入这个数组的大小\n");
// 	scanf("%d",&N);
// 	high=N-1;
// 	printf("请输入%d个数字，以从小到大的顺序或者相反\n",N);
// 	for(i=0;i<N;i++)
// 	scanf("%d",&a[i]);
// 	printf("请输入要查找的数字:");
// 	scanf("%d",&k);
// 	if(a[0]<a[N-1])
//     {
// 	  while((low<=high)&&(found==0))
//      {
//     	  mid=(low+high)/2;
//     	  if(k>a[mid])
//     		  low=mid+1;
//     	  else if(k<a[mid])
//     		  high=mid-1;
//     	  else
//     		  found=1;
//      }
//       if(found==1)
//     	  printf("这个数找到了，它的下标为%d\n",mid);
//   	  else
//   	      printf("找不到这个数\n");
//    }
//    else
//    {  while((low<=high)&&(found==0))
//      {
//     	  mid=(low+high)/2;
//     	  if(k>a[mid])
//     		  high=mid-1;
//     	  else if(k<a[mid])
//     		  low=mid+1;
//     	  else
//     		  found=1;
//      }
//           if(found==1)
//     	  printf("这个数找到了，它的下标为%d\n",mid);
//     	  else
//     	  printf("找不到这个数\n");
//    }
//     return 0;
// }