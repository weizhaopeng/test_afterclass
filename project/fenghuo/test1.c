#include <stdio.h>
#include <string.h>

int main(void) {
	char array[26] = {0};
	int  group = 0;

	scanf("%d", &group);
	char string[group*2][10000];

	for (int i = 0; i < group; i++) {
		scanf("%s", string[i]);
		fflush(stdin);
		scanf("%s", string[2*i]);
		fflush(stdin);
	}

	char index[group];

	for (int i = 0; i < group; i++) {
		for (int j = 0; j < strlen(string[i]) && j < strlen(string[2*i]); j++) {
			if (array[string[i][j]-'a'] == 0)
				array[string[i][j]-'a'] = string[i*2][j];
			else if (array[(int)string[i][j]] != array[(int)string[i*2][j]])
				index[i] = 0;
		}
	}

	for (int i = 0; i < group; i++) {
		if (index[i] == 0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}

	
		

