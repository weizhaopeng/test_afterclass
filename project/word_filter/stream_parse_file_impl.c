#include "stream_parse.h"

static inline int stream_buffer_fp_skip(FILE *fp);

int stream_input_parse(stream_buffer *sb, char *path)
{
	FILE	  *fp;
	char 	  *word, char_temp;
	int 	   ret, file_end = 1;
	
	fp = fopen(path, "r+");
	if (fp == NULL) {	
		perror("");
		return ENOENT;
	}

	word = (char *)malloc(sizeof(char)*WORD_SIZE);
	if (!word)
		return ENOMEM;

	while (file_end) {
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
				ret = stream_buffer_fp_skip(fp);
    			if (ret == 0) {
					word[posi] = '\0';
					break;
				}
				else {
					word[posi] = '\0';
					fclose(fp);
					file_end = 0;
					break;
				}
			}
		} while(1);
		
		ret = stream_buffer_insert_word(sb, word, strlen(word));
		if (ret == WF_SB_FULL) {
			free(word);
			fclose(fp);
			return WF_SB_FULL;
		}
	}
	free(word);
	return 0;
}
       
static inline int stream_buffer_fp_skip(FILE *fp)
{
	char char_temp;

    do {
		char_temp=fgetc(fp);
        if(char_temp == EOF)
            return (int)EOF;
    } while(char_temp < 'A' || (char_temp > 'Z' && char_temp < 'a') || 
			char_temp > 'z');
    fseek(fp,-1L,1);
    return 0;
}

