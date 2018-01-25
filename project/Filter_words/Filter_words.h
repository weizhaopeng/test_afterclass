#ifndef _FILTER_WORDS_
#define _FILTER_WORDS_

#define MAX 20
#define NUMBER_SHOW 10

#include"general_header.h"

/*每个单词存储的数据*/
typedef struct{
	char word[MAX];
	long word_number;
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

/*skip the chars which are not the letter*/
BOOL  fp_skip_space (FILE *fp);

/*print the link_list generate from the English file*/
void  FW_print (LIST_WORDS list_words);

#endif
