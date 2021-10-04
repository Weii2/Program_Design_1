#include <stdio.h>

int purely_recursive(int i, int f0, int f1, int f2)
{
	if(i==3)
		return f0+f1+f2;
	else if(i==2)
		return f2;
	else if(i==1)
		return f1;
	else if(i==0)
		return f0;
	return purely_recursive(i-1,f0,f1,f2) + purely_recursive(i-2,f0,f1,f2) + purely_recursive(i-3,f0,f1,f2);
}

int iterative(int i, int f0, int f1, int f2)
{
	int fi, p, q;
	
	for(int j=3; j<=i; j++)
	{
		fi=f0+f1+f2;
		p=f2; q=f1;
		f2=fi; f1=p; f0=q;
	}
	
	return fi;
}

int new_recursive(int i, int f0, int f1, int f2)
{
	int arr[100]={0}, a=0, b=0, c=0;
	arr[3]=f0+f1+f2; arr[2]=f2; arr[1]=f1; arr[0]=f0;
		
	if(arr[i]!=0)
		return arr[i];
	else if(i==3)
		return arr[i];
	else if(i==2)
		return arr[i];
	else if(i==1)
		return arr[i];
	else if(i==0)
		return arr[i];

	a=new_recursive(i-1,f0,f1,f2);
	b=new_recursive(i-2,f0,f1,f2);
	c=new_recursive(i-3,f0,f1,f2);
	arr[i]=a+b+c;
	
	return arr[i];
}


int main()
{
	int f0=0, f1=1, f2=2;
	
	printf("(1) %d\n",purely_recursive(7,f0,f1,f2));
	printf("(2) %d\n",iterative(7,f0,f1,f2));	
	printf("(3) %d\n",new_recursive(7,f0,f1,f2));
	return 0;
}

