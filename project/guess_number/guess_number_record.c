#include"guess_number.h"
void guess_num_record_1p(const TRY *try)
{
	FILE *fp;
	fp=fopen("record.doc","a+");
	fseek(fp,0L,2);
	fprintf(fp,"单人模式游戏记录\n玩家名：\n");
	fputs(try->name,fp);
	fprintf(fp,"\n正确答案:\n");
	for(int i=0;i<4;i++)
		fprintf(fp,"%d ",try->number[i]);
	fprintf(fp,"\n猜测次数：\n");
	fprintf(fp,"%d\n\n",try->try_number);
	fclose(fp);
}

void guess_num_record_2p(const TRY *try1,const TRY *try2)
{
	FILE *fp;
	fp=fopen("record.doc","a+");
	fseek(fp,0L,2);
	fprintf(fp,"双人模式游戏记录\n玩家名：\n");
	fprintf(fp,"%sVS%s\n",try1->name,try2->name);
	fprintf(fp,"最终结果:\n获胜者：\n");
	if(try1->try_number%2==1)
		fprintf(fp,"%s\n",try1->name);
	else
		fprintf(fp,"%s\n",try2->name);
	fprintf(fp,"正确答案:\n");
	for(int i=0;i<4;i++)
		fprintf(fp,"%d ",try1->number[i]);
	fprintf(fp,"\n猜测次数：\n");
	fprintf(fp,"%d\n\n",try1->try_number);
	fclose(fp);
}
	
		
	
