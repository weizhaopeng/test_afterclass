#include"stdio.h"
#include<math.h>

struct posi
{
	double x;
	double y;
};
typedef struct posi PSI;

void main (void)
{
	double dx,dy,result;
	PSI *a,*b;
	
	puts("请输入a点的坐标（x-y）：如：3.22 4.33（x y坐标可以是小数）");
	scanf("%lf%lf",&a->x,&a->y);
	puts("请输入b点的坐标（x-y）：如：3.22 4.33（x y坐标可以是小数）");
	scanf("%lf%lf",&b->x,&b->y);

	dx=a->x-b->x;
	dy=a->y-b->y;
	
 	result=sqrt(dx*dx+dy*dy);
	printf("a b的距离是d=%-5.2f\n",result);
}
