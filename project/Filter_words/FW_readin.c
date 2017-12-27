#include"Filter_words.h"

LIST_WORDS *FW_readin(void)
{
	/*read the name of file*/
	char name_file_feadin[MAX];
	printf("\033[40;41mplease input the name of file\n\033[0m");
	scanf("%s",name_file_readin);

	FILE *fp;
	fp=fopen(name_file_readin,"r+");
	if(fp==NULL)
	
	LIST_WORDS *list_words,*node_temp,*newnode;
	node_temp=list_words=newnode=(NODE *)malloc(sizeof(NODE));
	fscanf(fp,"%s",newnode->param_words->word);
	if(ferror(fp)!=0)
		puts("read file error"):
	do
	{
		char ch_temp;
		ch_temp=fgetc(fp);
	}while(ch_temp==' ');
	fseek(fp,-1,1);
	wd_num++;
	comp_value=value_word(newnode->param_words->word);
	newnode->next_node==NULL;

	for(int i=0;feof(fp)!=0;i++)
	{
		char arr_temp[MAX];
		int value_temp;
		fscanf(fp,"%s",arr_temp);
		if(ferror(fp)!=0)
			puts("read file error"):
		value_temp=value_word(arr_temp);
		NODE *node_poll=list_words;
		do
		{
			if(value_temp==node_poll->param_words->\
			comp_value)
			{
				node_poll->param_words->wd_num++:
				continue;
			}
			else
				node_poll=node_poll->next_node;
		}while(node_poll!=NULL);
		
	
		newnode=(NODE *)malloc(sizeof(NODE));
		do
		{
			char ch_temp;
			ch_temp=fgetc(fp);
		}while(ch_temp==' ');
		fseek(fp,-1,1);
		for(int i=0;i<30;i++)
			newnode->param_words->word[i]=arr_temp[i];
		newnode->param_words->wd_num++:
		newnode->param_words->comp_value=value_word(\
		newnode->param_words->word);
		newnode->next_node==NULL;

		node_temp->next_node=newnode;
		node_temp=newnode;
	}
	fclose(fp);
	return list_words;
}



int value_word(const char arr[])
{
	int value_temp=0;
	
	for (int i=0;arr[i]!='\0';i++)
	{
		if(arr[i]>='A'&&arr[i]<='Z')
			arr[i]+=32;
		value_temp+=(arr[i]-96)*(i+1);
	}
	
	return value_temp;
}

















	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	for(int i=0;filename[i]!=' ';i++)
	{
		fgetc(newnode->word->word[i],fp);
		

