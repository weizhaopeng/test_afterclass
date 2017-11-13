#include<stdio.h>
#include"_100buy100.h"
int hen(int mon,int num)
{
int i,mon1,num1;
	for(i=0;i<((int)mon/3);i++)
	{
	mon1=mon;
	num1=num;
	mon1=mon1-3*(i+1);
	num1=num1-i-1;
		if(chick(mon1,num1)==1)
		return i+1;
	}
}

