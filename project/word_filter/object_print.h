#include <stdio.h>

static void data_store_print_max_count(data_store_object *set)
{
	system("clear");
	printf("\033[40;32m******当前文档中单词数前十的单词统计******\n\033[0m");
	printf("\033[47;30m单词\t\t\t单词数\n\033[0m");
	for (int i=0 ; i<10 ; i++) {
		printf("\033[40;31m%s\t\t\t%d\n\033[0m",set[i]->word,set[i]->count);
	printf("\n");
	}
}
