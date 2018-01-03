#ifndef _FILTER_WORDS_
#define _FILTER_WORDS_

#define MAX 20

#include"general_header.h"

/*每个单词存储的数据*/
typedef struct{
	char word[MAX];
	long word_number;
	int  word_value;
}WORD; 

typedef struct node{
	WORD *word_content;
	struct node *node_next;
}NODE;

typedef NODE * LIST_WORDS; 

typedef enum{
	FALSE,
	TRUE
}BOOL;
/*generate a linked list containing word information of the document content extracted.*/ 
LIST_WORDS FW_readin(void);
FILE* acknowledge_fp();
void  classify_word(LIST_WORDS list_words,FILE *fp);
BOOL  match_node	(const LIST_WORDS list_words,const int comp_value);
int   comp_value	(char arr[]);
void  file_error    (FILE *fp);
NODE* creat_node	(FILE *fp);
void  fp_skip_space (FILE *fp);
/*print the link_list generate from the English file*/
void  FW_print (LIST_WORDS list_words);
void  file_print    ();





#endif
