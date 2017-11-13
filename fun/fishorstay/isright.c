#include<stdio.h>
#include"fiost.h"
int isright(int y,int m,int d)
{
if(y>=2000&&m>0&&m<13&&d>0&&d<32)
{
	switch(m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			break;
		case 2:
		{
			if(fiost_leap(y))
				return !(d<1||d>29);
			else
				return !(d<1||d>28);
		}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if(d<1||d>30)
			return 0;
		}
			break;
		default:
			break;
	}
}
else
return 0;
}
