#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	char IP[4][3]={"129","160","96","1"};
	unsigned int num1[4]={0}, num2[4]={0}, s=0, t=0;

	for(int i=0; i<4; i++)
	{
		num1[i]=atoi(IP[i]);
		for (int j=7; j>=0; j--)
		{
	    	if( (1<<j) & num1[i] )
	    		printf("1");
	    	else
	    		printf("0");
		}
	}
	
	printf("\n");
	
	char bit[]="10000001101000000110000000000001";
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<8; j++)
		{
			num2[i]=num2[i]+(int)pow(2,7-j) * (bit[t++]-'0');
			
		}
		printf("%d.",num2[i]);
	}
	printf("\b \n");
	
	return 0;
}

