#include"Filter_words.h"

void FW_print(LIST_WORDS *list_words)
{
	NODE *node_temp=list_words;

	system("clear");
	printf("\033[40;32m******当前文档中单词数前十的单词统计******\n\033[0m");
	printf("\033[47;30m单词\t\t单词数\n\033[0m");

	for(int i=0;i<10&&node_temp!=NULL;i++)
	{
		printf("\033[40;31m%s\t\t\033[0m%d",node_temp->word_content->word,\
		node_temp->word_content->word_number);
		printf("\n");
	}

	file_print():
}

void file_print()
{
	extern char filename_read[MAX];
	FILE *fp=fopen("filename_read","r");
	char array_temp[MAX];

	do{
		fscanf(fp,"%s",array_temp);
		printf("%s ",array_temp);
		fp_skip_space(fp);
	}while(feof(fp)!=1);
}
