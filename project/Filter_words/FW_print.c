#include"Filter_words.h" 
/*the function to print the result of the English file*/
void file_print();
/*sort the list_words as the number of words*/
NODE *SortList  (LIST_WORDS list_words);

void FW_print  (LIST_WORDS list_words)
{
	NODE *node_temp=list_words;
	NODE *arr_node_point[NUMBER_SHOW];

	for(int i;i<NUMBER_SHOW;i++)
	{
		

	system("clear");
	printf("\033[40;32m******当前文档中单词数前十的单词统计******\n\033[0m");
	printf("\033[47;30m单词\t\t\t单词数\n\033[0m");

	for(int i=0;i<NUMBER_SHOW&&*(arr_node_point)!=NULL;i++)
	{
		printf("\033[40;31m%s\t\t\t\033[0m%10ld",*(arr_node_point+i)->word_content->word,\
		*(arr_node_point+i)->word_content->word_number);
		printf("\n");
	}

	printf("\n");
	file_print();
}

/*sort the list_words as the number of words*/
NODE *SortList  (LIST_WORDS list_words)
{
	static NODE *node_temp=list_words,
	NODE *arr_node_point,*node_i;

	for(int i=0;i<NUMBER_SHOW;i++)
	{
		for(node_i=list_words->node_next;node_i!=NULL;node_i=node_i->node_next)
		{
			/*The node_i's number > node_temp's and they are not the same. */
			if(node_i->word_content->word_number>node_temp->word_content->word_number||\
			node_i->word_content->word_value!=node_temp->word_content->word_value)
				node_temp=node_i;
		}	
		arr_node_point[i]=node_temp;
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
