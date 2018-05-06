/*我们来玩一个大富翁的游戏，在地图上有N个连续的城市，城市对某件商品的售价为[V1,V2,V3...VN]，
 *你作为未来的大富翁看到其中的商机，打起了倒卖商品赚取差价的主意。约束条件：
 *你只能顺序从第一个城市出发，不能走回头路，每次只能交易一件商品，再下次买入商品后必须卖掉之前买入的商品
 *，求你能赚取的最大财富。比如：城市商品售价为[1,9,2,3,8]，最大财富为(9-1)+(8-2)=14；
 *城市商品售价为[9,8,3,2,1]，最大财富为0，因为你买啥都无法赚钱。
 */
#include <stdio.h>
#include <stdlib.h>

enum state {
	buy = 0x00,	//可买
	sall		//可卖
};

typedef enum state state;

typedef struct stack {
	int   money;
	state sta;
} stack;


static inline int find_max_price(stack *st, const int *price, const int N) {
	if (N == 1) {
		if (st->sta == buy)
			return st->money;
		if (st->sta == sall) {
			st->sta = buy;
			return st->money+price[0];
		}
	}
	else {
		int max, sum1, sum2, sum3, sum4;
		if (st->sta == buy) {
			st->sta = sall;
			sum1 = st->money-price[0]+find_max_price(st, price+1, N-1);
			st->sta = buy;
			sum2 = st->money+find_max_price(st, price+1, N-1);
			return sum1 > sum2 ? sum1 : sum2;
		}
		if (st->sta == sall) {
			st->sta = buy;
			sum3 = st->money+price[0]+find_max_price(st, price+1, N-1);
			st->sta = sall;
			sum4 = st->money+find_max_price(st, price+1, N-1);
			return sum3 > sum4 ? sum3 : sum4;
		}
	}
}

int main(int argc, char **argv) {
	//执行次数
	int test_num;
	scanf("%d", &test_num);

	int maxacq[test_num];
	stack *st = malloc(sizeof(stack));
	for (int i = 0; i < test_num; i++) {
		int city_num;
		scanf("%d", &city_num);

		int price[city_num];
		for (int j = 0; j < city_num; j++) {
			fflush(stdin);
			scanf("%d", price+j);
		}
		
		st->money = 0;
		st->sta	  = buy;

		maxacq[i] = find_max_price(st, price, city_num);
		if (maxacq[i] < 0)
			maxacq[i] = 0;
	}

	for (int j = 0; j < test_num; j++)
		printf("%d\n", maxacq[j]);
	if (st) {
		free(st);
		st = NULL;
	}
	return 0;
}

		

