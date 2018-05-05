/*一个数可以用二进制表示，也可以用十进制表示，如果该数的二进制表示法所有位数字之和等于十进制表
 *示法所有位数字之和，则称该数为神奇数。比如：21(十进制)=10101(二进制),
 *所有位数之和为2+1=3,1+0+1+0+1=3。求小于等于M的神奇数有多少个。
 */
#include <stdio.h>

int main(int argc, char **argv) {
	int example;
	scanf("%d", &example);
	int num[example], number_t[example+1], j;

	for (j = 0, num[0] = 0; j < example; j++) {
		scanf("%d", number_t+j);
		num[j] = 0;
		
		int sum1, sum2;

		//计算的数值从上次计算的开始
		for (int i = 0; i <= number_t[j]; i++) {
			sum1 = 0;
			sum2 = 0;
			//计算十进制和
			for (int temp = i; temp != 0; ) {
				sum1 += temp%10;
				temp /= 10;
			}
			
			//计算二进制和
			int div = i, quo, rem;
			while (1){
				rem 	  = div%2;
				quo 	  = div/2;
				div  	  = quo;
				sum2 	  += rem;
				if (quo == 0)
					break;
			}

			if (sum1 == sum2)
				num[j]++;
		}
	}
	for (int i = 0; i < example; i++)
		printf("%d\n", num[i]-1);
	return 0;
}

