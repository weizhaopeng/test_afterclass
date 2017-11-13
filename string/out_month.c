#include"stdio.h"
int main (void)
{
	int mon;
	char *month[12]={"january","february","march","april","may","june","july","august","september","october","november","december"};
	
	puts("请输入要查询的月份");
	scanf("%d",&mon);
	
	printf("%s\n",month[mon-1]);
	return 0;
}
