#ifndef _NUM_SEARCH_H
#define _NUM_SEARCH_H

#include"stdio.h"
#include"string.h"
#include"stdlib.h"

struct customer
{
	char num[15];
	char name[15];
};
typedef struct customer CUSTOMER;

void num_check(CUSTOMER *cus[],int n);
#endif 
