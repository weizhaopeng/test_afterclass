#include "data_store.h"
#include "stream_parse.h"

#define  CAPACITY 1024

void stream_buffer_destroy(stream_buffer *sb);

int main(int argc, char **argv)
{
	//step1: 解析参数，参数应该包括需要读取的文件名或者一个网络地址
	char  *path = argv[i], *word;
	size_t len;
	int    ret;
	for (int i=1 ; i<argc ; i++)
	{
	//step2: 对象初始化，初始化stream buffer和data store
		stream_buffer 	  *sb;
		data_store	  	  *ds;
		data_store_object *set;

		sb  = stream_buffer_create(CAPACITY);
		if (!sb) {
			puts("memory error!");
			continue;
		}
	
		ds  = data_store_create();
		if (!ds) {
			puts("memory error!");
			continue;
		}

		set = (data_store_object *)malloc(sizeof(data_store_object)*10);
		if (!set) {
			puts("memory error!");
			return 1;
		}
	//step3: stream input流程处理，包括将处理好的word存进stream buffer
		ret = stream_input_parse(path);
		if (ret == ENOENT) {
			puts("no such file");
			continue;
		}
		if (ret == ENOMEM) {
			puts("memory error");
			continue;
		if (ret == WF_SB_FULL) {
			puts("stream_buffer full");
			continue;
		}
		}
	//step4: 依次将stream buffer中的word存进data store中
		while (1)
		{
			if(!stream_buffer_is_empty(sb))
				break;

			stream_buffer_get_word(sb, word);

			ret =data_store_insert_count(ds, word);
			if (ret == WF_WORD_INSERT_FAIL) {
				puts("word insert failed");
				continue;
			}
		}
	//step5: 对data store进行排序，然后获取个数最多的10个word，打印
		data_store_sort(ds);
			
		data_store_get_max_count(ds, set, 10);
			
		data_store_print_max_count(set);

		stream_buffer_destory	  (sb);
		
		data_store_destroy		  (ds);
		return 0;
	}
	//备注：有空可以考虑一下，为什么对数据进行多份存储，以及为什么对框架进行这种划分？
}
