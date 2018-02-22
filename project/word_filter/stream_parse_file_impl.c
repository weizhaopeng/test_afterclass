#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "stream_parse.h"

#define WORD_SIZE 20

static inline int stream_buffer_fp_skip_space(FILE *fp);

char *stream_input_parse(char *path)
{
	FILE	  *fp;
	char 	  *word, char_temp;
	uint32_t   posi = 0;
	extern int errno;
	
	fp = fopen(path, "r+");
	if (fp == NULL)
	{	
		perror("");
		return NULL;
	}

	word = (char *)malloc(sizeof(char)*WORD_SIZE);
	do {
		char_temp = fgetc(fp);
		if(char_temp>='A' && char_temp<='z' || char_temp>='a' && char_temp<='z')
			word[posi++] = char_temp;
		else
    		if(stream_buffer_fp_skip_space(fp) == 0)
			{
				word[posi] = '\0';
        		return word;
			}
		word[posi] = '\0';
	} while(posi < WORD_SIZE);
}
       
static inline int stream_buffer_fp_skip_space(FILE *fp)
{
	char char_temp;
    do {
		char_temp=fgetc(fp);
        if(char_temp==EOF)
            return 0;
    } while(char_temp<'A'||(char_temp>'Z'&&char_temp<'a')||char_temp>'z');
    fseek(fp,-1L,1);
    return 1;
}
 
