#ifndef _GUESS_NUMBER_H_
#define _GUESS_NUMBER_H_

typedef struct 
{
	char name[15];
	char number[4];
}TRY;
typedef struct 
{
	int A;
	int B;
}RESUIT; 
int guess_num_menu();
void guess_num_result(TRY t);
TRY *guess_num_rule(void);


#endif
