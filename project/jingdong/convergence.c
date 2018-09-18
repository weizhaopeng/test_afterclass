/*算法
 *1.先将两个集合进行排序
 *2.使用归并排序的方法，将两个数组进行会和
 *3.对于小的放进数组，对于相等的情况放进一个并且都向后
 *题目：将两个字符串进行不重复合并
 */
#include <stdio.h>

static inline int compare(const void *a, const void *b);
static inline void merge_sort_print(const int *arr1, const int len1, const int *arr2, const int len2);
static inline void qsort(int *arr, const int len);

int main(void) {
	int len[2] = {0};
	while (scanf("%d%d", len, len+1) == 2) { 
		//读入数组数据
		int arr1[len[0]], arr2[len[1]];

		for (int i = 0; i < len[0]; i++)
				scanf("%d", arr1+i);
			for (int j = 0; j < len[1]; j++)
				scanf("%d", arr2+j);
	
			qsort(arr1, len[0]);
			qsort(arr2, len[1]);
			merge_sort_print(arr1, len[0], arr2, len[1]);
	}
	return 0;
}

static inline int compare(const void *a, const void *b) {
	return *(int*)a-*(int*)b;
}
	
static inline void merge_sort_print(const int *arr1, const int len1, const int *arr2, const int len2) {
	int buf[len1+len2], len = 0;

	for (int i = 0, j = 0; i < len1 || j < len2; ) {
		if (i >= len1) {
			buf[len++] = arr2[j++];
			continue;
		}
		if (j >= len2) {
			buf[len++] = arr1[i++];
			continue;
		}

		if (arr1[i] == arr2[j]) {
			buf[len++] = arr1[i++];
			j++;
		}
		else
			buf[len++] = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
	}

	for (int i = 0; i < len; i++)
		printf("%d ", buf[i]);
	puts("");
}

static inline void qsort(int *arr, const int len) {
	if (len <= 1)
		return;
	else {
		int base = arr[0], left = 0, right = len-1;
		while (left < right) {
			while (arr[right] > base)
				right--;
			arr[left] = arr[right];
			
			while (arr[left] < base)
				left++;
			arr[right] = arr[left];
		}
		arr[left] = base;

		qsort(arr, left-1);
		qsort(arr+left+1, right-left);
	}
}
