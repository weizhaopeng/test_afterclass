#include <stdio.h>
#include <stdlib.h>

typedef struct unit {
	long edge;
	int  number;
} unit;

int main(void) {
	int num_box = 0, length = 0, is_exist = 0, max = 0;
	long  edge_temp = 0;
	unit *set = NULL;
	
	setbuf(stdin, NULL);
	scanf("%d", &num_box);
	set = calloc(1, sizeof(unit)*num_box);

	for (int i = 0; i < num_box; i++) {
		scanf("%ld", &edge_temp);
		for (int j = 0; j < length; j++) {
			if (set[j].edge == edge_temp) {
				set[j].number++;
				max = set[j].number > max ? set[j].number : max;
				is_exist = 1;
			}
		}
		if (is_exist == 0) {
			set[length].edge = edge_temp;
			set[length++].number++;
			max = set[length-1].number > max ? set[length-1].number : max;
		}
		else
			is_exist = 0;
	}

	printf("%d\n", max);
	free(set);
	set = NULL;
	return 0;
}


	
		
