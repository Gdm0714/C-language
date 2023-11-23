/*          Program 4-1        */
/* Newton Interpolation Method */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(void)
{
	double x[11], f[11], df[11][11], xi, xterm, pnx;
	int m, n, i, j;

	printf("Input the number of (x,f(x)) : ");
    scanf("%d", &m);

	n = m - 1;
	printf("Input x & f(x) :\n");
	for(i=0;i<=n;i++)
		scanf("%lf%lf", &x[i], &f[i]);
	printf("Input x for interpolation : ");
	scanf("%lf", &xi);
    
	for(i=0;i<=n;i++) df[i][0] = f[i];
	for(j=1;j<=n;j++)
		for(i=0;i<=n-j+1;i++)
			df[i][j] = (df[i+1][j-1] - df[i][j-1]) / (x[i+j] - x[i]);
	
	pnx = df[0][0];
	for(i=1;i<=n;i++){
		xterm = 1;
		for(j=0;j<=i-1;j++)
			xterm *= (xi - x[j]);
		pnx += (df[0][i] * xterm);
	}
	
	printf("\n   ******* Newton Interpolation Table ********\n\n    X     F(x)");
	for(i=0;i<=n;i++){
		printf("\n %6.3lf", x[i]);
		for(j=0;j<=n-i;j++)
			printf(" % 7.5lf", df[i][j]);
	}
	printf("\n\n x = %10.8lf  Pn(x) = %10.8lf\n", xi, pnx);
}

