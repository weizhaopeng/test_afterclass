#include"Filter_words.h" 
/*the function to print the result of the English file*/
void file_print();
/*sort the list_words as the number of words*/
NODE *SortList  (LIST_WORDS list_words);

void FW_print  (LIST_WORDS list_words)
{
	NODE *node_temp=list_words;
	NODE **arr_node_point=SortList(list_words);
	

	for(int i;i<NUMBER_SHOW;i++)
	{
		

	system("clear");
	printf("\033[40;32m******当前文档中单词数前十的单词统计******\n\033[0m");
	printf("\033[47;30m单词\t\t\t单词数\n\033[0m");

	for(int i=0;i<NUMBER_SHOW&&arr_node_point!=NULL;i++)
	{
		printf("\033[40;31m%s\t\t\t\033[0m%10ld",*(arr_node_point+i)->word_content->word,\
		*(arr_node_point+i)->word_content->word_number);
		printf("\n");
	}

	printf("\n");
	file_print();
}

/*sort the list_words as the number of words*/
NODE **SortList  (LIST_WORDS list_words)
{
	static NODE *node_max_wordnum;
	NODE *node_i,*node_temp;
	NODE **arr_node_point;
	/*acquire the memory to stroage the point of the top nodes*/
	*arr_node_point=(NODE *)malloc(sizeof(NODE *)*NUMBER_SHOW);

	/*find the max word_number*/
	for(node_i=list_words->node_next;node_i!=NULL;node_i=node_i->node_next)
	{
		if(node_i->word_content->word_number>node_max_wordnum->word_content->word_number)
		{
			node_max_wordnum=node_i;
			*arr_node_point=node_max_wordnum;
		}
	}	
	/*find the other NUMBER_SHOW-1 node*/
	for(int i=1;i<NUMBER_SHOW;i++)
	{
		for(node_i=list_words->node_next ; node_i!=NULL ; node_i=node_i->node_next)
		{
			if(node_i->word_content->word_number > node_temp->word_content->word_number &&\
			strcmp(node_i->word_content->word,node_max_wordnum->word_content->word) !=0 &&\
			node_i->word_content->word_number <= node_max_wordnum->word_content->word_number)
			{
				node_max_wordnum=node_i;
				*(arr_node_point+i)=node_max_wordnum;
			}
		}	
	}
	
	return arr_node_point;		
}
	
/*the function to print the result of the English file*/
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

