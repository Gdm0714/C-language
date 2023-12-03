/*      Program 1-4      */
/* Newton-Raphson Method */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) (pow((x),2)-1)
#define df(x) (2*(x))

void main(void)
{
	double x, xn, eps=1.0e-4;
	int it=0, it_max;
	printf("Input [initial x], [max iteration]:");
	scanf("%lf%d", &xn, &it_max);
	do{
		it++;
		x = xn;
		xn = x - f(x) / df(x);
		if( it > it_max ){
			printf("Iteration= %d    Check Error!!!!", it);
			exit(1);
		}
	}while( fabs(xn - x) > eps );
	printf("Root= %f \n Iteration= %d \n", xn, it);
}
