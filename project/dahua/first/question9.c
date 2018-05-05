/*我们来玩一个大富翁的游戏，在地图上有N个连续的城市，城市对某件商品的售价为[V1,V2,V3...VN]，
 *你作为未来的大富翁看到其中的商机，打起了倒卖商品赚取差价的主意。约束条件：
 *你只能顺序从第一个城市出发，不能走回头路，每次只能交易一件商品，再下次买入商品后必须卖掉之前买入的商品
 *，求你能赚取的最大财富。比如：城市商品售价为[1,9,2,3,8]，最大财富为(9-1)+(8-2)=14；
 *城市商品售价为[9,8,3,2,1]，最大财富为0，因为你买啥都无法赚钱。
 */
#include <stdio.h>

typedef struct node {
	int money;
	struct node *buy;
	struct node *wait;
	struct node *sall;
} node;

typedef node *ttree;

static inline node *ttree_make(const int *price, const int N) {
	node *root = malloc(sizeof(node));
	root->money = 0;
	
	node *node_temp = root;
	for (int i = 0; i < N; i++) {
		node_new = malloc(sizeof(node));
		if (node_temp->money = 0) {
			node_temp->sall = NULL;
			node_temp->wait 
		
int main(int argc, char **argv) {
	//执行次数
	int test_num, city_num;
	scanf("%d", &test_num);
	scanf("%d", &city_num);

	int price[city_num];
	for (int i = 0; i < test_num; i++)
		for (int j = 0; j < city_num; j++) {
			fflush(stdin);
			scanf("%d", price+j);
		}

		ttree tt = NULL;
		tt = ttree_make(price, city_num);

		

