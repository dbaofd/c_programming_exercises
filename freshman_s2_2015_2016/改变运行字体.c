//自动变换字体颜色
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
int main()
{
  srand((unsigned)time(NULL));
  char com[20] = {0};
  union utype {
    int i;
    char ch;
    float a;
  } temp;
  temp.i = 266;
  printf("%d\n", temp.ch);
  while (1)
  {
    int a = rand() % 8;
    sprintf(com, "color 1%d", a);
    system(com); //
    Sleep(1000);
  }
  system("pause");
  return 0;
}
改变字体背景颜色
/*
局限：                仅限Windows系统使用；不能改变背景颜色；
主要应用：        改变指定区域的字体颜色；        

*/
#include <stdio.h>
#include <windows.h>
/*颜色对应值： 
　　0=黑色                8=灰色　　
  　 1=蓝色                9=淡蓝色                　　                        
　　2=绿色                10=淡绿色       0xa        　　
　　3=湖蓝色          11=淡浅绿色        0xb　
　　4=红色                12=淡红色        0xc　　
　　5=紫色                13=淡紫色        0xd        　　
　　6=黄色                14=淡黄色        0xe        　　
　　7=白色                15=亮白色        0xf 
　　也可以吧这些值设置成常量。
*/
void color(const unsigned short color1)
{ /*仅限改变0-15的颜色;如果在0-15那么实现他的颜色   因为如果超过15后面的改变的是文本背景色。*/
  if (color1 >= 0 && color1 <= 15)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
  /*如果不在0-15的范围颜色，那么改为默认的颜色白色；*/
  else
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

main()
{ /*在上面写color（颜色代码）下面便是改变的颜色。
          注意：这里是把下面所有的颜色全部改变。*/
  color(0);
  printf("黑色\n");
  color(1);
  printf("蓝色\n");
  color(2);
  printf("绿色\n");
  color(3);
  printf("湖蓝色\n");
  color(4);
  printf("红色\n");
  color(5);
  printf("紫色\n");
  color(6);
  printf("黄色\n");
  color(7);
  printf("白色\n");
  color(8);
  printf("灰色\n");
  color(9);
  printf("淡蓝色\n");
  color(10);
  printf("淡绿色\n");

  color(11);
  printf("淡浅绿色\n");
  color(12);
  printf("淡红色\n");
  color(13);
  printf("淡紫色\n");
  color(14);
  printf("淡黄色\n");
  color(15);
  printf("亮白色\n");
  color(16); //应为这里大于15，所以，下面的颜色应该是白色；
  printf("%s", "hello");
  printf("%s\n", " world");
}