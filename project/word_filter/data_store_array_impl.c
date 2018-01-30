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

data_store *data_store_create(void)
{

}

void data_store_destroy(data_store *ds)
{
	

}

int data_store_insert_count(data_store *ds, char *word)
{
	
}

int data_store_get_max_count(data_store *ds, data_store_object *set, int index)
{


}

int data_store_sort(data_store *ds)
{

}
