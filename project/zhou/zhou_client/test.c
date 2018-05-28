#include <stdio.h>
#include <stdlib.h>
int main() {
	system("clear");
 	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 150; j++) {
			if ( i == 0 || i == 29)
				printf("*");
			else {
				if (j == 0 || j == 149) {
					printf("*");
				}
				else {
					if (i == 25 && j > 0 && j < 149)
						printf("-");
					else printf("\033[1C");
				}
			}
		}
		printf("\n");
	}
	printf("\033[149A\033[1C");
}
	

