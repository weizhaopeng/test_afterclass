/*测试案例
 *4#33
 10#15
 16#F
 5#30
 END
 None
 */
//加入头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义结构体
typedef struct node {
	int  num;
	int  up;
	char num_exist;
	char string[50];
} node;

int
main(void) {
	node nset[1000] = {0}, 
		 node_temp  = {0};
	int	 i 			= 0,
		 nnum   	= 0,
		 up_buf		= 0;

	while (scanf("%d#%s", &up_buf, node_temp.string) == 2) {
		int k 	   = 0,
			square = 1,
			len    = strlen(node_temp.string);

		node_temp.num = 0;
		for (int j = 0; j < len; j++) {
			if (node_temp.string[j] >= 'A')
				node_temp.num += (int)(node_temp.string[len-j-1]-'A'+10)*square;
			else
				node_temp.num += (int)(node_temp.string[len-j-1]-'0')*square;
			square *= up_buf;
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
			memcpy(nset[i].string, node_temp.string, len);
			i++, nnum++;
		}
	}

	int has = 0;

	for (int j = 0; j < nnum; j++) {
		if (nset[j].num_exist == 0) {
			printf("%d#%s\n", nset[j].up, nset[j].string);
			has = 1;
		}
	}
	if (has == 0)
		puts("None");
	return 0;
}


	

