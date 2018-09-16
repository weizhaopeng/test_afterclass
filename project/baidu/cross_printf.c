/*算法：
 *利用分治法，将大的打印拆分成九个格子进行打印，首先定位到全图的中心，然后分别对
 *定位到上下左右的小格子中心进行打印，当只有一个格子的放入'o'
 *确定最终的打印
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void fill_in_buf(int posi_x, int posi_y, const int edge);

#define BUF_LEN  2000
//虽然我们定义的额是2000*2000的二维数组，但是我们使用的array[5][8]仍然是5排8列的数据,不影响
char array[2000][2000];//全局变量，在函数中也可以进行修改

int main(void) {
	int num = 0, case_t[10] = {0};
	//读取case值
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", case_t+i);

	for (int i = 0; i < num; i++) {
		//初始化最大缓冲区
		memset(array, ' ', sizeof(char)*BUF_LEN*BUF_LEN);
		int x = (int)powf(3, case_t[i]-1)/2;
		int y = x, edge = (int)powf(3, case_t[i]-1);
		fill_in_buf(x, y, case_t[i]);

		printf("Case #%d:\n", case_t[i]);
		for (int j = 0; j < edge; j++) {
			for (int k = 0; k < edge; k++)
				printf("%c", array[j][k]);
			puts("");
		}
	}
	return 0;
}
//根据缓冲区的边长，将字符填入缓冲区，使用递归的方法
void fill_in_buf(int x, int y, const int case_t) {
	int edge 	   = (int)powf(3, case_t-1);
	int child_edge = (int)powf(3, case_t-2);

	if (edge == 1)
		array[x][y] = 'o';

	if (edge > 0) {
		fill_in_buf(x, y, case_t-1);
		fill_in_buf(x-child_edge, y, case_t-1);
		fill_in_buf(x+child_edge, y, case_t-1);
		fill_in_buf(x, y-child_edge, case_t-1);
		fill_in_buf(x, y+child_edge, case_t-1);
	}
}
		

