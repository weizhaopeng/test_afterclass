#include"guess_number.h"

void guess_num_menu(void)
{
	int choice_ruletype;
	unsigned int choice_menu;
	
	for(int row=0;row<3;row++)
	{
		if(row==0)
			printf("***1:开始游戏***\n");
		if(row==1)
			printf(" **2:游戏规则** \n");
		if(row==2)
			printf("  *3:退出游戏*  \n");
		printf("\n");
	}
	printf("\t请选择:");
	scanf("%d",&choice_menu);
	switch(choice_menu)
	{
		case 1:guess_num_mode();
			break;
		case 2:guess_num_rule();
			break;
		case 3:return;
			break;
		default:puts("选择错误");
			guess_num_menu();
			break;
	}
}
		
void main (void)
{	
	system("clear");
	guess_num_menu();
}
