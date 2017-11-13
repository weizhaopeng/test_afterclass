#include<stdio.h>
#include"Matr_tr.h"
int main (void)
{
int i,j;
printf("请输入矩阵的行数\n");
scanf("%d",&row);
printf("请输入矩阵的列数\n");
scanf("%d",&col);
for(i=0;i<row;i++)
{
printf("输入第%d行的%d个数值\n",i+1,col);
	for (j=0;j<col;j++)
	{
	scanf("%d",&arr1[i][j]);
	}
}
Matr_tr(arr1,arr2,row,col);
printf("原矩阵：\n");
Matr_tr_print(arr1,row,col);
printf("\n转置矩阵\n");
Matr_tr_print(arr2,col,row);
return 0;
}
