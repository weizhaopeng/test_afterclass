#include"Filter_words.h"

int main (int argc,int *argv[])
{

	return 0;
}

void FW_readin(void)
{
	char filename[MAX];
	printf("\033[40;41mplease input the name of file\n\033[0m");
	scanf("%s",filename);

	FILE *fp;
	fp=fopen(filename,"r+");
	if(fp==NULL)
		puts("read fault(the file may lose)");

	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	for(int i=0;filename[i]!=' ';i++)
	{
		fgetc(newnode->word->word[i],fp);
		

