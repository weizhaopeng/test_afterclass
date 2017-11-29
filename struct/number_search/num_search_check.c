#include"num_search.h"

void num_check(CUSTOMER *cus[],int n)
{
	int check_mode;
	char check_name[15],check_num[15];
	do
	{
		puts("选择查询方式:姓名——1，号码——2");
		scanf("%d",&check_mode);
		if(check_mode==1)
		{
			puts("请输入查询的姓名");
			scanf("%s",check_name);
			for(int i=0;i<n;i++)
			{
				if(strcmp(check_name,cus[i]->name))
				{
					printf("姓名是：%s\n电话号码是：%s\n",cus[i]->name,cus[i]->num);
					return ;
				}
			}
			puts("未查询到");
		}
		
		if(check_mode==2)
		{
			puts("请输入查询的电话号码");
			scanf("%s",check_num);
			for(int i=0;i<n;i++)
			{
				if(strcmp(check_num,cus[i]->name))
				{
					printf("姓名是：%s\n电话号码是：%s\n",cus[i]->name,cus[i]->num);	
					return ;
				}
			}
			puts("未查询到");
		}
	}while(check_mode==1||check_mode==2);
}

	 


