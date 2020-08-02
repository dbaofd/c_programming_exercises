#include <stdio.h>
#include <string.h>
int main()
{
  char str[80], ch;
  int i, j, k = 0;
  gets(str);
  scanf("%c", &ch);
  for (i = 0; i < strlen(str); i++)
  {
    if (str[i] == ch)
    {
      k++;
      for (; i < strlen(str); i++)
        printf("%c", str[i]);
    }
  }
  if (k == 0)
    printf("Not found\n");
  return 0;
}
// 曲解后的查找字符
// 例1
// 输入boy   bbc  sdf  ju  bomb
//       b
// 输出boy bbc bomb
// #include<stdio.h>
// #include<string.h>
// int main()
// {
//    char str[81],ch;
//    int i,j,k=0;
//    gets(str);
//    scanf("%c",&ch);
//    for(i=0;i<strlen(str);i++)
//      {
//          if(str[i]==ch)
//            {
//              k++;
//              for(;str[i]!=' ';i++)
//                {
//                  printf("%c",str[i]);
//                  if(i==strlen(str)-1)
//                      break;
//                }
//            printf(" ");
//            }
//      }
//     if(k==0)
//       printf("Not found\n");
//     return 0;
// }
// 此题被我曲解，其实很简单，被我想复杂了，结果我竟然实现了这个功能！

// break的作用，之前写这段代码，程序运行结果只要我要查找的首字母，有该首字母的单词
// 按理均会被输出，但是如果这个单词以这个字母为首字母并且是最后一个单词并且它后面没有空格
// ，这时就会出现乱码，因为我的条件是str等于空格了才会终止程序，否则像这种情况就终止不了了
// ，所以为了防止这种情况发生，加上break，依靠在最后一个单词的最后一个字母来决定终止程序。