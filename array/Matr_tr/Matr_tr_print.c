#include<stdio.h>
#include"Matr_tr.h"
void Matr_tr_print(int arr[max][max],int row,int col)
{
int i,j;
for(i=0;i<row;i++)
{
	for(j=0;j<col;j++)
	{
	printf("%-4d\t",arr[i][j]);
	}
printf("\n");
}
}

