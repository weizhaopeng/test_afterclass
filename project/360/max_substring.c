/*算法：
 *使用M轮循环用两个整形指代子串的首尾，计算出最大值输出
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N 		= 0, 
		M 		= 0, 
		end 	= -1, 
		begin   = 0, 
	   *array_n = NULL, 
	   *array_m = NULL;

	//读入需要的数据
	setbuf(stdin, NULL);
	scanf("%d", &N);
	array_n = calloc(1, sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf("%d", array_n+i);
	scanf("%d", &M);
	array_m = calloc(1, sizeof(int)*M);
	for(int i = 0; i < M; i++)
		scanf("%d", array_m+i);

	//执行M次对整个数组进行遍历获取最大子串
	for (int i = 0, max = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (array_n[j] >= array_m[i]) {
				if (j < N-1)
					end++;
				else
					max = max >= end-begin+1 ? max : end-begin+1;
			}
			else {
				if (begin != -1) {
					max = max >= end-begin+1 ? max : end-begin+1;
					begin = end = -1;
				}
			}
		}
		printf("%d\n", max);
		max = 0; begin = 0; end = -1;
	}

	free(array_n); free(array_m);
	array_n = array_m = NULL;
	return 0;
}
			



	

	
