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

	/*print the node*/
	system("clear");
	printf("\033[40;32m******当前文档中单词数前十的单词统计******\n\033[0m");
	printf("\033[47;30m单词\t\t\t单词数\n\033[0m");
	for(int i=0;i<NUMBER_SHOW;i++)
		NodePrint(list_words);
	printf("\n");

	/*print the file content*/
	printf("\033[40;32m******文档的内容为:******\n\033[0m");
	file_print();
}


/*
 *
 *
 *print the list_words' nodes as the number of words
 */
void NodePrint(LIST_WORDS list_words)
{
	NODE *node_i,*node_j;
	NODE *node_max_wordnum,*node_max_before;
	

	if(list_words==NULL)
	{
		printf("\n");
		return ;
	}
	else
	{
		for(node_max_wordnum=list_words,node_i=list_words;node_i!=NULL;\
		node_j=node_i,node_i=node_i->node_next)
		{
			if(node_i->word_content->word_number>node_max_wordnum->word_content->word_number)
			{
				node_max_wordnum=node_i;
				node_max_before=node_j;
			}
		}
	
		printf("\033[40;31m%s\t\t\t%ld\n\033[0m",node_max_wordnum->word_content->word,\
		node_max_wordnum->word_content->word_number);
	
		if(node_max_wordnum!=list_words)
			node_max_before->node_next=node_max_wordnum->node_next;
		else
			list_words=node_max_wordnum->node_next;
		free(node_max_wordnum);
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
	char array_temp[MAX];
	FILE *fp=fopen(filename,"r+");
	
	for(int i=1;feof(fp)!=1;i++)
	{
		fscanf(fp,"%s",array_temp);
		printf("%s ",array_temp);
		fp_skip_space(fp);

		if(i%10==0)
			printf("\n");
	}
	printf("\n");
}

