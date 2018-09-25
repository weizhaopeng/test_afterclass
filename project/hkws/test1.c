#include <stdio.h>

int main(void) {
	long x = 0;
	
	while (scanf("%ld", &x) != EOF)
		printf("%lld\n", (long long)(x*2));

	return 0;
}
