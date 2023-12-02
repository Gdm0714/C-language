/*											 */
/*				Steffensen Method			 */
/*											 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) (exp(-x)-(x)) /*(pow((x),2)-(x)-2)*/
#define g(x) (exp(-x)) /*(1+2/(x))*/ /*(pow((x),2)-2)*/ /*(2+3/(x))*/ /*(sqrt(2*(x)+3))*/ /*((pow((x),2)-3)/2)*/
void main(void)
{
	double x0, x1, x2, x, temp, eps=1.0e-4;
	int it=0, it_max;
	printf("Input [initial x], [max iteration]:");
	scanf("%lf%d", &x, &it_max);
	do{
		it++;
		x0 = x;
		x1 = g(x0);
		x2 = g(x1);
		temp = (x1 - x0);
		x = x0 - (temp * temp)/(x2 - 2 * x1 + x0);
		printf("It= %d , x= %f \n", it, x);
		if( it > it_max ){
			printf("Iteration= %d    Check Error!!!!", it);
			exit(1);
		}
		
	} while( fabs(x - x0) > eps );
	printf("\n Root= %f \n Iteration= %d \n", x, it);
}
