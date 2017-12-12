#include"guess_number.h"
void guess_num_rule(void)
{
	int choice_ruletype;
	puts("*****请选择要查看的游戏规则*****\n  \
		  *****1:单人游戏			 *****\n  \
		  *****2:双人游戏			 *****\n  \
		  *****3:返回主菜单			 *****\n");
	scanf("%d",&choice_ruletype);
	
	switch(choice_ruletype)
	{
		case 1:
			printf("单人游戏需要玩家在电脑随机产生一个四位数的情况下玩家\n进行猜测，没当输入一个四位数都会返回提示：aAbB，意味\n着有a个数字的位置和数值正确，b个数字数值正确但是位置\n不对例如：正确答案是5213，猜测数值是：3216 此时显示2A1B\n");
			guess_num_menu();
			break;
		case 2:
			printf("双人游戏需要两个玩家在电脑随机产生一个四位数的情况下玩家\n轮流进行猜测，没当输入一个四位数都会返回提示：aAbB，意味着有a个\n数字的位置和数值正确，b个数字数值正确但是位置不对\n例如：正确答案是5213，猜测数值是：3216 此时显示2A1B\n");
			guess_num_menu();
			break;
		case 3:
			guess_num_menu();
			break;
		default:puts("选择错误");
			guess_num_rule();
			break;
	}
}
			
