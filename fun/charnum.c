#include"stdio.h"
int charnum(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{}
	return i;
}
void main (void)
{
	char str[100];
	puts("请输入字符串");
	scanf("%s",str);
	printf("含有字符的个数是:%d\n",charnum(str));
}
