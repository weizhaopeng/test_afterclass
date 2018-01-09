#include"Filter_words.h"

LIST_WORDS FW_readin(void)
{
	FILE *fp;
	LIST_WORDS list_words;
	NODE *node_judge;
    char *Array;
    /*acquire the point of file*/
	fp=acknowledge_fp();

    /*creat the linked list and the first node*/
    Array=AcquireWordFromFile(fp);
    if(Array==NULL)
    {
        puts("There are no words in the file, please check it");
        exit(-1);
    }
    else
    {
	    list_words=creat_node(Array);
        free(Array);
    }

	/*add the new word into the linked list*/
	do{
        char *ArrayTemp=AcquireWordFromFile(fp);
        if(ArrayTemp==NULL)
            break;
        else
            DivideWordIntoList(list_words,ArrayTemp);
        free(ArrayTemp);
	}while(1);
        
	fclose(fp);
	return list_words;
}


/*
 *
 *creat a node according to the internal information the node*/
void DivideWordIntoList(LIST_WORDS list_words,char *arr[])
{
	NODE *node_temp=list_words;
    int ValueComputed=comp_value(arr);
    
    do
	{
        /*if match the computed value in the link list, return the classify result*/
		if(ValueComputed==node_temp->word_content->word_value)
        {
			node_temp->word_content->word_number++;
            return ;
		}
        if(node_temp==NULL)
            break;
		node_temp=node_temp->node_next;
	}while(1);

    /*no match creat a new node to storage the word*/
    node_temp->node_next=creat_node(arr);
    return ;
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
/*
 *
 *
 *
 *
 *
 */
/*creat a node from the file to save the word and return the point of the node*/
NODE *creat_node(char *arr[])
{
	NODE *node_new;
	node_new=(NODE *)malloc(sizeof(NODE));
    node_new->word_content=(WORD*)malloc(sizeof(WORD));

    for(int i=0;i<MAX;i++)
       node_new->word_content->word[i]=arr[i];
	node_new->word_content->word_number++;
	node_new->word_content->word_value=\
    comp_value(node_new->word_content->word);
	node_new->node_next=NULL;

	return node_new; 
}
/*
 *
 *acquire a char* point from the file 
 *
 *
 */
char *AcquireWordFromFile(FILE *fp)
{
    char *array=(char *)malloc(sizeof(char)*MAX);

    fscanf(fp,"%s",array);
    file_error(fp);
    if(fp_skip_space(fp)==FALSE)
        return NULL;
    else
        return array;
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
/*input the point of file and skip the spaces to read the next word*/
BOOL fp_skip_space(FILE *fp)
{
	char char_temp;
    do{
		char_temp=fgetc(fp);
        if(char_temp==EOF)
            return FALSE;
    }while(char_temp<'A'||(char_temp>'Z'&&char_temp<'a')||char_temp>'z');

    fseek(fp,-1L,1);
    return TRUE;
}
/*
 *
 *
 *
 */

		

