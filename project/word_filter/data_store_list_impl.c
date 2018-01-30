#include others
#include <data_store.h>


/*
 * 双向链表的实现形式
 */
typedef struct {
	data_store_object    *obj;
	data_store_list_node *next;
	data_store_list_node *prev;
} data_store_list_node;

typedef struct {
	data_store_list_node *head;
	data_store_list_node *tail;
	uint32_t              count;
} data_store_list;

/*list operations here!*/
static data_store_list_node *node_find(char *word)
{

}

static int node_insert(char *word)
{

}

static void node_free(data_store_list_node *node)
{

}

static void node_count_inc(data_store_list_node *node)
{

}

data_store *data_store_create(void)
{
	data_store      *ds      = NULL;
	data_store_list *ds_list = NULL;

	ds_list = malloc(sizeof(data_store_list));
	if (!ds_list)
		return NULL;

	ds = malloc(sizeof(data_store));
	if (!ds) {
		free(ds_list);
		return NULL;
	}

	ds->type = DATA_STORE_TYPE_LIST;
	ds->priv = ds_list;

	return ds;
}

void data_store_destroy(data_store *ds)
{
	foreach list node:
		node_free(node);
	free(ds->priv);
	free(ds);

}

int data_store_insert_count(data_store *ds, char *word)
{
	data_store_list_node *node = NULL;

	node = node_find(word);
	if (node) {
		node_count_inc(node);
		return 0;
	}

	node = malloc() and init
}

int data_store_get_max_count(data_store *ds, data_store_object *set, int index)
{


}

int data_store_sort(data_store *ds)
{

}
