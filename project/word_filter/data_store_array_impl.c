#include "data_store.h"

#ifdef DATA_STORE_ARRAY
/*
 * 动态数组的实现形式
 */
typedef struct {
	uint32_t           capacity;
	uint32_t           use;
	data_store_object *set;
} data_store_array;

static inline int data_store_array_expand(data_store_array *ds_array)
{
	uint32_t capacity;

	if (sizeof(data_store_object)*ds_array->capacity <= 1024*1024) {
		capacity = sizeof(data_store_object)*ds_array->capacity*2;
		ds_array = (data_store_array *)realloc\
			(ds_array, capacity);
		ds_array->capacity = capacity;
	}
	else {
		capacity = sizeof(data_store_object)*ds_array->capacity+1024*1024;
		ds_array = (data_store_array *)realloc\
			(ds_array, capacity);
		ds_array->capacity = capacity;
	}

	if (!ds_array)
		return ARRAY_EXPAND_FAIL;
	else 
		return 0;
}

static inline int unit_find(data_store_array *ds_array, char *word)
{
	int unit_number = -1;

	for(int i = 0; i < ds_array->use; i++) {
		if(strcmp(word, ds_array->set[i].word) == 0)
			return i;
	}
	return -1;
}

static inline void unit_exchange(data_store_object *obj1, data_store_object *obj2)
{
	char *word_temp;
	int   count_temp;

	word_temp   = obj2->word;
	obj2->word  = obj1->word;
	obj1->word  = word_temp;

	count_temp  = obj2->count;
	obj2->count = obj1->count;
	obj1->count = count_temp;
}

data_store *data_store_create(int capacity)
{
	data_store *ds 			   = NULL;
	data_store_array *ds_array = NULL;

	ds_array = calloc(1, sizeof(data_store_array));
	if(!ds_array) 
		return NULL;
	ds_array->set 	   = (data_store_object *)\
		calloc(1, sizeof(data_store_object)*capacity);
	ds_array->capacity = capacity;
	ds_array->use	   = 0;

	ds = (data_store *)calloc(1, sizeof(data_store));
	if(!ds) 
		return NULL;

	ds->type = DATA_STORE_TYPE_ARRAY;
	ds->priv = ds_array;
	return ds;
}

void data_store_destroy(data_store *ds)
{
	data_store_array *ds_array;
	
	ds_array = (data_store_array *)ds->priv;
	for(uint32_t i = 0; i < ds_array->use; i++) {
		if (ds_array->set[i].word)
			free(ds_array->set[i].word);
	}
	if (ds_array->set)
		free(ds_array->set);
	if (ds_array)
		free(ds_array);
	if (ds)
		free(ds);
}

int data_store_insert_count(data_store *ds, char *word)
{
	uint32_t i;
	int unit_number, ret;
	data_store_array *ds_array;

	ds_array 	= (data_store_array *)ds->priv;
	unit_number = unit_find(ds_array, word);
	if (unit_number >= 0 && ds_array->use)
		ds_array->set[unit_number].count++;

	if (unit_number == -1) {
		if (ds_array->use == ds_array->capacity) {
			ret = data_store_array_expand(ds_array);
			if (ret == ARRAY_EXPAND_FAIL)
				return WF_WORD_INSERT_FAIL;
		}

		ds_array->set[ds_array->use].word  = \
			(char *)calloc(1, strlen(word)+1);
		strcpy(ds_array->set[ds_array->use].word, word);
		ds_array->set[ds_array->use].count = 1;
		ds_array->use++;
	}
	return WF_WORD_INSERT_OK;
}

void data_store_get_max_count(data_store *ds, data_store_object *set, int index)
{
	data_store_array *ds_array;

	ds_array = (data_store_array *)ds->priv;
	for(int i = 0; i < index; i++)
	{
		if (i < ds_array->use) {
			set[i].word  = ds_array->set[i].word;
			set[i].count = ds_array->set[i].count;
		}
		else {
			set[i].word  = NULL;
			set[i].count = 0;
		}
	}
}

int data_store_sort(data_store *ds)
{
	uint32_t i, j;
	data_store_array *ds_array;
	
	ds_array = (data_store_array *)ds->priv;
	if (ds_array->use <= 0)
		return WF_DATA_STORE_EMPTY;

	for(i = 0; i < ds_array->use; i++) {
		for(j = i+1; j < ds_array->use; j++) {
			if(ds_array->set[j].count > ds_array->set[i].count) 
				unit_exchange(ds_array->set+i, ds_array->set+j);
		}
	}
	return 0;
}

void data_store_print_max_count(data_store_object *set, char *path)
{
	system("clear");
	printf("\033[40;32m******当前文档%s中单词数前十的单词统计******\n\033[0m",path);
	printf("\033[47;30m单词\t\t\t\t\t\t单词数\n\033[0m");
	for (int i = 0; i < WF_WORD_PRINT_NUMBER && set[i].word; i++)
		printf("\033[40;31m%-30s\t\t\t%5d\n\033[0m",set[i].word,set[i].count);
	printf("\n");
	printf("\033[47;30m点击回车继续\033[0m\n");
	getchar();
	return;
}

data_store_object *data_store_object_array_creat(uint32_t object_number)
{
	data_store_object *set;

	set = (data_store_object *)calloc(1, sizeof(data_store_object)*object_number);
	if (!set)
		return NULL;
	return set;
}
	
void data_store_object_array_destroy(data_store_object *set, uint32_t object_number)
{
	free(set);
}

#endif
