#include <stdio.h>

#define SUM(x) (x*(x-1)/2)
typedef struct pair {
	long m;
	long n;
} pair;

int main(void) {
	int group;
	scanf("%d", &group);

	pair array_p[group];
	for (int i = 0; i < group; i++) {
		scanf("%ld%ld", &(array_p[i].n), &(array_p[i].m));
		fflush(stdin);
	}

	for (int i = 0; i < group; i++) {
		long max = 0, min = 0, n = array_p[i].n, m = array_p[i].m, de;

		de  = n-m+1;
		max = SUM(de);
		long re = n/m, last = n%m;

		min = SUM(re)*(m-last)+SUM(re+1)*last;
		printf("%ld %ld\n", min, max);
	}
	return 0;
}


