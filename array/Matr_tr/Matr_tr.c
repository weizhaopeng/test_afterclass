#include<stdio.h>
#include"Matr_tr.h"
void Matr_tr(int arr1[max][max],int arr2[max][max],int row,int col)
{
int i,j;
for (i=0;i<row;i++)
{
	for (j=0;j<col;j++)
	{
//	*(arr2+j*row+i)=*(arr1+i*col+j);
	arr2[j][i]=arr1[i][j];
	}
}
}

