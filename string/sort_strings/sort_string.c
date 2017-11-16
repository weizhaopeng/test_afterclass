#include"sort_string.h"
void sort_string(char *string[],int n)
{
	char *temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if (strcmp(string[i],string[j])>0)
			{
				temp=string[i];
				string[i]=string[j];
				string[j]=temp;
			}
		}
	}
	
}

