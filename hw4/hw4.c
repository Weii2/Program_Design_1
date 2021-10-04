#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef union
{ 
   	float f; 
	struct
	{   
		unsigned int m : 23; 
    	unsigned int e : 8; 
	    unsigned int s : 1; 
  	}r; 
}flo;

int main(int argc, char *argv[])
{
	int t=atoi(argv[1]);
	float num1=0;
	double num2=0;
	unsigned int* pt1 = (int*)&num1;
	unsigned long long* pt2 = (unsigned long long *)&num2;
	unsigned long long m=1;
	
	if(t==1)
	{
		num1=atof(argv[2]);

		for (int i=31; i>=0; i--)
		{
	    	if( (1<<i) & *pt1 )
	    		printf("1");
	    	else
	    		printf("0");
	    	if(i==31 || i==23)
	    		printf(" ");
		}
		printf("\n");
	}
	
	else if(t==2)
	{
		num2=atof(argv[2]);

		for (int i=63; i>=0; i--)
		{
	    	if( (m<<i) & *pt2 )
	    		printf("1");
	    	else
	    		printf("0");
	    	if(i==63 || i==52)
	    		printf(" ");	    		
	    }
		printf("\n");		
	}

	else if(t==3)
	{
		flo tra;
		tra.r.s=argv[2]-'0';
		tra.r.e=0;
		tra.r.m=0;
	
		for (int i=0; i<=7; i++)
		{ 
        	tra.r.e = tra.r.e + (argv[3][i]-'0') * pow(2,7-i); 
    	} 
		
		for (int i=0; i<=22; i++)
		{ 
        	tra.r.m = tra.r.m + (argv[4][i]-'0') * pow(2,22-i);
        	printf("",(argv[4][i]-'0') * pow(2,22-i),tra.r.m);
    	}

		printf("%f\n",tra.f); 		
	}

	else if(t==4)
	{
		int j=2;
		int k=0;
				
	   	for(int i=0; i <= 63; i++)
	   	{
			*pt2 = *pt2 | (((unsigned long long)(argv[j][k++] - '0'))<<(63-i));
			
   			if(i==0 || i==11)
   			{
   				k=0;
				j++;
   			}
		}	
   		
		printf("%f\n",num2);
	}
		
	return 0;
}
