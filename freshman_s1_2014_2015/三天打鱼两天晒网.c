#include <stdio.h>
int main()
{
  int a;
  scanf("%d", &a);
  if (a % 5 == 0)
    printf("Drying in day %d\n", a);
  else if (a % 5 == 1)
    printf("Fishing in day %d\n", a);
  else if (a % 5 == 2)
    printf("Fishing in day %d\n", a);
  else if (a % 5 == 3)
    printf("Fishing in day %d\n", a);
  else if (a % 5 == 4)
    printf("Drying in day %d\n", a);
  return 0;
}