#include <stdio.h>

void one(int I[][2], int v, int r[][2]){
	for(int i=0; i<4; i++)
	{
		if(v>=I[i][0] & v<=I[i][1])
		{
			r[i][0]=I[i][0];
			r[i][1]=I[i][1];
		}
	}
}

void two(int I[][2], int T[]){
	
	int s=0, t;
	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<2; j++)
		{
			if(j==0)	
				T[s++]=I[i][j]-1;
			else if(j==1)
				T[s++]=I[i][j];
		}
	}
	
	for(int i=0; i<8; i++)
	{
		for(int j=i; j<8; j++)
		{
			if(T[j]<T[i])
			{	
				t=T[j];
				T[j]=T[i];
				T[i]=t;
			}
		}
	}
	
}

int main()
{
	int I[4][2]={{3,19}, {11,33}, {18,80}, {80,100}}, r[4][2]={0}, T[8]={0};
	int v=18;
	
	one(I,v,r);
	two(I,T);
	
	for(int i=0; i<4; i++)
	{
		if(r[i][0]==0 & r[i][1]==0)
			break;
		printf("lower:%d upper:%d\n", r[i][0], r[i][1]);
	}
	
	for(int i=0; i<8; i++)
	{
		printf("%d ",T[i]);
	}
	printf("\n");
	return 0;
}

