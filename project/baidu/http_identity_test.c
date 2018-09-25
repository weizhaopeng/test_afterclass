#include"stdio.h"
#include <string.h>

int main()
{
	    char s[201];
		    memset(s,0,sizeof(s));
			    while(scanf("%s",s) != EOF)
					    {
							        char a = getchar();
									        int i;
											      	for(i = 0; s[i] != '\0'; i++)
														        {
																	          	if(!strncmp(s+i,"http://",7) || !strncmp(s+i,"https://",8))
																					        	{
																									            	printf("<a href\=\"%s\">%s</a>",s+i,s+i);
																													              	break;
																																	        	}
																																				        	else
																																								            	printf("%c",s[i]);
																																												        }
																																														      	if(a == ' '||a == '\n')
																																																	        printf("%c",a);
																																																			        memset(s,0,sizeof(s));
																																																					    }
}
