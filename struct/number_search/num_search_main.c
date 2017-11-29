#include"num_search.h"

void main (void)
{
	CUSTOMER *cus[10];
	int judge=1,check1,i=0;

	printf("请输入用户名和电话号码，按#结束\n****例如：魏朝鹏# 13151589195\n");
	cus[0]=(CUSTOMER *)malloc(sizeof(CUSTOMER));
	scanf("%s%s",cus[0]->name,cus[0]->num);	
	i++;
	
	do
	{	
		printf("是否继续进行输入：是——1，否——0\n");
		scanf("%d",&judge);
		if(judge!=0)
		{
			puts("请继续输入\n用户名和电话号码，按#结束\n****例如：魏朝鹏# 13151589195\n");
			cus[i]=(CUSTOMER *)malloc(sizeof(CUSTOMER));
			scanf("%s%s",cus[i]->name,cus[i]->num);
			i++;
		}
		else
		judge=0;
	}while(judge!=0);
	
	puts("是否查询用户号码：是——1，否——0");
	scanf("%d",&check1);
	if(check1!=0)
	num_check(cus,i-1);
}
	
