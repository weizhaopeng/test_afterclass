#include "stream_parse.h"

static inline int stream_buffer_fp_skip_space(FILE *fp);

int stream_input_parse(stream_buffer *sb, char *path)
{
	FILE	  *fp;
	char 	  *word, char_temp;
	int 	   ret;
	
	fp = fopen(path, "r+");
	if (fp == NULL) {	
		perror("");
		return ENOENT;
	}

	word = (char *)malloc(sizeof(char)*WORD_SIZE);
	if (!word)
		return ENOMEM;

	while (1) {
		int posi = 0;

		do {
			char_temp = fgetc(fp);

			if (char_temp>='A' && char_temp<='Z' || 
				char_temp>='a' && char_temp<='z' ||
				char_temp == '_')
			{
				if (char_temp >= 'A' && char_temp <= 'Z')
					char_temp = char_temp+32;
				word[posi++] = char_temp;
			}
			else
			{
				ret = stream_buffer_fp_skip_space(fp);
    			if (ret == 0) {
					word[posi] = '\0';
					break;
				}
				else {
					fclose(fp);
					return 0;
				}
			}
		} while(1);
		
		ret = stream_buffer_insert_word(sb, word, strlen(word));
		if (ret == WF_SB_FULL) {
			fclose(fp);
			return WF_SB_FULL;
		}
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
 
