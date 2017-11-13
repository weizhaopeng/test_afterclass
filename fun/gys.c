#include<stdio.h>
int gys(int a,int b)
{
	int t;
	t=a%b;
	return t?gys(b,t):b;
}
int gbs(int a,int b)
{
	return a*b/gys(a,b);
}
void main (void)
{
	int a=245,b=365;
	printf("%d\n%d\n",gys(a,b),gbs(a,b));
}

