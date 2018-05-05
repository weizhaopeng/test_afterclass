/*
int find_max_sum_without_adjacents(int vec[],int N)
Input:
2
6
5 4 10 100 10 5
4
3 2 7 10

Output:
110
13
 */

#include <stdio.h>
#include <time.h>

static inline int find_max_sum_without_adjacents(int vec[],int N)
{
	/*
	if (N == 1)
		return vec[0];
	if (N == 2)
		return (vec[0] > vec[1] ? vec[0]:vec[1]);
	if (N == 3)
		return (vec[1] > vec[0]+vec[2] ? vec[1]:vec[0]+vec[2]);
	if (N > 3) {
		int sum1 = 0, sum2 = 0;
	
		for (int i = 2; i < N-1; i++) {
			sum1 = find_max_sum_without_adjacents(vec+i, N-i)+vec[0];
			if (sum1 > sum2)
				sum2 = sum1;
		}
		return sum2;
	}
	*/
	int sum1, sum2;
	for (int i = 2; i < N-1; i++) {
		sum1 = vec[0]+vex[0+i];
		if (sum1 > sum2)
			sum2 = sum1;

}
	


int main(int argc, char **argv)
{
	long start = clock();
	unsigned int test_num;
	scanf("%u", &test_num);
	for (int i = 0; i < test_num; i++) {
		int vec[501];
		unsigned int N;

		scanf("%u", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", vec+j);
			fflush(stdin);
		}
		
		unsigned int sum;
		sum = find_max_sum_without_adjacents(vec, N);
		printf("%d\n", sum); 
	}
	printf("执行时间：%ld\n", clock()-start);
	return 0;
}

