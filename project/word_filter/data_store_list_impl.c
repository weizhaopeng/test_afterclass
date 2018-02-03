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
	data_store_list_node *node_temp;

	for (node_temp = ds_list->head; 
	node_temp && strcmp(word, node_temp->obj->word) != 0;
	node_temp = node_temp->next);

	return node_temp;
	
}

static data_store_list_node *node_insert(char *word)
{
	data_store_list_node *node_insert;

	node_insert      = (data_store_list_node *)malloc(sizeof(data_store_list_node));
	if(!node_insert) 
		node_insert = NULL;

	node_insert->obj = (data_store_object *)malloc(sizeof(data_store_object));
	if(!node_insert->obj) 
		node_insrt->obj = NULL;

	node_insert->obj->word  = word;
	node_insert->obj->count = 1;
	node_insert->prev   	= ds_list->tail;
	node_insert->next		= NULL;

	return node_insert;
}

static void node_free(data_store_list_node *node)
{
	free(node->obj->word);
	free(node->obj);
	free(node);
}

static void node_count_inc(data_store_list_node *node)
{
	node->obj->count++;
}

static void node_exchange(data_store_list_node *node1, data_store_list_node *node2)
{
	data_store_list_node *node_temp;

	node_temp   = node1->next;
	node1->next = node2->next;
	node2->next = node_temp;
	node_temp   = node1->prev;
	node1->prev = node2->prev;
	node2->prev = node_temp;
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
	data_store_list_node *node;

	for(node = ds->priv->priv->head; node; node = node->next) 
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

	node 				= node_insert(word);
	ds_list->tail->next = node_insert;
	ds_list->tail      	= node_insert;
	ds_list->count ++;
}

int data_store_get_max_count(data_store *ds, data_store_object *set, int index)
{
	data_store_list_node 

}

void data_store_sort(data_store *ds)
{
	data_store_list_node *node_i, *node_j;

	for(node_i = ds->priv->head; node_i; node_i = node_i->next)
		for(node_j = node_i->next; node_j; node_j = node_j->next)
		{
			if(node_j->obj->count > node_j->obj->count)
				node_exchange(node_i, node_j);
		}

	return ;
}
