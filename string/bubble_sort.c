#include<stdio.h>
#include"insert_element.h"
void bubble_sort(int arr[],int n)
{
	int i,j,p;
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				p=arr[i];
				arr[i]=arr[j];
				arr[j]=p;
			}
		}
	}
	printf("\n经过排序过后的序列是：\n");
	for(i=0;i<n;i++)
	{
        	printf("%-5d",arr[i]);
	}
	printf("\n");
}	 	
/*int main (void)
{
	int i,arr[10],*p;
	p=arr;
	for(i=0;i<10;i++)
	{
		printf("请输入序列中第%d个数值\n",i+1);
		scanf("%d",arr+i);
	}
        printf("原序列是：\n");
	for(i=0;i<10;i++)
        {
		printf("%-5d",arr[i]);
        }
	bubble_sort(p,10);
return 0;
}*/
