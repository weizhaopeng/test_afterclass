#ifndef _GUESS_NUMBER_H_
#define _GUESS_NUMBER_H_
/*常用C语言函数库*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/*每次尝试也就是进行一次游戏
*游戏者的名字和循环输入的数字数据*/
typedef struct 
{
	char name[15];
	char number[4];
}TRY;
/*用于显示-A-B的结果*/
typedef struct 
{
	int A;
	int B;
}RESULT; 
/*主菜单界面函数*/	
void guess_num_menu(void);
/*游戏算法函数，一人和双人游戏的集合，兼有显示结果和记录游戏数据*/
void guess_num_game(void);
/*显示游戏规则*/
void guess_num_rule(void);
/*单人游戏*/
void guess_1p();
/*双人游戏*/
void guess_2p();
/*选择游戏模式*/
void guess_num_ganmemode();

#endif
