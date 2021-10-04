#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
	int n;
	double ans,i,j;
	
	n=atoi(argv[1]);
	ans=1;
	j=1;
			
	for(i=1; i<=n; i++)
	{
		ans=ans+1/j;
		j=j*(j+1);
		
		printf("%.10f\n",ans);
	}
	
	return 0;
} 
