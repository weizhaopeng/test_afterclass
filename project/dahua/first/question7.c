/*
 *给定一个全小写的英文字符串，请在该字符串中找到一个连续子字符串
 *，使得子字符串没有重复的字符并且长度最长，计算此最长字符串的长度。
 *比如：abcbdeab,最长的子字符串为cbdea，长度为5；aaaa，最长子字串为a，长度为1。
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>

typedef struct stack {
	char buf[27];
	int  top;
	int  bot;
} stack;

int main(int argc, char **argv) {

	char  str[100];
	int   length;
	int   example;
	stack st;
	int   arr[26];
	int   maxlen;

	scanf("%d", &example);

	for (int j = 0; j < example; j++) {
		//输入数据小写字符
		scanf("%s", str);
		length = strlen(str);
		maxlen = 0;

		//计算length-maxlen个字符每个的最大长度
		for (int j = 0; j < length-maxlen; j++) {
			//栈和数组初始化
			bzero(arr, sizeof(int)*26);
			bzero(st.buf, 26);
			st.top    = 0;
			st.bot    = 1;
			//计算从第j个到length中的最大长度
			for (int i = j; i < length; i++) {
				if (arr[str[i]-97] == 0) {		//判断是否已经存在
					st.buf[st.top+=1] = str[i];	//入栈, 栈顶上升
					arr[str[i]-97] = st.top;	//记录字母所在的栈顶位置
					if (maxlen < st.top-st.bot+1)
						maxlen = st.top-st.bot+1;
				}
				else
					break;
			}
		}
		printf("%d\n", maxlen);
	}			
	return 0;
}
		
