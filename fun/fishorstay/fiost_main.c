#include<stdio.h>
#include"fiost.h"
int main (void)
{
	int y,m,d,day;
	do
	{
		printf("请输入2000年1月1日之后的任意一天，如：2002 3 23\n");
		scanf("%d%d%d",&y,&m,&d);
	}while(isright(y,m,d)==0);
	day=fiost_day(y,m,d);
	if(day%5<4&&day%5!=0)
		printf("渔夫在打鱼\n");
	else
		printf("渔夫在晒网\n");
return 0;
}
