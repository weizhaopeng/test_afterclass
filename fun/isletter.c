#include<stdio.h>
void isletter(char ch)
{
	if (ch>='a'&&ch<='z'||ch>='A'&&ch<='X')
	printf("%c是字母\n",ch);
	else
	printf("%c不是字母\n",ch);
}
void main (void)
{
	char ch;
	printf("请输入一个字符\n");
	scanf("%c",&ch);
	isletter(ch);
}
