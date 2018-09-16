#include <stdio.h>
#include <string.h>
/*算法
 *1.建立字符串数组存储字符串
 *2.建立一个字符个数的数组
 *3.读取字符串更新26位长指示数组的长度，同时更新最大长度
 *4.计算每个字符下面的串数，每种字符串的长度就是包含的子串数
 */

#define STRING_STORE_LEN 100000

int main(void) {
	char string[STRING_STORE_LEN];
	long index[26]  = {0}, sub_string_sum = 0, child_len = 0;
	int  len = 0, k = 0;

	scanf("%s", string);
	len = strlen(string);
	for (int i = 0; i < len;) {
		while (string[k] == string[i])
			k++;
		child_len = k-i;
		if (index[string[i]-'a'] < child_len)
			index[string[i]-'a'] = child_len;
		i = k;
	}

	for (int i = 0; i < 26; i++)
		sub_string_sum += index[i];
	printf("%ld\n", sub_string_sum);
	return 0;
}

	
		

