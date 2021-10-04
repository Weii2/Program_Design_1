#include <stdio.h>
#include <math.h>
#define SIZE 31

void rec(int ind, int a[], int n){
	
	int b[SIZE+1];
	
	if(ind*2 > a[0])
		return;
	for(int i=1; i<8; i++)
	{
		if(ind*(1<<i) > a[0])
			break;
		for(int j=0; j < (1<<i)/2; j++)
		{
			b[j] = a[(1<<i)*ind+j];
			a[(1<<i)*ind+j] = a[(1<<i)*ind+(1<<i)/2+j];
			a[(1<<i)*ind+(1<<i)/2+j] = b[j];
		}
	}

	rec(2*ind, a, a[0]);
	rec(2*ind+1, a, a[0]);
}

void inte(int b[], int n){
	
	int t;
	
	for(int i=1; i<=4; i++)
	{
		for(int j=0; j<pow(2,i-1); j++)
		{
			t=b[(int)pow(2,i)+j];
			b[(int)pow(2,i)+j]=b[(int)pow(2,i+1)-(j+1)];
			b[(int)pow(2,i+1)-(j+1)]=t;
		}
	}
}

int main()
{	
	int a[SIZE+1]={15,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	rec(1, a, a[0]);
	for(int i=0; i<=15; i++)
		printf("%d ",a[i]);
	
	printf("\n");

	int b[SIZE+1]={15,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};	
	inte(b, b[0]);
	for(int i=0; i<=15; i++)
		printf("%d ",b[i]);
	printf("\n");
			
	return 0;
}

