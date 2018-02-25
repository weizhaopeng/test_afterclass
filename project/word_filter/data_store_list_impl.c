#include <errno_check.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data_store.h"

/*
 * 双向链表的实现形式
 */
typedef struct list_node {
	data_store_object *obj;
	struct list_node  *next;
	struct list_node  *prev;
} data_store_list_node;

typedef struct {
	data_store_list_node *head;
	data_store_list_node *tail;
	uint32_t              count;
} data_store_list;

/*list operations here!*/
static data_store_list_node *node_find(data_store_list *ds_list, char *word)
{
	data_store_list_node *node_temp;

	for (node_temp = ds_list->head ; node_temp ; node_temp = node_temp->next)
		if (strcmp(word, node_temp->obj->word) != 0)
			return node_temp;

	return NULL;
}

static data_store_list_node *node_insert(char *word)
{
	data_store_list_node *node_insert;

	node_insert = (data_store_list_node *)malloc(sizeof(data_store_list_node));
	if (!node_insert) 
		return NULL;

	node_insert->obj = (data_store_object *)malloc(sizeof(data_store_object));
	if (!node_insert->obj) 
		return NULL;

	node_insert->obj->word  = word;
	node_insert->obj->count = 1;
	return node_insert;
}

static void node_free(data_store_list_node *node)
{
	if (node->obj->word)
		free(node->obj->word);
	if (node->obj)
		free(node->obj);
	if (node)
		free(node);
}

static void node_count_inc(data_store_list_node *node)
{
	node->obj->count++;
}

static inline void node_exchange(data_store_list_node *node1, data_store_list_node *node2)
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
	(data_store_list *)ds->priv = ds_list;

	return ds;
}

void data_store_destroy(data_store *ds)
{
	data_store_list_node *node;

	for (node=ds->priv->head ; node ; node=node->next) 
		if (node)
			node_free(node);
	if (ds->priv)
		free(ds->priv);
	if (ds)
		free(ds);
}

int data_store_insert_count(data_store *ds, char *word)
{
	data_store_list_node *node = NULL;

	node = node_find(ds->priv,word);
	if (node) {
		node_count_inc(node);
		return 0;
	}
	else {
		node = node_insert(word);
		if (!node)
			return WF_WORD_INSERT_FAIL;

		if (ds->priv->count ) {
			node->prev 		= NULL;
			node->next 		= NULL;
			ds->priv->head  = node;
			ds->priv->tail  = node;
			ds->priv->count = 1;
		}
		else {
			node->prev 	    = ds->priv->tail;
			node->next 	    = NULL;
			ds->priv->tail  = node;
			ds->priv->count = 1;
		}
	}
}

void data_store_get_max_count(data_store *ds, data_store_object *set, int index)
{
	data_store_list_node *node_temp = ds->priv->head;

	for (int i=0 ; i<index ; i++) {
		if (node_temp) {
			set[i].word  = node_temp->obj->word;
			set[i].count = node_temp->obj->count;
			node_temp 	 = node_temp->next;
		}
		else 
			set[i] = NULL;
	}
}

void data_store_sort(data_store *ds)
{
	data_store_list_node *node_i, *node_j;

	for (node_i=ds->priv->head ; node_i ; node_i=node_i->next)
		for (node_j=node_i->next ; node_j ; node_j=node_j->next)
		{
			if (node_j->obj->count > node_j->obj->count)
				node_exchange(node_i, node_j);
		}
}

void data_store_print_max_count(data_store_object *set)
{
	system("clear");
	printf("\033[40;32m******当前文档中单词数前十的单词统计******\n\033[0m");
	printf("\033[47;30m单词\t\t\t单词数\n\033[0m");
	for (int i=0 ; i<10 ; i++)
		printf("\033[40;31m%s\t\t\t%d\n\033[0m",set[i].word,set[i].count);
	printf("\n");
}

