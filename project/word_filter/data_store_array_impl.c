#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <data_store.h>

/*
 * 动态数组的实现形式
 */
typedef struct {
	uint32_t           capacity;
	uint32_t           use;
	data_store_object *set;
} data_store_array;

static inline void unit_exchange(data_store_object obj1, data_store_object obj2)
{
	char *word_temp;
	int   count_temp;

	word_temp = obj2.word;
	obj2.word = obj1.word;
	obj1.word = word_temp;

	count_temp = obj2.count;
	obj2.count = obj1.count;
	obj1.count = count_temp;
}

data_store *data_store_create(void)
{
	data_store *ds 			   = NULL;
	data_store_array *ds_array = NULL;

	ds_list = (data_store_array *)malloc(sizeof(data_store_array)*capacity);
	if(!ds_array) 
		return NULL;

	ds = (data_store *)malloc(sizeof(data_store));
	if(!ds) 
		return NULL;

	ds->type = DATA_STORE_TYPE_ARRAY;
	ds->priv = ds_array;
}

void data_store_destroy(data_store *ds)
{
	for(uint32_t i = 0; i < ds->priv->use; i++)
		free(ds->priv->set);
	free(ds->priv);
	free(ds);
}

int data_store_insert_count(data_store *ds, char *word)
{
	extern int errno;
	uint32_t i;

	for(i=0 ; i<ds->priv->use ; i++)
	{
		if(strcmp(word, ds->priv->set[i]) == 0) {
			ds->priv->set[i].count++;
			return errno;
		}
	}

	if (ds->priv->use) {
		ds->priv->set[0].word  = word;
		ds->priv->set[0].count = 1;
	}
	else {
		ds->priv->set[use-1].word  = word;
		ds->priv->set[use-1].count = 1;
		ds->count++;
	}
	return errno;
}

int data_store_get_max_count(data_store *ds, data_store_object *set, int index)
{
	extern int errno;

	for(uint32_t i = 0; i < index; i++)
	{
		if(ds->priv->set[i]) {
			set[i].word  = ds->priv->->set[i].word;
			set[i].count = ds->priv->->set[i].count;
		}
		else
			set[i] = NULL;
	}
	return errno;

}

int data_store_sort(data_store *ds)
{
	uint32_t i, j;
	extern int errno;
	
	for(i = 0; i < ds->priv->use; i++) {
		for(j = i; j <ds->priv->use; j++) {
			if(ds->priv->set[j].count > ds->priv->set[i].count) 
				unit_exchange(ds->priv->set[i], ds->priv->set[j]);
		}
	}
	return errno;
}
