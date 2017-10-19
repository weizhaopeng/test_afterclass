#include<stdio.h>
#define max 100
int main (void)
{
int num,arr[max][5],i,j;
printf("请输入运动员的人数\n");
scanf("%d",&num);
printf("请输入各个裁判的评分（空格隔开）\n");
for(i=0;i<num;i++)
{
printf("NO.%d\tjudge1\tjudge2\tjudge3\tjudge4\tjudge5\n",(i+1));
printf("\t");
scanf("%d%d%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3],&arr[i][4]);
}
printf("裁判员:\t\tjudge1\tjudge2\tjudge3\tjudge4\tjudge5\n");
for (i=0; i<num;i++)
{
printf("运动员：NO.%d",(i+1));
	for( j=0; j<5;j++)
	printf("%8d",arr[i][j]);
printf("\n");
}
return 0;
}
