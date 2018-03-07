#include "data_store.h"
#include "stream_parse.h"


int stream_input_parse(stream_buffer *sb, char *path);

int main(int argc, char **argv)
{
	//step1: 解析参数，参数应该包括需要读取的文件名或者一个网络地址
	char  *path, *word;
	int    len, ret;
	//step2: 对象初始化，初始化stream buffer和data store
	stream_buffer 	  *sb;
	data_store	  	  *ds;
	data_store_object *set;

	for (int i=1 ; i<argc ; i++)
	{
		path = argv[i];

		sb  = stream_buffer_create(WF_SB_CAPACITY);
		if (!sb) {
			puts("memory error!");
			continue;
		}
	
		ds  = data_store_create();
		if (!ds) {
			puts("memory error!\n");
			continue;
		}

		set = data_store_object_array_creat(WF_WORD_PRINT_NUMBER, WORD_SIZE);
		if (!set) {
			puts("memory error!\n");
			return 1;
		}

		word = (char *)malloc(sizeof(char)*WORD_SIZE);
		if (!word) {
			puts("memory error!\n");
			return 1;
		}
	//step3: stream input流程处理，包括将处理好的word存进stream buffer
		ret = stream_input_parse(sb, path);
		if (ret == ENOMEM) {
			puts("memory error\n");
			continue;
		}
		if (ret == WF_SB_FULL) {
			puts("stream_buffer full\n");
			continue;
		}
	//step4: 依次将stream buffer中的word存进data store中
		while (1)
		{
			ret = stream_buffer_get_word(sb, word);
			if (ret == WORD_GET_FAIL)
				break;

			ret =data_store_insert_count(ds, word);
			if (ret == WF_WORD_INSERT_FAIL) {
				printf("word:%s insert failed\n",word);
				continue;
			}
		}
	//step5: 对data store进行排序，然后获取个数最多的10个word，打印
		ret = data_store_sort(ds);
		if (ret)
			puts("data store is empty\n");
		
		data_store_get_max_count	   (ds, set, WF_WORD_PRINT_NUMBER);
			
		data_store_print_max_count	   (set, path);

		data_store_object_array_destroy(set, WF_WORD_PRINT_NUMBER);
		stream_buffer_destroy	  	   (sb);
		data_store_destroy		  	   (ds);
		free(word);
	}
	return 0;
	//备注：有空可以考虑一下，为什么对数据进行多份存储，以及为什么对框架进行这种划分？
	/*多份存储便于根据数据类型选择执行效率更高的存储方式，这样的框架划分，将程序处理过程模块化，便于编程和排错*/
}
