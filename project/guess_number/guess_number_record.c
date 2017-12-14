#include"guess_number_record.c"
void guess_num_record(const FILE *fp,const const TRY *try,const int mode)
{
	char *str1={"单人模式过关记录\n"};
	char *str2={"双人模式过关记录\n"};
	char *str3={"玩家姓名\n"};
	char *str4={"猜数字正确答案\n"};
	char *str5={"猜测次数\n"};
	char *try_num;

	if(mode!=1&&mode!=2)
		return ;	
	if(mode==1)
	{
		*try_num=(char)try->try_number;
		fseek(fp,0L,2);
		fprintf(str1,fp);
		fprintf(str3,fp);
		fprintf(try->name,fp);
		fprintf(str4,fp);
		fprintf(try->number,fp);
		fprintf(str5,fp);
		fputc(try_num,fp);
	}
		
	if(mode==2)	
	{
		*try_num=(char)try->try_number;
		fseek(fp,0L,2);
		fprintf(str1,fp);
		fprintf(str2,fp);
		fprintf(try->name,fp);
		fprintf(str4,fp);
		fprintf(try->number,fp);
		fprintf(str5,fp);
		fputc(try_num,fp);
	}
}
		
	
