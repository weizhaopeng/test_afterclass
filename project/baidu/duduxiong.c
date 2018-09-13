/*因为每一排都是从小到大排列的，所以可以直接归并排序一次就排序出
 *来了，当然不用排序出来全部的数据，只是排序出前k个元素
 */
#include <stdio.h>

int main(void) {
	long row, col, k;
	scanf("%ld%ld%ld", &row, &col, &k);
	
	long left = 1, right = row*col, mid;

	while (left <= right) {
		mid = (left+right)/2;
		//我们能统计出每个数字出现的时候，大于等于他的数的个数,当出现了和k前面的数相同的时候
		long count = 0;
		//实际上这个对于重复的数据来说，1-row*col并不是实际的数据数组，而是位置，对
		//于这其中的数进行判断,数组中的数虽然是重复的，但是实际出现的值是连续的
		for (int i = 1; i <= row; i++) {
			if (i*col > mid)
				count += mid/i;
			else
				count += col;
		}
		
		if (count < k)
			left = mid+1;
		else
			right = mid-1;
	}
	
	printf("%ld\n", left); 
	return 0;
}
















/*
#include <stdio.h>
#include <stdlib.h>

static inline void heap_build(int *set, int length);
static inline void heap_adjust_down(int *set, int key, const int length);
static inline void heap_adjust_up  (int *set, int key, const int length);
static inline void swap(int *a, int *b);

int main(void) {
	int row, col, k, *set, p = 1;
	int length;

	scanf("%d%d%d", &row, &col, &k);
	//数组长度
	length = row*col+1;
	set = calloc(1, length*sizeof(int));
	//建立数组，将数据填入1-row*col单元中
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++)
			set[p++] = i*j;
	}
	//用数组建立一个k+1长度的堆
	heap_build(set, k);

	//将数组中k+2-length的元素都加入到堆结尾并且进行向上调整，注意数组越界
	for (int i = k+1; i < length && k <= length && set[i] < set[k]; i++) {
		set[k] = set[i];
		heap_adjust_up(set, k+1, k);
	}

	//此时数组前k个元素（从1开始的就是前k个数）小的数被放入了数组，但是此时相互位置是错开的
	for (int i = 1; i <= k; i++) {
		printf("%d\n", set[i]);
	}
	free(set);
	return 0;
}

//交换数组元素
static inline void swap(int *a, int *b) {
	int temp;

	temp = *a;
	*a   = *b;
	*b   = temp;
}
//向下调整
static inline void heap_adjust_down(int *set, int key, const int length) {
	int i = key;
	while (i <= length/2) {
		if (length < 2*i+1) {
			if (set[i] > set[i*2])
				swap(set+i, set+i*2);
			i *= 2;
		}
		else {
			if (!(set[i] < set[2*i] && set[i] < set[2*i+1])) {
				//TODO 确认这个是否正确
				if (set[i*2] < set[i*2+1]) {
					swap(set+i, set+i*2);
					i *= 2;
				}
				else {
					swap(set+i, set+(i*2+1));
					i = i*2+1;
				}
			}
			else
				break;
		}
	}
}
//建堆
static inline void heap_build(int *set, int k) {
	for (int i = k/2; i > 0; i--) {
		heap_adjust_down(set, i, k);
	}
}
//向上调整,注意奇偶数
static inline void heap_adjust_up  (int *set, int key, const int length) {
	int key_t = key;
	if (key_t%2 == 0) {
		while (set[key_t] < set[key_t/2]) {
			swap(set+key_t, set+key_t/2);
			key_t = key_t/2;
		}
	}
	else {
		while (set[key] < set[(key-1)/2]) {
			swap(set+key, set+(key-1)/2);
			key_t = (key_t-1)/2;
		}
	}
}
*/
