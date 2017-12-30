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

typedef struct{
	WORD *word_content;
	NODE *node_next;
}NODE;

typedef NODE* LIST_WORDS; 

typedef enum{
	FALSE,
	TRUE
};

LIST_WORDS FW_readin(void);
void 	   FW_print (LIST_WORDS *list_words);

NODE*	   creat_node	(FILE *fp);
NODE*	   classify_word(FILE *fp);
void  	   fp_skip_space(FILE *fp);
BOOL 	   match_node	(const LIST_WORDS *list_words,const int comp_value);
int 	   comp_value	(const char arr[]);
void 	   sort_list 	(const LIST_WORDS *list_words,const NODE *newnode);
void 	   file_print	 ();
FILE*	   acknowledge_fp();



#endif
