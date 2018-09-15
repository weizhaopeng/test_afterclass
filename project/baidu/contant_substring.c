#include <stdio.h>

typedef struct node {
	char ch;
	long number;
} node;

#define STRING_STORE_LEN 100000

int main(void) {
	char string[STRING_STORE_LEN];
	node buf[26] = {0};
	
	scanf("%s", string);
	for (int i = 0; i < strlen(string); i++) {
		buf[st
