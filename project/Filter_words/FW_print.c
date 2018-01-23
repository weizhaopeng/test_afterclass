#include"Filter_words.h"

/*the function to print the result of the English file*/
void  file_print    ();

void FW_print(LIST_WORDS list_words)
{
	NODE *node_temp=list_words;

	system("clear");
	printf("\033[40;32m******当前文档中单词数前十的单词统计******\n\033[0m");
	printf("\033[47;30m单词\t\t\t单词数\n\033[0m");

	for(int i=0;i<10&&node_temp!=NULL;i++,node_temp=node_temp->node_next)
	{
		printf("\033[40;31m%s\t\t\t\033[0m%ld",node_temp->word_content->word,\
		node_temp->word_content->word_number);
		printf("\n");
	}

	printf("\n");
	file_print();
}

void file_print()
{
	extern char filename[MAX];
	FILE *fp=fopen(filename,"r");
	char array_temp[MAX];

	printf("\033[40;32m******文档的内容为:******\n\033[0m");
	for(int i=1;feof(fp)!=1;i++)
	{
		fscanf(fp,"%s",array_temp);
		printf("%s ",array_temp);
		fp_skip_space(fp);

		if(i%10==0)
			printf("\n");
	}
}
