/*算法
 *1.	读入数据
 *2.	读入的数据和每个字符串进行比对去重复
 *3.	对要采购的商品的数量进行排序
 *4.	利用冒泡排序筛选出topn
 *5.	对应的topn相乘相加得到最大最小值
 *测试数据;
 6 5
 3 5 1 6 8 1
 peach
 grapefruit
 banana
 orange
 orange
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct goods_buf{
	char name[200];
	int  num;
} goods_buf

typedef struct goods {
	goods_buf *gb;
	int		   goods_count;
} goods;

static inline int  cmp(const goods_buf *g1, const goods_buf g2);
static inline void bsort(int *price, int *topk, int *bottomk);
static inline void count(goods *gs, const char *goods_temp);
static inline int  cmp_price(const int *a, const int *b);

int main(void) {
	//存储要买的商品名称和临时的商品名称缓冲区
	int  	   label_num, goods_num;
	char	   goods_temp[200]
	goods_buf *gb = calloc(1, sizeof(goods_buf)*1024);
	goods	  *gs = calloc(1, sizeof(goods));

	gs->gb = gb;
	goods_count = 0;
	
	while (scanf("%d%d", &label_num, &goods_num) != EOF) {
		int price[label_num];

		for (int i = 0; i < label_num; i++)
			scanf("%d", price+i);

		for (int i = 0; i < goods_num; i++) {
			scanf("%s", goods_temp);
			fflush(stdin);
			count(gs, goods_temp);
		}
		//快速排序要买的商品的去重复数量
		qsort(gs->gb, gs->goods_count, sizeof(goods_buf), cmp);

		//记录价格topk和bottomk数组
		int topk[count_buy], bottomk[count_buy];

		qsort(price, label_num, sizeof(int), cmp_price);
		for (int i = 0; i < count_buy; i++) {
			topk[i] = price[i];
			bottom[i] = price[count_buy-i];
		}

		long max = 0, min = 0;
		for (int i = 0; i < count_buy; i++) {
			max += name_num[i]*topk[i];
			min += name_num[i]*bottomk[i];
		}
		printf("%ld %ld", min, max);
	}
	return 0;
}

static inline void count(goods *gs, const char *goods_temp) {
	int i;

	for (i = 0; i < gs->goods_count; i++) {
		if (strcmp(gs->gb[i]->name, goods_temp) == 0)
			gs->gb[i]->num++;
	}
	memcpy(gs->gb[i]->name, goods_temp, strlen(goods_temp));
	gs->goods_count++;
}

static inline int cmp(const goods_buf *g1, const goods_buf g2) {
	return g1->num-g2->num;
}

static inline int cmp_price(const int *a, const int *b) {
	return *((int*)a-(int*)b);
}
