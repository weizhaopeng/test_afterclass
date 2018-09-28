#include <stdio.h>

static inline long sum_recursion(int n, int before_is);

int main(void) {
	int   num_food = 0, before = 0;
	char *set = NULL;
	long  sum = 0;

	scanf("%d", &num_food);
	set = calloc(sizeof(char)*num_food);
	printf("%ld\n", ret);
	return 0;
}

/*
static inline long sum_recursion(int n, int before_is) {
	long sum = 0, sum1 = 0, sum2 = 0;

	if (n == 1) {
		if (before_is == 1)
			sum = 1;
		else
			sum = 2;
	}
	else {
		if (before_is == 1)
			sum = sum_recursion(n-1, 0);
		else {
			sum1 = sum_recursion(n-1, 1);
			sum2 = sum_recursion(n-1, 0);
			sum  = sum1+sum2;
		}
	}
	return sum;
}
*/
