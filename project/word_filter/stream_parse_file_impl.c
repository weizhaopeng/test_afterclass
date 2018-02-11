#include others
#include <stream_parse.h>

char *stream_input_parse(char *path)
{
	FILE	*fp;
	uint32_t posi;
	char 	*word, char_temp;
	
	fp = fopen(path, r+);
	do {
		char_temp = (char)fgetc(fp);
		if(char_temp>='A' && char_temp<='z' || char_temp>='a' && char_temp<='z')
			word[posi++] = char_temp;
		else
		{
			posi++;
			break;
		}
	}while(1);
	word[posi] = '\0';

    if(fp_skip_space(fp)==FALSE)
        return NULL;
    else
        return word;
}
       
static bool fp_skip_space(FILE *fp)
{
	char char_temp;
    do{
		char_temp=fgetc(fp);
        if(char_temp==EOF)
            return FALSE;
    }while(char_temp<'A'||(char_temp>'Z'&&char_temp<'a')||char_temp>'z');
    fseek(fp,-1L,1);
    return TRUE;
}
 
