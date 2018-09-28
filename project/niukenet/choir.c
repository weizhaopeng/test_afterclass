/*算法：
 *1.根据贪心法，我们将最大值集中在最大的数据上
 *2.然后将从最大的数据进行分层的寻找最大正数和最小负数
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct unit {
	long max;
	long min;
	int  layers;
} unit;

static inline int find_mm(int layer_left, int index, int *set, const int interval, const int set_len);
		
int main(void) {
	//读入数据
	int   num_stu     = 0, num_select 	   = 0, interval = 0,
		  max = min   = 0, max_no = min_no = 0;
	 	 *set_ability = NULL;
	unit *set 		  = NULL;

	setbuf(stdin, NULL);
	scanf("%d", &num_stu);
	set_ability = calloc(1, sizeof(int)*num_stu);
	for (int i = 0; i < num_stu; i++)
		scanf("%d", set_ability+i);
	
	scanf("%d%d", &num_select, &interval);
	set = calloc(1, sizeof(unit)*num_select);
	//获取每层的最大正数和最小负数

	for (j = 1; j < num_stu; j++) {
		if (max < set_ability[j]) {
			max_no = j;
		}
		if (min > set_ability[j]) {
			min_no = j;
		}
	}
	max1 = find_mm(num_select, max_no, interval, num_stu);
	max2 = find_mm(num_select, min_no, interval, num_stu);
	printf("%d\n", max1 > max2 ? max1 : max2);

	free(set_ability); free(set);
	set_ability = set = NULL;
	return 0;
}
//寻找一个当前位置的前后的乘积的最大最小值
static inline int find_mm(int layer_left, int index, int *set, const int interval, const int set_len) {
	static unit u = {0, 0, leyer_left};
	long   max1 = max2 = 0;

	if (layer_left == 1) {
		for (int i = index-interval
			; i >= 0 && i <= num_stu && i <= index+interval
			; i++) {
			u.max = (set[i]*u.max > u.max ? set[i]*u.max : u.max);
			u.max = (set[i]*u.min > u.max ? set[i]*u.min : u.max);
		}
	}
	else {
		for (int i = index-interval
			; i >= 0 && i <= num_stu && i <= index+interval
			; i++) {
			if (int new_max = set[i]*u.max > u.max) {
				int setcopy[set_len] = {0};

				memcpy(setcopy, set, sizeof(int)*set_len);
				u.max = new_max;
				setcopy[i] = 1;
				index = i;
				find_mm(layer_left-1, index, setcopy, interval, set_len);
			}
			
			if (int new_min = set[i]*u.min < u.min) {
				int setcopy[set_len] = {0};

				memcpy(setcopy, set, sizeof(int)*set_len);
				u.min = new_min;
				setcopy[i] = 1;
				index = i;
				find_mm(layer_left-1, index, setcopy, interval, set_len);
			}
		}
	}
	return u.max;
}
