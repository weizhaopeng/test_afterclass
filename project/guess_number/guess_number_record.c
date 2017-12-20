#include"guess_number.h"
void guess_num_record_1p(const TRY *try)
{
	FILE *fp;
	fp=fopen("record.doc","a+");
	if(fp==NULL)
	{
		printf("record.doc文件不存在\n");
		exit(-1);
	}
	fseek(fp,0L,2);
	fprintf(fp,"单人模式游戏记录\n玩家名：\n");
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	fputs(try->name,fp);
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	fprintf(fp,"\n正确答案:\n");
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	for(int i=0;i<4;i++)
	{
		fprintf(fp,"%d ",try->number[i]);
		if(!ferror(fp))
		{
			puts("读写错误");
			exit(-1);
		}
	}
	fprintf(fp,"\n猜测次数：\n");
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	
	fprintf(fp,"%d\n\n",try->try_number);
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	fclose(fp);
}

void guess_num_record_2p(const TRY *try1,const TRY *try2)
{
	FILE *fp;
	fp=fopen("record.doc","a+");
	if(fp==NULL)
	{
		printf("record.doc文件不存在\n");
		exit(-1);
	}

	fseek(fp,0L,2);
	fprintf(fp,"双人模式游戏记录\n玩家名：\n");
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	fprintf(fp,"%sVS%s\n",try1->name,try2->name);
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	fprintf(fp,"最终结果:\n获胜者：\n");
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	if(try1->try_number%2==1)
		fprintf(fp,"%s\n",try1->name);
	else
		fprintf(fp,"%s\n",try2->name);
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	fprintf(fp,"正确答案:\n");
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	for(int i=0;i<4;i++)
	{
		fprintf(fp,"%d ",try1->number[i]);
		if(!ferror(fp))
		{
			puts("读写错误");
			exit(-1);
		}
	}
	fprintf(fp,"\n猜测次数：\n");
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	fprintf(fp,"%d\n\n",try1->try_number);
	if(!ferror(fp))
	{
		puts("读写错误");
		exit(-1);
	}
	fclose(fp);
}
	
		
	
