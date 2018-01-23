#include"Filter_words.h"
int main(void)
{
	LIST_WORDS list_words;
	list_words=FW_readin();
	
	FW_print(list_words);
	return 0;
}

