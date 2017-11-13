#include<stdio.h>
#include"fiost.h"
int fiost_leap(int y)
{
	if(y%4==0&&y%100!=0||y%400==0)
	return 1;
	else 
	return 0;
}
