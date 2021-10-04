#include <stdio.h>
#define N 4

int boolfunc(int *var, int m);
int recursivebool(int *var, int n);
int combinations(int A[], int n, int k);

main()
{
	int varbool[20];
	recursivebool(varbool, N);
	
	int A[4]={4,1,2,3}, t;

	printf("count=%d\n",combinations(A, 4, 2)-2);
	
}

int boolfunc(int *var, int m)
{
	int result=var[0], i;
	for (i=1; i<m; i++) result = (result && var[i]);
	return result;
}

int recursivebool(int *var, int n)
{
	int localvar[20], i, j;
	
	if (n == 0)
	{
		for(i=0; i<N; i++) printf("%d ", var[i]);
		printf("%d\n", boolfunc(var, N));
		return;
	}

	for (j=0; j<=1; j++)
	{
		var[n-1] = j;
		recursivebool(var, n - 1);
	}
}

int localvar[20],count=1,s=0;
int combinations(int A[], int n, int k)
{
	int check=1;
	
	if(k == 0)
	{
		for(int i=0; i<1; i++)
		{
			if(localvar[i+1]<localvar[i])
				check=1;
			else
			{
				check=0;
				break;
			}
		}
		if(check==1)
		{
			printf("(");
			for(int i=1; i>=0; i--)
				printf("%d,", localvar[i]);
			printf("\b)\n");
			
			count++;
		}
		return count;
	}
	
	for(int i=s; i<4; i++)
	{	
		localvar[k-1]=A[i];
		combinations(A, n-1, k-1);
	}
	s++;
}



