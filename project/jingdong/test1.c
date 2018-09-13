#include <stdio.h>

typedef struct node {
	int point[2];
	int exist;
} node;

int main(int argc, char argv) {
	int groups, nodes, lines, ret = 0;

	scanf("%d", &groups);
	scanf("%d", &nodes);
	scanf("%d", &lines);

	node *node_set = calloc(1, sizeof(node)*lines);
	for (int i = 0; i < lines; i++) {
		scanf("%d%d", &(node_set[i].point[0]), &(node_set[i].point[1]));
		node_set[i].exist ? ret = 1 : node_set[i].exist = 1;
		fflush(stdin);
	}




