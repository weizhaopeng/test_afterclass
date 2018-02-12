#include others
#include <data_store.h>
#include <stream_parse.h>

#define  CAPACITY 

int main(int argc, char **argv)
{
	//step1: 解析参数，参数应该包括需要读取的文件名或者一个网络地址
	for(int i=1 ; i<argc && argv[i] ; i++)
	{
		char *path = argv[i];
		size_t len;

		word = stream_input_parse(*(argv+i));
		len  = strlen(word);
	//step2: 对象初始化，初始化stream buffer和data store
		stream_buffer *sb;
		data_store	  *ds;
		data_store_objexct *set;

		sb = stream_buffer_create(CAPACITY);
		ds = data_store_create();
		set = (data_store_object *)malloc(sizeof(data_store_object)*10);
	//step3: stream input流程处理，包括将处理好的word存进stream buffer
		char  *word;
		size_t len;

		do {
			word = stream_input_parse(path);
			len  = strlen(word);
			if(word)
				stream_buffer_insert_word(sb, word, len);
		} while(1);		
	//step4: 依次将stream buffer中的word存进data store中
		extern int errno = 0;
		for( ; ; )
		{
			errno = stream_buffer_get_word(sb, word);
			if(errno)
			{
				strerror(errno);
				exit(-1);
			}
			else
				data_store_insert_count(ds, word);
		}
	//step5: 对data store进行排序，然后获取个数最多的10个word，打印
		data_store_sort(ds);
		data_store_get_max_count(ds, set, 10);
		data_store_print_max_count(set);
		return 0;
	}
备注：有空可以考虑一下，为什么对数据进行多份存储，以及为什么对框架进行这种划分？
}
