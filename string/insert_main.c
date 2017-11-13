#include"stdio.h"
#include"insert_element.h"
int main (void)
{
	printf("****请输入10个整数****\n");
	for(int i=0;i<10;i++)
	{
		printf("请输入第%d个整数\n",i+1);
		scanf("%d",&arr[i]);
	}
	
	bubble_sort(arr,10);
	
	puts("请输入要插入的数值：\n");
	scanf("%d",&ins);
	
	insert_element(arr,10,ins);
	return 0;
}
	
