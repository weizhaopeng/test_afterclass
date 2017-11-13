#include<stdio.h>
int sub_fish(int flo)
{
	if (flo==1) 
	{ 
		static int i=0;
		do 
		{
		i++;
		}while(i%5!=0);
	return (i+1);
	}
	else
	{
	int t;
		do
		{
		t=sub_fish(flo-1);
		}while(t%4!=0);
	return (t/4*5+1);
	}
}
void main (void)
{
sub_fish(4);
printf("最少的鱼的数量是：%d\n",sub_fish(5));
}
	
