#include"stdio.h"
struct student 
{
	int student_ID;
	char name[20];
	float score;
};
typedef struct student STU;

void main(void)
{
	STU stu1[4]={
			{100,"魏朝鹏",73.3},
			{101,"蔡清源",75.3},
			{102,"杨晓涵",88.3},
			{103,"带薪",9.2}};
	
	STU *temp=stu1;
	for (int i=1;i<4;i++)
	{
		if(temp->score<(stu1+i)->score)
		temp=stu1+i;
	}
	
	printf("分数最高的学生是:%d号%s同学，%-3.1f分\n",temp->student_ID,temp->name,temp->score);
}	
		
