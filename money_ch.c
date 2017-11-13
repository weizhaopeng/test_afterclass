#include"stdio.h"
int main(void)
{
int i,j,k;
double money,money1;
printf("请输入要兑换的金额：\n");
scanf("%lf",&money);
money1=money;
money*=10;
	for(i=0;money>9;i++)
	{
	money-=10;
	}
	for(j=0;money>4;j++)
	{
	money-=5;
	}
	for(k=0;money>0;k++)
	{
	money-=1;
	}
printf("%-4.1lf可兑换为%d个一元，%d个五角，%d个一角\n",money1,i,j,k);
return 0;
}//完成
