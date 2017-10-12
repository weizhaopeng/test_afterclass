#include"stdio.h"
int main(void)
{
int i,j;
int a[4][4];
	for (i=1;i<4;i++)
	{
		for (j=1;j<4;j++)
		{
		printf("请输入a[%d][%d]\n",i,j);
		scanf("%d",&a[i][j]);
		}
	}
	
	for (i=1;i<4;i++)
	{
		for (j=1;j<4;j++)
		{
		printf("%-5d",a[i][j]);
		}
	printf("\n");
	}
	return 0;
}
