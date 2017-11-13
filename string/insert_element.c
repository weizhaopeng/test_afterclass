#include"stdio.h"
#include"insert_element.h"
void insert_element(int arr[20],int n,int ins)
{
	for(int i=0;i<n;i++)
	{
		if (ins<=arr[0]||ins>arr[i]&&ins<=arr[i+1])
		{		
			for (int j=n+1;j>i+1;j--)
			{
				arr[j]=arr[j-1];
			}
			*(arr+i+1)=ins;
		}
	}

	printf("插入后的序列：\n");
	for(int k=0;k<n+1;k++)
	printf("%-5d",arr[k]);
	printf("\n");
}
	
