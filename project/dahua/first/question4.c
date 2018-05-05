/*实现find_sub_string(str1,str2)函数，判断字符串str2在str1中出现的次数。返回str2在str1中出现的次数。
 *int find_sub_string(const std::string& str1, const string& str2);
 */
#include <stdio.h>
#include <string.h>
#include <strings.h>

int main(int argc, char **argv) {
	int example;
	int num[example];
	scanf("%d", &example);

	char readin[100], cmp[100];
	int  readin_len, cmp_len;
	
	for (int i = 0; i < example; i++) {
		bzero(readin, 100);
		bzero(cmp, 100);
		
		fflush(stdin);
		scanf("%s", readin);
		readin_len = strlen(readin);
		fflush(stdin);
		scanf("%s", cmp);
		cmp_len    = strlen(cmp);

		int ret;
		num[i] = 0;
		for (int j = 0; j < readin_len-cmp_len+1; j++) {
			if (readin[j] == cmp[0]) {
				ret = bcmp(readin+j, cmp, sizeof(char)*cmp_len);
				if (ret == 0)
					num[i]++;
			}
		}
	}
	for (int k = 0; k < example; k++)
		printf("%d\n", num[k]);
	
	return 0;
}
	
