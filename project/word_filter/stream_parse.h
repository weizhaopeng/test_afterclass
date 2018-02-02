#ifndef _STREAM_PARSE_H_
#define _STREAM_PARSE_H_

/*
 * 数据流缓冲区
 * 实现为一个环形队列
 */
typedef struct {
	uint32_t  capacity;
	uint32_t  head;
	uint32_t  tail;
	char     *buf;
} stream_buffer;

static inline stream_buffer *stream_buffer_create(uint32_t capacity)
{
	stream_buffer *sb = (stream_buffer *)malloc(sizeof(stream_buffer));
	sb->buf           = (char *)malloc(sizeof(char)*(capacity+1));
	sb->capacity      = capacity;
	sb->head 		  = sb->tail = 0;
	return sb;
}

static inline void stream_buffer_destroy(stream_buffer *sb)
{
	for( ; sb->head < sb->tail ; sb->tail--);
		free(*(sb->buf+sb->tail));
	free(sb);
}

static inline void stream_buffer_insert_word(stream_buffer *sb,
						char *word, int len)
{
	char *char_temp = (char)malloc(sizeof(char)*len);
	for(int i=0 ; i<len ; i++)
		*(char_temp+i) = *(word+i);
	*(char_temp+i) = '\0';
	sb->tail++;
	*(buf+sb->tail) = char_temp;
}

static inline int stream_buffer_get_word(stream_buffer *sb,
						char *word, int len)
{
	
}

static inline bool stream_buffer_is_empty(steam_buffer *sb)
{
	if(sb->head == sb->tail)
		return TRUE;
	else 
		return FALSE;
}

static inline int stream_buffer_empty_size(stream_buffer *sb)
{
	return capacity-(tail-head+1)-1;
}

/*
 * 数据输入
 * 实现方式可以为从一个文件或者一个网络，读取相应内容
 * 考虑文本特殊情况包括：各种标点符号，字符大小写，换行，空行等的处理
 */
int stream_input_parse(char *path);

#endif
