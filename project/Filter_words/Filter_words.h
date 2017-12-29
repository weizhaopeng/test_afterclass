#ifndef _FILTER_WORDS_
#define _FILTER_WORDS_

#define MAX 20
#include"general_header.h"

/*程序数据结构*/
typedef struct
{
	char word_spell[MAX];
	long word_number;
	int  word_value;
}WORD; 

typedef struct
{
	WORD *word;
	NODE *node_next;
}NODE;

typedef NODE* LIST_WORDS; 


#endif
