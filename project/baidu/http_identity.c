/*算法：
 *每读入一个字符串就对其进行分析，找到http:// 和https://
 *替换输出
 *注：每个字符串进行分析，不是先存储字符串数组再分析，是没有结束的
 *含有https://可能在字符串中间，注意空格
 *输入案例：You are next. https://http://http:// Next what?
 */
#include <stdio.h>
#include <string.h>

static inline void arrange_print(const char *string, const int start);
static inline int  identity(const char *string, const int len);

int main(void) {
	char array[256] = {0};
	int  start = 0;

	while(scanf("%s", array) != EOF) {
		start = identity(array, strlen(array));
		if (start == -1) {
			printf("%s ", array);
			continue;
		}
		else
			arrange_print(array, start);
	}	

	return 0;
}

static inline int  identity(const char *string, const int len) {
	for (int i = 0; i < len-7; i++) {
		if (string[i] == 'h') {
			if (strncmp("http://", string+i, 7) == 0 
				|| strncmp("https://", string+i, 8) == 0) {
				return i;
				break;
			}
		}
	}
	return -1;
}

static inline void arrange_print(const char *string, const int start) {
	if (start != 0) {
		char buf[200] = {0};
		memcpy(buf, string, start);
		printf("%s", buf);
	}
	printf("<a href=\"%s\">%s</a> ", string+start, string+start);
}

	


