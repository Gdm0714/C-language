/*   Program 4-2          */
/* Lagrange Interpolation */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(void)
{
	int i, j, k, m, n, n1;
	double  x[10], xi[10], f[10], P[10], sum, product;

	printf("Number of input data : ");
	scanf("%d", &n1);
	n = n1 - 1;

	printf("Input x & f(x) :\n");
	for (i = 0; i <= n; i++)
		scanf("%lf%lf", &x[i], &f[i]);

	printf("Number of output data : ");
	scanf("%d", &m);
	printf("Input x for interpolation :\n");
	for (i = 1; i <= m; i++)
		scanf("%lf", &xi[i]);

	printf("\n****** Solution ******\n");
	printf("  NO.        Point         Value ");
	
	for (k = 1; k <= m; k++) {
		sum = 0;
		for (i = 0; i <= n; i++) {
			product = f[i];
			for (j = 0; j <= n; j++) {
				if (i != j)
					product *= (xi[k] - x[j]) / (x[i] - x[j]);
			}
			sum += product;
		}
		P[k] = sum;
	}

	for (i = 1; i <= m; i++) 		
		printf("\n  %2d     %9.4lf     %10.7lf\n", i, xi[i], P[i]);
}
