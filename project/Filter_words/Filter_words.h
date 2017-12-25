#ifndef _FILTER_WORDS_
#define _FILTER_WORDS_

#define MAX 20
#include"general_header.h"

/*程序数据结构*/
typedef struct
{
	char word[MAX];
	long wd_num;
	int comp_value;
}NODE_INFO;

typedef struct
{
	NODE_INFO *word；
	NODE *next_node;
}NODE;

typedef NODE* LIST;


