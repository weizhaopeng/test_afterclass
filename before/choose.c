#include"stdio.h"
#include"stdlib.h"
int main (void)
{
int a,b,re;
char fh; 
long max;
printf("请输入产生的数的最大值<10000\n");
scanf("%ld",&max);
printf("请输入进行的运算（+或者-）\n");
scanf("%c",&fh);
srand((unsigned long)time(0));
while(fh=='\0')
{
a=rand()%max;
b=rand()%max;
	while(a<b)
	{
	a=rand()%max;
	b=rand()%max;
	}
}
	if (fh=='+')
	re=a+b;
	else
	re=a-b;
	
printf("%d\t%c\t%d=%d\n",a,fh,b,re);
return 0;
}
	
