#ifndef _STREAM_PARSE_H_
#define _STREAM_PARSE_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
	sb->buf			  = (char *)malloc(sizeof(char)*capacity);
	sb->capacity      = capacity;
	sb->head 		  = sb->tail = 0;
	return sb;
}

void stream_buffer_destroy(stream_buffer *sb)
{
	if(sb->buf)
		free(sb->buf);
	if(sb)
		free(sb);
}

static void stream_buffer_insert_word(stream_buffer *sb,
						char *word, int len)
{
	if(stream_buffer_is_empty(sb) == 0)
		sb->tail = sb->head;
	for(int i=0 ; i<len ; i++)
	{
		sb->buf[sb->tail] = word[i];
		sb->tail = (sb->tail+1)%sb->capacity;
	}
	sb->buf[sb->tail++] = '\0';
}

static int stream_buffer_get_word(stream_buffer *sb, char *word)
{
	extern int errno;

	if(stream_buffer_is_empty(sb))
		return 1;
	else
	{
		for(int i=0 ; sb->head!=sb->tail && i<len ; i++)
		{
			word[i]  = sb->buf[sb->head];
			sb->head = (sb->head+1)%sb->capacity;
		}
		return 0;
	}
}

static inline int stream_buffer_is_empty(stream_buffer *sb)
{
	if(sb->tail == sb->head)
		return 1;
	else 
		return 0;
}

static inline int stream_buffer_empty_size(stream_buffer *sb)
{
	return ((sb->tail - sb->head + sb->capacity) % sb->capacity);
}

/*
 * 数据输入
 * 实现方式可以为从一个文件或者一个网络，读取相应内容
 * 考虑文本特殊情况包括：各种标点符号，字符大小写，换行，空行等的处理
 */
char *stream_input_parse(char *path);

#endif
