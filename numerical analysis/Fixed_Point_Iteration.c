/*											 */
/*		Fixed_Point_Iteration Method		 */
/*											 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) (exp(-x)-(x)) /*(pow((x),2)-(x)-2)*/ /*(pow((x),1)-2*(x)-3)*/
#define g(x) (exp(-x)) /*(pow((x),2)-2)*/ /*(1+2/(x))*/ /*(2+3/(x))*/ /*(sqrt(2*(x)+3))*/ /*((pow((x),2)-3)/2)*/
void main(void)
{
	double x0, x1, eps=1.0e-4;
	int it=0, it_max;
	printf("Input [initial x], [max iteration]:");
	scanf("%lf%d", &x1, &it_max);
	do{
		it++;
		x0 = x1;
		x1 = g(x0);
		printf("It= %d , x= %f \n", it, x1);
		if( it > it_max ){
			printf("Iteration= %d    Check Error!!!!", it);
			exit(1);
		}
		
	} while( fabs(x1 - x0) > eps );
	printf("\n Root= %f \n Iteration= %d \n", x1, it);
	printf("f= %f \n", f(x1));
}
