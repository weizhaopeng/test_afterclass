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

typedef NODE* LIST_WORDS; 

typedef enum{
	FALSE,
	TRUE
}BOOL;

LIST_WORDS FW_readin(void);
void 	   FW_print (LIST_WORDS list_words);

NODE* classify_word (LIST_WORDS list_words,FILE *fp);
NODE* creat_node	(FILE *fp);
void  fp_skip_space (FILE *fp);

BOOL  match_node	(const LIST_WORDS list_words,const int comp_value);
void  sort_list 	(LIST_WORDS list_words,NODE *newnode);
int   comp_value	(char arr[]);
void  file_error    (FILE *fp);
void  file_print    ();
FILE* acknowledge_fp();



#endif
