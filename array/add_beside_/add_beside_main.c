#include<stdio.h>
#include"add_beside.h"
int main (void)
{
int i,j;
long a[5],b[5];
printf("请输入5个整形数值，用空格隔开输入\n");
for (i=0;i<5;i++)
scanf("%ld",(a+i));
add_beside_faction(a,b);
for(i=0;i<4;i++)
{
printf("%-5ld\t",*(b+i));
j=i+1;
if(j%3==0)
printf("\n");
}
printf("\n");
return 0;
}

