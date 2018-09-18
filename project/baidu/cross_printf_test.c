#include<stdio.h>
#include<string.h>
#include<math.h>

char a[2500][2500];
void draw(int x, int y, int n){

	    int temp = pow(3,n-2);
		    if(n==1){
				        a[x][y] = 'o';
						    }
							    else{
									        draw(x,y,n-1);
											        draw(x-temp,y,n-1);
													        draw(x+temp,y,n-1);
															        draw(x,y-temp,n-1);
																	        draw(x,y+temp,n-1);
																			    }
}
void printS(int n)
{
	    int i,j;
		    for(i=0;i<n;i++)
				    {
						        for(j=0;j<n;j++)
									            printf("%c",a[i][j]);
												        printf("\n");
														    }
}

int main()
{
		int n, i, j,t,temp;
			
				scanf("%d",&n);
					for(i=0;i<n;i++)
							{
										scanf("%d",&t);
												temp=(pow(3,t-1)-1)/2;
														 memset(a,' ',sizeof(a));
														 		 draw(temp,temp,t);
																          printf("Case #%d:\n",i+1);
																		  		 printS(pow(3,t-1));
																				 	}
																						return 0;
} 
