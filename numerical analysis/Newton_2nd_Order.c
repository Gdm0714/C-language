/*          Program 1-5         */
/* Newton's Second-Order Method */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) (pow((x),2)-1)
#define df(x) (2*(x))
#define ddf(x) (2)

void main(void)
{
	double x, xn, eps=1.0e-4;
	int it=0, it_max;
	printf("\nInput [initial x], [maximum iteration]: ");
	scanf("%lf%d",&xn,&it_max);
	do{
		it++;
		x = xn;
		xn = x - f(x)/(df(x) - ddf(x) * f(x)/(2.0 * df(x)));
		if( it > it_max ){
			printf("Iteration= %d    Check Error!!!!", it);
			exit(1);
		}
	}while( fabs(f(xn)) > eps );
	printf("Root=       %lf \nIteration=  %d \n", xn, it);
}


