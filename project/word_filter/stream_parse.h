#ifndef _STREAM_PARSE_H_
#define _STREAM_PARSE_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_check.h"

#define WF_SB_EMPTY  	 0x00
#define WF_SB_NOTEMPTY 	 0x01

#define WF_SB_FULL 		 0x01
#define WF_SB_NOTFULL	 0x00

#define WORD_GET_OK	 	 0x00 
#define WORD_GET_FAIL	 0X01
#define WORD_INSERT_OK 	 0x00

#define WORD_SIZE 		 0x14

#define WF_SB_CAPACITY   (1024*30)
/*
 * 数据流缓冲区
 * 实现为一个环形队列
 */
typedef struct stream_buffer {
	uint32_t  capacity;
	uint32_t  head;
	uint32_t  tail;
	char     *buf;
} stream_buffer;

static inline int stream_buffer_is_empty(stream_buffer *sb);

static inline int stream_buffer_empty_size(stream_buffer *sb);

static inline stream_buffer *stream_buffer_create(uint32_t capacity)
{
	stream_buffer *sb; 

	sb = (stream_buffer *)malloc(sizeof(stream_buffer));
	if (!sb)
		return NULL;

	sb->buf	= (char *)malloc(sizeof(char)*capacity);
	if (!sb->buf)
		return NULL;

	sb->capacity      = capacity;
	sb->head 		  = sb->tail = 0;
	return sb;
}

static inline void stream_buffer_destroy(stream_buffer *sb)
{
	if(sb->buf)
		free(sb->buf);
	if(sb)
		free(sb);
}

static inline int stream_buffer_insert_word(stream_buffer *sb,
						char *word, int len)
{
	if (stream_buffer_empty_size(sb) <= len)
		return WF_SB_FULL;
	else {
		for(int i = 0; i < len; i++) {
			sb->buf[sb->tail] = word[i];
			sb->tail = (sb->tail+1)%sb->capacity;
		}
		sb->tail = (sb->tail+1)%sb->capacity;
		sb->buf[sb->tail] = '\0';
		return WORD_INSERT_OK;
	}
}

static inline int stream_buffer_get_word(stream_buffer *sb, char *word)
{
	int i = 0;

	while (sb->buf[sb->head] == '\0' && sb->head != sb->tail)
			sb->head  = (sb->head+1)%sb->capacity;
		
	while(sb->buf[sb->head] != '\0' && sb->head != sb->tail) {
		if (sb->head == sb->tail)
			break;

		word[i++]   = sb->buf[sb->head];
		sb->head  = (sb->head+1)%sb->capacity;
	}
	word[i] = '\0';

	if (sb->head == sb->tail)
		return WORD_GET_FAIL;

	return WORD_GET_OK;
}

static inline int stream_buffer_is_empty(stream_buffer *sb)
{
	if(sb->tail == sb->head)
		return WF_SB_EMPTY;
	else 
		return WF_SB_NOTEMPTY;
}

static inline int stream_buffer_empty_size(stream_buffer *sb)
{
	return (sb->capacity-(sb->tail - sb->head + sb->capacity) % sb->capacity-1);
}

/*
 * 数据输入
 * 实现方式可以为从一个文件或者一个网络，读取相应内容
 * 考虑文本特殊情况包括：各种标点符号，字符大小写，换行，空行等的处理
 */
int stream_input_parse(stream_buffer *sb, char *path);

#endif
