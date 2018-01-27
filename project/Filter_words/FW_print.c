#include"Filter_words.h" 


/*the function to print the result of the English file*/
void file_print();

/*sort the list_words as the number of words*/
void NodePrint (LIST_WORDS list_words);


/*
 *
 *
 *print the result 
 */
void FW_print  (LIST_WORDS list_words)
{
	NODE *node_temp;
	system("clear");
	printf("\033[40;32m******当前文档中单词数前十的单词统计******\n\033[0m");
	printf("\033[47;30m单词\t\t\t单词数\n\033[0m");

	for(int i=0;i<NUMBER_SHOW;i++)
		NodePrint(list_words);

	printf("\n");
	file_print();
}


/*
 *
 *
 *sort the list_words as the number of words
 */
void NodePrint(LIST_WORDS list_words)
{
	NODE *node_i,*node_j;
	NODE *node_max_wordnum,*node_max_before;
	node_max_wordnum=list_words;
	
	if(list_words==NULL)
		return ;
	else
	{
		for(node_max_wordnum=node_i=list_words;node_i!=NULL;node_j=node_i,node_i=node_i->node_next)
		{
			if(node_i->word_content->word_number>node_max_wordnum->word_content->word_number)
				node_max_wordnum=node_i;
			node_max_before=node_j;
		}
	
		printf("\033[40;31m%s\t\t\t\033[0m%ld",node_max_wordnum->word_content->word,\
		node_max_wordnum->word_content->word_number);
	
		node_max_before->node_next=node_max_wordnum->node_next;
		free(node_max_before);
	}
	return ;
}
	
/*
 *
 *
 *the function to print the result of the English file
 */
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

