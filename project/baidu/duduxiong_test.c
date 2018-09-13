#include<stdio.h>

int main()
{
		long n, m, k;
			long i=0, left=1, right, mid=0;
				
					scanf( "%ld %ld %ld", &n, &m, &k);
						
							right = n*m;
								
									while( left<=right)
											{
														mid = (left+right)/2;
																
																		long count=0;
																				for( i=n; i>0; i--)
																							{
																											if( m<=mid/i)
																															{
																																				count += m;
																																								break;
																																											}
																																														count += mid/i;
																																																}
																																																		
																																																				if( count<k)
																																																								left = mid+1;
																																																										else
																																																														right = mid-1;
																																																															}
																																																																
																																																																	printf( "%ld", left);
																																																																		return 0;
} 
