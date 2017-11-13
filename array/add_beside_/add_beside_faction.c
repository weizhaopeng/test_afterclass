#include<stdio.h>
#include"add_beside.h"
void add_beside_faction(long *a,long *b)
{
int i;
for(i=0;i<4;i++)
{
b[i]=a[i]+a[i+1];
}
//return b;
}
