#include"stdio.h"

struct elected
{
	char name[15];
	int num;
};
typedef struct elected ELE;

void main (void)
{
	int vote;
	ELE voter[3]=
	{
		{"魏朝鹏"},
		{"杨晓涵"},
		{"炮姐"}
	};
	for(int i=0;i<10;i++)
	{	
		puts("请输入要投给的人的编号\n*****魏朝鹏——100*****\n*****杨晓涵——101*****\n*****炮姐——102*****");
		scanf("%d",&vote);
		switch(vote)
		{
			case 100:voter->num++;
				break;
			case 101:(voter+1)->num++;
				break;
			case 102:(voter+2)->num++;
				break;
			default:puts("输入无效");
				i--;
				break;
		}
	}

	puts("*****魏朝鹏*****杨晓涵*****炮姐*****");
	printf("*****%-6d*****%-6d*****%-6d*****\n",voter->num,(voter+1)->num,(voter+2)->num);
}
	
	
