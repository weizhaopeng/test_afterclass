#include"stdio.h"
int main(void)
{
char c,c1;
printf("请输入一个字母，数字或者符号\n");
c=getchar();
c1=c-1;
putchar(c1);
putchar('\n');
return 0;
}
