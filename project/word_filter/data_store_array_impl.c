#include others
#include <data_store.h>

/*
 * 动态数组的实现形式
 */
typedef struct {
	uint32_t           capacity;
	uint32_t           use;
	data_store_object *set;
} data_store_array;

static data_store_object *unit_insert(char *word)
{
	data_store_object *obj;

	obj = (data_store_object *)malloc(sizeof(data_store_object));
	if(!obj) 
		return NULL;
		
	obj->word  = word;
	obj->count = 1;
	return obj;
}

static inline void unit_exchange(data_store_object *obj1, data_store_object *obj2)
{
	data_store_obj *obj_temp;
	
	obj_temp = obj2;
	obj2     = obj1;
	obj1	 = obj_temp;
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
		free(*(ds->priv->set+i));
	free(ds->priv);
	free(ds);
}

int data_store_insert_count(data_store *ds, char *word)
{
	uint32_t i;
	for(i = 0; i < ds->priv->use; i++)
	{
		if(strcmp(word, *(ds->priv->set+i)) == 0) {
			*(ds->priv->set+i)->count ++;
			return 0;
		}
	}
	
	*(ds->priv->set+i) = unit_insert(word);
	return 0;
}

int data_store_get_max_count(data_store *ds, data_store_object *set, int index)
{


}

int data_store_sort(data_store *ds)
{
	uint32_t i, j;
	
	for(i = 0; i < ds->priv->use; i++)
		for(j = i; j <ds->priv->use; j++)
		{
			if(*(ds->priv->set+j)->count > *(ds->priv->set+i)->count) 
				unit_exchange(*(ds->priv->set+i), *(ds->priv->set+j));
		}
	return 0;
}
