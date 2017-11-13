#include<stdio.h>
#include"fiost.h"
int fiost_day(int y,int m,int d)
{
int day=0,i;
	for(i=2000;i<y;i++)
	{
		if(fiost_leap(i))
		day+=366;
		else
		day+=365;
	}
	switch(m)
	{
		case 12:day+=31;
		case 11:day+=30;
		case 10:day+=31;
		case 9:day+=30;
		case 8:day+=31;
		case 7:day+=31;
		case 6:day+=30;
		case 5:day+=31;
		case 4:day+=30;
		case 3:day+=31;
		case 2:
		{
			if(fiost_leap(y))
			day+=29;
			else
			day+=28;
		}
			break;
		default:
			break;
	}
day+=d;
return day;
}
		
