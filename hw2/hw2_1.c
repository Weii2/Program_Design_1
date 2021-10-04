#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	float a=atof(argv[1]);
	int i,j;
	double x0,x1;
	
	i=atoi(argv[2]);
	x1=1;
				
	for(j=0; j<i; j++)
	{
		x0=x1;
		x1=0.5*(x1+a/x1);
		printf("%.10f\n",x1);
	}
	
	return 0;
} 
