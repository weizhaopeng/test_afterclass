#include <stdio.h>
#include <stdlib.h>
#include <stream_parse.h>
#include <error_check.h>

#define WORD_SIZE 20

static inline int stream_buffer_fp_skip_space(FILE *fp);
/*return ENOENT, ENOMEM, WF_SB_FULL, 0*/
int stream_input_parse(stream_buffer *sb, char *path)
{
	FILE	  *fp;
	char 	  *word, char_temp;
	uint32_t   posi = 0;
	int 	   ret;
	
	fp = fopen(path, "r+");
	if (fp == NULL)
	{	
		perror("");
		return ENOENT;
	}

	word = (char *)malloc(sizeof(char)*WORD_SIZE);
	if (!word)
		return ENOMEM;

	while (1) {
		do {
			char_temp = fgetc(fp);
			if (char_temp>='A' && char_temp<='z' || char_temp>='a' && char_temp<='z')
				word[posi++] = char_temp;
			else {
				ret = stream_buffer_fp_skip_space(fp);
    			if (ret == 0) {
					word[posi] = '\0';
					break;
				}
				else 
					return 0;
			}
		} while(1);
		
		ret = stream_buffer_insert_word(sb, word, strlen(word));
		if (ret == WF_SB_FULL)
			return WF_SB_FULL;
	}
}
       
static inline int stream_buffer_fp_skip_space(FILE *fp)
{
	char char_temp;
    do {
		char_temp=fgetc(fp);
        if(char_temp==EOF)
            return (int)EOF;
    } while(char_temp<'A'||(char_temp>'Z'&&char_temp<'a')||char_temp>'z');
    fseek(fp,-1L,1);
    return 0;
}
 
