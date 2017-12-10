#include"guess_number.h"
static TRY *ans;
ans=(TRY *)calloc(sizeof(TRY));
ans->name="auto";
for(int i=0;i<4;i++)
{
	ans->number[i]=rand()&9;
}
void guess_num_menu()
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
		case 0:void guess_num_game();
			break;
		case 1:void guess_num_rule();
			break;
		case 2:exit(-1);
			break;
		default:puts("选择错误");
			void guess_num_menu();
			break;
	}
}
		
void main (void)
{	
	
}
