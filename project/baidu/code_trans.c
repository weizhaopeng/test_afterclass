#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void distinguish(char *string);
static inline void convert_print(long row, long col, char mode);

int main(void) {
	char **array_p = NULL;
	int    num;

	//读入数据
	scanf("%d", &num);
	array_p = malloc(sizeof(char *)*num);

	for (int i = 0; i < num; i++) {
		fflush(stdin);
		array_p[i] = malloc(sizeof(char)*16);
		scanf("%s", array_p[i]);
	}

	//进行识别是何种编码以及进行转换并打印
	for (int i = 0; i < num; i++) {
		//mode == 0代表AA22,mode == 1代表R22C22
		distinguish(array_p[i]);
		free(array_p[i]);
	}
	free(array_p);
	return 0;
}

static inline void distinguish(char *string) {
	long row  = 0, col = 0;
	int  mode = 0;
	char buf[32] = {0};

	if (sscanf(string, "R%ldC%ld", &row, &col) == 2)
		mode = 1;
	
	if (mode == 0) {
		long pow = 1;
		sscanf(string, "%[^0-9]%ld", buf, &row);
		//将WW转化成十进制
		for (int i = strlen(buf)-1; i >= 0; i--, pow *= 26) {
			if (buf[i] == '@')
				col += 0;
			col += (buf[i]-'A'+1)*pow;
		}
	}

	convert_print(row, col, mode);
}

static inline void convert_print(long row, long col, char mode) {
	if (mode == 0)
		printf("R%ldC%ld\n", row, col);
	else {
		int  i = 0, k = 0, int_buf[16] = {0};
		char char_buf[16] = {'\0'};
		long de = col;
		//辗转相除法找到26进制的表示
		while (de >= 26) {
			int_buf[i++] = de%26;
			de = de/26;
		}
		int_buf[i] = de;

		for (int j = i; j >= 0; j--, k++) {
			if (int_buf[j] == 0) {
				char_buf[k-1]--;
				char_buf[k] = 'Z';
			}
			else
				char_buf[k] = 'A'+int_buf[j]-1;
		}
		printf("%s%ld\n", char_buf, row);
	}
}
		
