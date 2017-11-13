#include<stdio.h>
int main(void)
{
int mon,num,i,k,j,cock,hen,chick;
printf("请输入所持有的金额:\n");
scanf("%d",&mon);
printf("请输入要购买的鸡的数量:\n");
scanf("%d",&num);
cock=(int)mon/5;
hen=(int)mon/3;
chick=num<mon*3?num:mon*3;
	for(i=0;i<cock;i++)
	{
		for(j=0;j<hen;j++)
		{
			for( k=0;k<chick;k++)
			{	
			if(k%3==0)
				if(5*i+3*j+k/3==mon)
					if(i+j+k==num)	
					printf("公鸡购买%d\n母鸡购买%d\n雏鸡购买%d\n",i,j,k);
			}
		}
	}
return 0;
}



