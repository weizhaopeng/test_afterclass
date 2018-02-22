#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include "data_store.h"
#include "stream_parse.h"
#include "error_check.h"

#define  CAPACITY 1024

int errno;

int main(int argc, char **argv)
{
	//step1: 解析参数，参数应该包括需要读取的文件名或者一个网络地址
	for (int i=1 ; i<argc ; i++)
	{
		char  *path = argv[i], *word;
		size_t len;
	//step2: 对象初始化，初始化stream buffer和data store
		stream_buffer 	  *sb;
		data_store	  	  *ds;
		data_store_object *set;

		sb  = stream_buffer_create(CAPACITY);
		ds  = data_store_create();
		set = (data_store_object *)malloc(sizeof(data_store_object)*10);
	//step3: stream input流程处理，包括将处理好的word存进stream buffer
		do {
			word = stream_input_parse(path);
			if (word == NULL)
				break;
			len = strlen(word);
			stream_buffer_insert_word(sb, word, len);
		} while(1);		
	//step4: 依次将stream buffer中的word存进data store中
		extern int errno;
		while (1)
		{
			errno = stream_buffer_get_word(sb, word);
			if(errno)
			{
				perror("");
				exit(-1);
			}
			else
				data_store_insert_count(ds, word);
		}
	//step5: 对data store进行排序，然后获取个数最多的10个word，打印
		errno = data_store_sort(ds);
		data_store_error_check(errno);

		errno = data_store_get_max_count(ds, set, 10);
		data_store_error_check(errno);

		data_store_print_max_count(set);
		stream_buffer_destory	  (sb);
		data_store_destroy		  (ds);
		return 0;
	}
	//备注：有空可以考虑一下，为什么对数据进行多份存储，以及为什么对框架进行这种划分？
}
