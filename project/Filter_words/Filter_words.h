#ifndef _FILTER_WORDS_
#define _FILTER_WORDS_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

/*the length of word*/
#define MAX 20
/*the number of words to show*/
#define NUMBER_SHOW 10


/*word information*/
typedef struct{
	char word[MAX];
	long word_number;
}WORD; 

/*list's node information*/
typedef struct node{
	WORD *word_content;
	struct node *node_next;
}NODE;
typedef NODE * LIST_WORDS; 

/*Boolean value*/
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
