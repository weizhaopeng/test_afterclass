#include"guess_number.h"
void guess_num_mode()
{
	int choice_gamemode;
	TRY *ans;
	ans=(TRY *)malloc(sizeof(TRY));

	puts("\
	*****请选择游戏模式*****\n\
	*****1:单人模式    *****\n\
	*****2:双人模式    *****\n\
	*****3:返回主菜单  *****\n\
	*****请选择：");
	scanf("%d",&choice_gamemode);

	switch(choice_gamemode)
	{
		case 1:srand((unsigned)time(NULL));
				for(int i=0;i<4;i++)
					ans->number[i]=rand()%9;
			game_1p(ans);
			break;
		case 2:srand((unsigned)time(NULL));
				for(int i=0;i<4;i++)
					ans->number[i]=rand()%9;
			game_2p(ans);
			break;
		case 3:guess_num_menu();
			break;
		default:puts("选择错误");
			guess_num_mode();
			break;
	}
	free(ans);
}
			 
void game_1p(const TRY *ans)
{
	TRY *try0;
	try0=(TRY *)malloc(sizeof(TRY));
	RESULT *result;
	result=(RESULT *)malloc(sizeof(RESULT));

	puts("请输入您的姓名：");
	scanf("%s",try0->name);
	try0->try_number=0;

	do
	{
		printf("*****请输入您的猜想*****\n\n\n");

		scanf("%d%d%d%d",try0->number,try0->number+1,try0->number+2,try0->number+3);
		result->A=0;
		result->B=0;
		
		for(int ans_i=0;ans_i<4;ans_i++)
		{
			if(try0->number[ans_i]==ans->number[ans_i])
				result->A++;
			for(int try0_j=0;try0_j<4;try0_j++)
			{
				if(try0->number[try0_j]==ans->number[ans_i]&&ans_i!=try0_j)
					result->B++;
			}
		}
		
		if(result->A==4)
		{
			printf("*****输入正确******\n正确结果是：%d %d %d %d\n", \
			ans->number[0],ans->number[1],ans->number[2],ans->number[3]);
			break;
		}
		else
			printf("结果错误！\n提示：%dA%dB\n",result->A,result->B);
		
	try0->try_number++;
	}while(1);
	free(try0);
}
	
void game_2p(const TRY *ans)
{
	RESULT *result;
	result=(RESULT *)malloc(sizeof(RESULT));

	TRY *try1,*try2;
	try1=(TRY *)malloc(sizeof(TRY));
	try2=(TRY *)malloc(sizeof(TRY));
	
	puts("请输入玩家1的名字");
	scanf("%s",try1->name);
	puts("请输入玩家2的名字");
	scanf("%s",try2->name);
	
	int num_try=0;
	try1->try_number=0;
	try2->try_number=0;
	do 
	{
		result->A=0;
		result->B=0;
		
		if(num_try%2==0)
			printf("*****%s*****\n",try1->name);
		else
			printf("*****%s*****\n",try2->name);

		printf("*****请输入您的猜想*****\n\n\n");
		scanf("%d%d%d%d",try1->number,try1->number+1,try1->number+2,try1->number+3);

		for(int ans_i=0;ans_i<4;ans_i++)
		{
			if(try1->number[ans_i]==ans->number[ans_i])
				result->A++;
			for(int try1_j=0;try1_j<4;try1_j++)
			{
				if(try1->number[try1_j]==ans->number[ans_i]&&\
					ans_i!=try1_j)
					result->B++;
			}
		}
			
		if(result->A==4)
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
		try1->try_number=(int)num_try/2+1;
		try2->try_number=(int)num_try/2;	
	}while(1);
	free(try1);
	free(try2);
}

