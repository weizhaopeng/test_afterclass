/*
 *给定一个链表，实现一个函数，将链表中每k个节点进行翻转，若最后一组节点数量不足k个，
 *则按实际个数翻转。例如：给定链表1->2->3->4->5->6->7->8->NULL，k=3，翻转后输出3->2->1->6->5->4->8->7->NULL。
 *翻转函数reverse有两个参数，分别为链表头指针和翻转步长k。
 *Input:
 *1
 *8
 *1 2 2 4 5 6 7 8
 *4

 *Output:
 *4 2 2 1 8 7 6 5
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int 		 ele;
	struct node *next;
	struct node *prev;
} node;

typedef node* list;

static inline void exchange(node *node1, node *node2)
{
	int ele_temp;
	ele_temp   = node1->ele;
	node1->ele = node2->ele;
	node2->ele = ele_temp;
	return ;
}
			
void reverse(const node *headnode, int div)
{
	int k = div;
	node *node_temp = headnode->next;
	//分块进行转换
	for (int i = 0; i < headnode->ele/k+1; i++) {
		int   k1;
		//确定数组长度
		if (i < headnode->ele/k)
			k1 = k;
		else {
			k1 = headnode->ele%k;
			if (k1 == 0)
				break;
		}

		//将当前快的k1个链表结点存在数组中
		node *p_set[k1];
		for (int j = 0; j < k1 && node_temp != NULL; j++) {
			p_set[j]  = node_temp;
			node_temp = node_temp->next;
		}
			
		//确定转换的初始位置
		node *node_i, *node_j;

		node_i = p_set[0];
		node_j = p_set[k1-1];

		//结点进行互换
		for (int s = 0; s < k1/2; s++) {
			exchange(node_i, node_j);
			node_i = p_set[s+1];
			node_j = p_set[k1-s-2];
		}	
	}
	return ;
}
int main(int argc, char **argv)
{
	int  cir_num;
	scanf("%d", &cir_num);

	for (int i = 0; i < cir_num; i++) {
		node *headnode, *tailnode, *node_temp;
		int   ele_num;
		int	  ele_set[10];
		int   div;

		scanf("%d", &ele_num);
		for (int k = 0; k < ele_num; k++) {
			scanf("%d", ele_set+k);
			fflush(stdin);
		}
		scanf("%d", &div);
		headnode = malloc(sizeof(node));
		headnode->ele  = ele_num;
		headnode->prev = NULL;
		headnode->next = NULL;
		tailnode	   = headnode;

		for (int j = 0; j < ele_num; j++) {
			node_temp 		= malloc(sizeof(node));
			node_temp->ele  = ele_set[j];
			node_temp->prev = tailnode;
			tailnode->next  = node_temp;
			node_temp->next = NULL;
			tailnode 		= node_temp;
		}

		reverse(headnode, div);
		for (node *nd = headnode->next; nd != NULL; nd = nd->next)
			printf("%d ", nd->ele);
		printf("\n");
		
		for (node *nd = tailnode; nd != NULL; nd = tailnode) {
			tailnode = tailnode->prev;
			free(nd);
		}
	}
	return 0;
}
