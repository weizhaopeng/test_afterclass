/*算法
 *1.	读入数据
 *2.	读入的数据和每个字符串进行比对去重复
 *3.	对要采购的商品的数量进行排序
 *4.	利用冒泡排序筛选出topn
 *5.	对应的topn相乘相加得到最大最小值
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int cmp(const void *a, const void *b);
static inline void bsort(int *price, int *topk, int *bottomk);
static inline void count(const char *temp);
//存储要买的商品名称和临时的商品名称缓冲区
char name_buy[1024][200] = {0}, temp[200] = {0};
//商品名称去重复后的计数， 给出的标签数组
int  count_buy = 0, name_num[1024] = {0}, goods, num_buy;

int main(void) {
	
	while (scanf("%d%d", &goods, &num_buy) != EOF) {
		int price[goods];

		for (int i = 0; i < goods; i++)
			scanf("%d", price+i);

		for (int i = 0; i < num_buy; i++) {
			scanf("%s", temp);
			fflush(stdin);
			count(temp);
		}
		//快速排序要买的商品的去重复数量
		qsort(name_num, count_buy, sizeof(int), cmp);

		//记录价格topk和bottomk数组
		int topk[count_buy], bottomk[count_buy];
		//冒泡排序得到
		bsort(price, topk, bottomk);

		long max = 0, min = 0;
		for (int i = 0; i < count_buy; i++) {
			max += name_num[i]*topk[i];
			min += name_num[i]*bottomk[i];
		}
		printf("%ld %ld", min, max);
	}
	return 0;
}

static inline void count(const char *temp) {
	int i;

	for (i = 0; i < count_buy; i++) {
		if (strcmp(name_buy[i], temp) == 0)
			name_num[i]++;
	}
	memcpy(name_buy[i], temp, strlen(temp));
	name_num[i]++;
}

static inline void bsort(int *price, int *topk, int *bottomk) {
	for (int i = 0; i < count_buy; i++) {
		topk[i]   = price[i];
		bottomk[i] = price[i];
	}

	for (int i = 0; i < count_buy; i++) {
		for (int j = i; j < goods; j++) {
			if (price[i] < price[j])
				bottomk[i] = price[i];
			if (price[i] > price[j])
				topk[i] = price[i];
		}
	}
}
	
static inline int cmp(const void *a, const void *b) {
	return *(int*)a-*(int*)b;
}
