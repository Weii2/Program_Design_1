#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(int argc, char *argv[])
{
	srand(time(NULL));
	
	int N=atoi(argv[1]), P=atoi(argv[2]), H, X, k;
	char num[P-1], guess[P-1], y;
	
	for (int i=0; i<P; i++)
	{
		int x=rand();
	
		num[i]=x%N+1;
	}
	
	while (H!=P)
	{	
		H=0;
		X=0;
		k=0;
				
		printf("Guess: ");
		while (1)
		{
			scanf("%d", &guess[k]);

			k++;
			
		  	if (y=getchar()=='\n')
	    	{
				break;
			}
		}
		system("clear");
		for (int i=0; i<P; i++)
		{
			for (int j=0; j<P; j++)
			{
				if (guess[i]==num[i])
				{	
					H++;
					break;
				}	
			
				if (guess[i]==num[j])
				{
					X++;
					break;	
				}
			}
		}
		
		if (H==P)
		{
			printf("correct\n");
			break;
		}
		printf("%dH%dX\n",H,X);	
	}
	
	return 0;
} 
