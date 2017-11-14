#include"sort_string.h"
int main (void)
{
	puts("***请输入5个字符串***");
	for(int i=0;i<5;i++)
	{
		printf("请输入字符串%d\n",i+1);
		scanf("%s",strings[i]);
	}
	
//	sort_string(strings,5);

	printf("排序后的字符串是\n");
	for(int j=0;j<5;j++)
	printf("%s\n",strings[j]);
	
	return 0;
}

