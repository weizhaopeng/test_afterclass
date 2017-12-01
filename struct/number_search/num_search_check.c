#include"num_search.h"

void num_check(CUSTOMER *cus[],int n)
{
	int check_mode;
	char check_con[15];
	do
	{
		puts("选择查询方式:姓名——1，号码——2");
		scanf("%d",&check_mode);
		if(check_mode!=1&&check_mode!=2)
		continue;
		
		if(check_mode==1)
		puts("请输入查询的姓名");
		if(check_mode==2)
		puts("请输入查询的电话号码");

		scanf("%s",check_con);
		int sec=1;
		for(int i=0;i<n+1;i++)
		{
			if(check_mode==1)
			{	
				if(strcmp(check_con,cus[i]->name)==0)
				{
					printf("姓名是：%s\n电话号码是：%s\n",cus[i]->name,cus[i]->num);
					sec=0;
				}
			}
			
			if(check_mode==2)
			{	
				if(strcmp(check_con,cus[i]->num)==0)
				{
                                	printf("姓名是：%s\n电话号码是：%s\n",cus[i]->name,cus[i]->num);
					sec=0;
				}
			}	
		}
		if(sec==1)
		puts("未查询到");
		return ;
	}while(check_mode!=1&&check_mode!=2);
}

	 


