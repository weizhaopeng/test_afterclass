#include"stdio.h"
#include"insert_element.h"
void insert_element(int arr[],int n,int ins)
{
	for(int i=0;i<n;i++)
	{
		if (ins<=arr[0]||ins>arr[i]&&ins<=arr[i+1])
		{		
			int j=i+1;
			for (;j<n+1;j++)
			{
				arr[j++]=arr[j];
				*(arr+i+1)=ins;
			}
		}
	}
	for(int k=0;k<n+1;k++)
	printf("%-5d",arr[k]);
	printf("\n");
}
	
