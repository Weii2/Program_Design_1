#include <stdio.h>
#include <math.h>

int determinant(int f[][10],int x)
{
	int pr=1, c[10], d=0, b[10][10], j, p, q, t;
	if(x==2) return (f[0][0]*f[0][1] - f[1][1]*f[1][0]);
 	for (j=0; j<x; j++){
 	int r=0,s=0;
	for (p=0; p<x; p++) {
 		for (q=0; q<x; q++) {
 			if (p!=0 && q!=j) {
 				b[r][s]=f[p][q];
				s++;
 				if(s > x-2) { r++; s=0; }
 			}
 		}
 	}
 	pr=pow(-1,j);
 	c[j] = pr*determinant(b,x-1);
 	}
	for(j=0,d=0;j<=x;j++) d += (f[0][j]*c[j]);
 	return d;
}

int main()
{
	int f[10][10]={
			{2,5,4},
			{-1,4,1},
			{1,1,1}
			};
	int d=determinant(f,3);
	printf("%d\n",d);
}

