#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
	int n;
	double ans,j;
	
	n=atoi(argv[1]);

			
	for(j=1; j<=n; j++)
	{
		ans=pow(1+1/j,j);
		printf("%.10f\n",ans);
	}
	
	return 0;
} 
