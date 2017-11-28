#include"stdio.h"
#include<math.h>
#include<stdlib.h>
struct point
{
	double x;
	double y;
};
typedef struct point POINT; 

double distance(POINT *a,POINT *b)
{
	double dx,dy,result;
	
	dx=a->x-b->x;
	dy=a->y-b->y;
 	result=sqrt(dx*dx+dy*dy);
	return result;
}
void main (void)
{
	POINT *a,*b;
	
	a=(POINT *)malloc(sizeof(POINT));
	b=(POINT *)malloc(sizeof(POINT));

	puts("请输入a点的坐标（x-y）：如：3.22 4.33（x y坐标可以是小数）");
	scanf("%lf%lf",&a->x,&a->y);
	puts("请输入b点的坐标（x-y）：如：3.22 4.33（x y坐标可以是小数）");
	scanf("%lf%lf",&b->x,&b->y);
	
	printf("a b的距离是d=%-5.2f\n",distance(a,b));
}
