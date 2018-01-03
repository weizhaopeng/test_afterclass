#include"Filter_words.h"

LIST_WORDS FW_readin(void)
{
	FILE *fp;
	LIST_WORDS list_words;
	NODE *node_judge;
	
	fp=acknowledge_fp();

	list_words=creat_node(fp);
	/*add the new word into the linked list*/
	for(int i=0;feof(fp)==0;i++)
	{
        /*classify the new word into the link list*/
		classify_word(list_words,fp);
		fp_skip_space(fp);
	}
	fclose(fp);
	return list_words;
}



/*acknowledge the filename need read*/
FILE *acknowledge_fp()
{
	static char filename_read[MAX];
    FILE *fp;

	printf("\033[40;41mplease input the name of file\033[0m\n");
	scanf("%s",filename_read);
	fp=fopen(filename_read,"r+");
	file_error(fp);
	return fp;
}
/*check the error when open the file and read or write the file*/
void file_error(FILE *fp)
{
    if(fp==NULL){
        puts("open file error");
        exit(-1);
    }
    if(ferror(fp)!=0){
        puts("file read or write error");
        exit(-1);
    }
}
/*creat a node from the file to save the word and return the point of the node*/
NODE *creat_node(FILE *fp)
{
	NODE *node_new;
	node_new=(NODE *)malloc(sizeof(NODE));
    node_new->word_content=(WORD*)malloc(sizeof(WORD));

	fscanf(fp,"%s",node_new->word_content->word);
	file_error(fp);
	node_new->word_content->word_number++;
	node_new->word_content->word_value=comp_value(node_new->\
	word_content->word);
	node_new->node_next=NULL;

	fp_skip_space(fp);
	return node_new; 
}
/*creat a node according to the internal information the node*/
void classify_word(LIST_WORDS list_words,FILE *fp)
{
	int comp_value_newword;
	char array_temp[MAX];
	NODE *newnode,*node_temp=list_words;

	fscanf(fp,"%s",array_temp);
	file_error(fp);
	comp_value_newword=comp_value(array_temp);
	fp_skip_space(fp);
	
	if(match_node(list_words,comp_value_newword)==TRUE)
		return;
	else
	{
		newnode=(NODE *)malloc(sizeof(NODE));
        newnode->word_content=(WORD*)malloc(sizeof(WORD));

		newnode->word_content->word_number++;
		newnode->word_content->word_value=comp_value_newword;
		newnode->node_next==NULL;
		for(int i=0;i<MAX;i++)
			newnode->word_content->word[i]=array_temp[i];
        
        for(;node_temp->node_next!=NULL;)
            node_temp=node_temp->node_next;
        node_temp->node_next=newnode;
	}
	return;
}
/*input a word as a array and return the value computed*/
int comp_value(char arr[])
{
	int comp_value=0;
	
	for (int i=0;arr[i]!='\0';i++)
	{
		if(arr[i]>='A'&&arr[i]<='Z')
			arr[i]+=32;
		comp_value+=(arr[i]-96)*(i+1);
	}
	
	return comp_value;
}
/*input the point of file and skip the spaces to read the next word*/
void fp_skip_space(FILE *fp)
{
	char char_temp;
    do{
		char_temp=fgetc(fp);
    }while(char_temp<'A'||(char_temp>'Z'&&char_temp<'a')||char_temp>'z');
    fseek(fp,-1L,1);
}
/*if cthe value computed of a word equel to one node of the list, \
 *lassify and add it into the linked list
 */
BOOL match_node(const LIST_WORDS list_words,const int comp_value)
{
	NODE *node_temp=list_words;

	for(int i=0;;i++)
	{
		if(comp_value==node_temp->word_content->word_value)
		{
			node_temp->word_content->word_number++;
			return TRUE;
		}
		if(node_temp->node_next==NULL)
			return FALSE;
		node_temp=node_temp->node_next;
	}
}

		

