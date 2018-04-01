#ifndef _DATA_STORE_H_
#define _DATA_STORE_H_

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WF_WORD_INSERT_FAIL   0x01
#define WF_WORD_INSERT_OK	  0x00

#define ARRAY_EXPAND_FAIL 	  0x01

#define WF_DATA_STORE_EMPTY   0x01
#define WF_OBJ_ARRAY_EMPTY    0x01

#define WF_ARRAY_CAPACITY	  100
#define WF_WORD_PRINT_NUMBER  20
#define WORD_LENGTH_MAX  	  0x14

/*
 * 数据存储模块，实现形式可以为链表、数组或散列表。
 * 0x01指的是2位16进制数，转换成正数是1
 */
typedef enum {
	DATA_STORE_TYPE_LIST  = 0x01,
	DATA_STORE_TYPE_ARRAY,
	DATA_STORE_TYPE_HASH
} data_store_type;

/*
 * 数据存储对象结构体，type表示具体的实现形式，priv为私有数据区
 * 私有数据区用来指向不同实现的对象地址，比如数据存储模块使用链表方式实现，priv则指向
 * uint32_t指的是32位无符号类型整形数据
 */
typedef struct {
	data_store_type type;
	void           *priv;
} data_store;

typedef struct {
	char    *word;
	uint32_t count;
} data_store_object;

/*
 * 数据存储对象的创建和销毁
 */
data_store *data_store_create(int capacity);
void        data_store_destroy(data_store *ds);

/*
 * 数据的插入和按序查询
 */
int  data_store_insert_count(data_store *ds, char *word);
void data_store_get_max_count(data_store *ds, data_store_object *set, int index);

/*
 * 数据手动排序，按count的大小顺序
 */
int data_store_sort(data_store *ds);

/*
 *数据对象打印
 */
void data_store_print_max_count(data_store_object *set, char *peth);
	
/*
 *数据存储对象数组的创建和销毁
 */
void data_store_object_array_destroy(data_store_object *set, uint32_t object_number);
data_store_object *data_store_object_array_creat(uint32_t object_number);

static inline void wf_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}
#endif
