#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int  num;
	int  up;
	char num_exist;
	char string[50];
} node;

int main(void) {
	node nset[1000] = {0}, node_temp;
	int  up_buf = 0, i = 0, nnum = 0;
	char num_buf[50] = {0};

	while (scanf("%d#%s", &up_buf, num_buf) == 2) {
		int len = strlen(num_buf), k;
		for (int j = 0; j < len; j++) {
			if (num_buf[j] >= 'A')
				node_temp.num += (int)(nset[i].string-'A'+10)*(int)pow(up_buf, len-j);
			else
				node_temp.num += (int)(nset[i].string-'0')*(int)pow(up_buf, len-j);
		}

		for (k = 0; k < nnum; k++) {
			if (nset[k].num == node_temp.num) {
				nset[k].num_exist = 1;
				break;
			}
		}

		if (k == nnum) {
	 		nset[i].up 		  = up_buf;
			nset[i].num 	  = node_temp.num;
			nset[i].num_exist = 0;
			memcpy(nset[i].string, num_buf, len);
			i++;
		}
	}

	int is = 0;
	for (int j = 0; j < nnum; j++) {
		if (nset[j].num_exist == 0) {
			printf("%d#%s\n", nset[j].up, nset[j].string);
			is = 1;
		}
	}
	if (is == 0)
		printf("None\n");
	return 0;
}


	

