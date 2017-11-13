#include<stdio.h>
#include"_100buy100.h"
void cock(int mon,int num)
{
int i,hen1,num1,mon1;
for(i=0;i<((int)mon/5);i++)
{
mon1=mon;
num1=num;
mon1=mon1-5*(i+1);
num1=num1-i-1;
hen1=hen(mon1,num1);
	if(hen1!=0)
	{
	printf("购买公鸡:%d\n",i+1);
	printf("购买母鸡:%d\n",hen1);
	printf("购买雏鸡:%d\n",num-hen1-i-1);
	printf("\n");
	}
}

}

