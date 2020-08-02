#include <stdio.h>
#include <string.h>
void shuzu(char a[100])
{
    int i, j, k;
    for (i = strlen(a) - 1; i >= 0; i--)
        printf("%c", a[i]);
}
int main()
{
    int i;
    char a[100], ch[200];
    gets(a);
    shuzu(a);
    strcpy(ch, a);
    printf("\n%s\n", ch);
    strupr(ch);
    puts(ch);
    printf("%d\n", strcmp(ch, a));
    printf("%s\n", strcat(a, ch));
    strlwr(ch);
    for (i = 0; i < strlen(ch); i++)
        printf("%c", ch[i]);
    return 0;
}