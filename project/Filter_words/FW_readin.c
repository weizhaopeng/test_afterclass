#include"Filter_words.h"

LIST_WORDS FW_readin(void)
{
	char filename_read[MAX];
	char char_temp;
	char array_temp[MAX];
	int  comp_value_newword;
	FILE *fp;
	LIST_WORDS *list_words,*node_last,*node_temp,*node_new;
	
	/*open the file*/
	filename_read=acknowledge_filename();
	fp=fopen(filename_read,"r+");
	file_error(fp);

	/*creat the linked list and the first node to stoage the words*/
	list_words=node_last=creat_node(fp);

	/*add the new word into the linked list*/
	for(int i=0;feof(fp)!=0;i++)
	{
		fscanf(fp,"%s",array_temp);
		file_error(fp);
		comp_value_newword=value_word(array_temp);
		fp_skip_space(fp);
		
		if(classify_word(list_words,comp_temp)==true)
			continue;
		else
		{
			/*creat a new node*/
			newnode=generate_node(array_temp);
			sort_list(list_words,newnode);
		}
	}
	fclose(fp);
	return list_words;
}
/*acknowledge the filename need read*/
char *acknowledge_filename()
{
	static char filename_read[MAX];

	printf("\033[40;41mplease input the name of file\n\033[0m");
	scanf("%s",filename_read);
	return filename;
}
/*creat a node from the file to save the word and return the point of the node*/
NODE *creat_node(const FILE *fp)
{
	NODE *node_new;
	node_new=(NODE *)malloc(sizeof(NODE));
	fscanf(fp,"%s",node_new->word->word_spell);
	file_error(fp);
	node_new->word->word_number++;
	node_new->word->word_value=comp_value(node_new->word->word_spell);
	node_new->node_next=NULL;
	
	return node_new;
}
/*creat a node according to the internal information the node*/
NODE *generate_node(const char arr[])
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->word->word_number++;
	newnode->word->word_value=comp_value(arr);;
	newnode->node_next==NULL;
	for(int i=0;i<MAX;i++)
		newnode->word->word_spell[i]=arr[i];

	return newnode;
}
/*input a word as a array and return the value computed*/
int comp_value(const char arr[])
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
void fp_skip_space(const FILE *fp)
{
	char char_temp;
	for(int i=0;char_temp==' ';i++)
		char_temp=fgetc(fp);
	fseek(fp,-1L,1);
}
/*if cthe value computed of a word equel to one node of the list, \
 *lassify and add it into the linked list
 */
bool classify_word(const LIST_WORDS list_words,const int comp_value)
{
	NODE *node_temp=list_words;

	for(int i=0;;i++)
	{
		if(comp_value==node_temp->word->word_value)
		{
			node_temp->word->word_number++;
			return true;
		}
		if(node_temp->node_next==NULL)
			return false;
		node_temp=node_temp->node_next;
	}
}
/*sort the nodes of linked list as the value computed in the process\
 *of creating the linked list
 */
void sort_list(LIST_WORDS *list_words,NODE *newnode)
{
	NODE *node_temp=list_words;
	for(int i=0;;i++)
	{
		if(newnode->word->word_value<=node_temp->word->word_value)
		{
			newnode->node_next=node_temp->node_next;
			node_temp->node_next=newnode;
		}
		node_temp=node_temp->node_next;
	}
}
			













		

