#include"guess_num.h"
void guess_num_mode()
{
	int choice_gamemode;
	puts("\
	*****请选择游戏模式*****\n\
	*****1:单人模式    *****\n\
	*****2:双人模式    *****\n\
	*****3:退出	   *****\n\
	*****请选择：");
	scanf("%d",&choice_gamemode);
		
	switch(choice_gamemode)
	{
		case 1:void game_1p();
			for(int i=0;i<4;i++)
			ans->number[i]=rand()%9;
			break;
		case 2:void game_2p();
			break;
		case 3:void guess_num_menu();
			break;
		default:puts("选择错误");
			void guess_num_mode();
			break;
	}
}
			 
void game_1p()
{
	RESULT *result={0,0};
	TRY *try0;
	extern TRY *ans;
	puts("请输入您的姓名：");
	scanf("%s",try0->name);
	do
	{
		printf("*****请输入您的猜想*****\n\n\n");
		for(int i=0;i<4;i++)
			try0->number[i]=getch();
		
		for(int ans_i=0;ans_i<4;ans_i++)
		{
			for(int try0_j=0;try0_j<4;try0_j++)
			{
				if(try0->number[ans_i]==ans->number[ans_i])
					result->A++;
				if(try0->number[try0_j]==ans->number[ans_i]&&\
					ans_i!=try0_j)
					result->B++;
			}
		}
		
		if(result->A==4&&result->B==0)
		{
			printf("*****输入正确******\n正确结果是：%d %d %d %d\n", \
			ans->number[0],ans->number[1],ans->number[2],ans->number[3]);
			break;
		}
		else
			printf("结果错误！\n提示：%dA%dB\n",result->A,result->B);
		
	}while(1);
}
	
void game_2p()
{
	result *result={0,0};
	TRY *try1,*try2;
	extern TRY *ans;
	
	puts("请输入玩家1的名字");
	scanf("%s",try1->name);
	puts("请输入玩家2的名字");
	scanf("%s",try2->name);
	
	int num_try=0;
	do 
	{
		if(num_try%2==0)
			printf("*****%s*****\n",try1->name);
		else
			printf("*****%s*****\n",try2->name);
		printf("*****请输入您的猜想*****\n\n\n");
	
		for(int i=0;i<4;i++)
			try0->number[i]=getch();
		
		for(int ans_i=0;ans_i<4;ans_i++)
		{
			for(int try0_j=0;try0_j<4;try0_j++)
			{
				if(try0->number[ans_i]==ans->number[ans_i])
					result->A++;
				if(try0->number[try0_j]==ans->number[ans_i]&&\
					ans_i!=try0_j)
					result->B++;
			}
		}
			
		if(result->A==4&&result->B==0)
		{
			printf("*****输入正确******\n正确结果是：%d %d %d %d\n", \
			ans->number[0],ans->number[1],ans->number[2],ans->number[3]);
			if(num_try%2==0)
				printf("玩家%s胜出\n",try1->name);
			else
				printf("玩家%s胜出\n",try2->name);
			break;
		}
		else
			printf("结果错误！\n提示：%dA%dB\n",result->A,result->B);
		
		num_try++;
	while(1);
}

