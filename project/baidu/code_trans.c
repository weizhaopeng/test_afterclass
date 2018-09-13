#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void distinguish(char *string);
static inline long int pow_int(const int x, const int y);
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
	int mode = 0;
	if (string[0] == 'R') {
		if (string[1] >= '0' && string[1] <= '9')
			mode = 1;
		else
			mode = 0;
	}
	else
		mode = 0;

	long row = 0, col = 0;
	char buf[16] = {0};

	if (mode == 1)
		sscanf(string, "R%ldC%ld", &row, &col);
	else {
		sscanf(string, "%[^0-9]%ld", buf, &row);
		//将WW转化成十进制
		for (int i = 0; i < strlen(buf); i++) {
			col += (buf[i]-'A'+1)*pow_int(26, strlen(buf)-i-1);
		}
	}

	convert_print(row, col, mode);
}

static inline void convert_print(long row, long col, char mode) {
	if (mode == 0)
		printf("R%ldC%ld\n", row, col);
	else {
		char buf[16] = {0};
		long de = col, last = 0, length = 0;

		sprintf(buf, "%ld", de/26);
		last   = de%26;
		length = strlen(buf);

		for (int i = 0; i <= length; i++) {
			if (buf[i] == '0') {
				if (length > 1) {
					buf[i] = 'Z';
					continue;
				}
				else {
					i--;
					continue;
				}
			}
			else {
				if (i  == length)
					buf[i] = last+'A'-1;
				else
					buf[i] = buf[i]-'0'+'A'-1;
			}
		}	
		printf("%s%ld\n", buf, row);
	}
}
		
static inline long int pow_int(const int x, const int y) {
	long return_value = 1;

	for (int i = 0; i < y; i++)
		return_value *= x;
	return return_value;
}
