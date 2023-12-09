/*								 */
/*		The Secant Method		 */
/*								 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) (a[3]*pow((x),3)+a[2]*pow((x),2)+a[1]*x+a[0])


void main(void)
{
	double a[4];
	double x1, x2, x3, y1, y2, y3, eps=1.0e-4;
	int it_max, it=0;
	printf("Input a3, a2, a1, a0 : ");
	scanf("%lf%lf%lf%lf", &a[3], &a[2], &a[1], &a[0]);
	printf("Input Max Iteration & initial x1, x2 : ");
	scanf("%d%lf%lf", &it_max, &x1, &x2);
	while(1){
		it++;
		y1=f(x1);
		y2=f(x2);
		x3=(x1*y2-x2*y1)/(y2-y1);
		y3=f(x3);
		if( it>it_max ){
			printf("Iteration= %d    Check Error!!!!",it);
			exit(1);
		}
		if ( fabs(y3) < eps) break;
		if( fabs(x2-x1) < eps ) break;
			else x1=x2, x2=x3;
	};
	printf("\nf(x) = %5.2lfx^3 + %5.2lfx^2 + %5.2lfx + %5.2lf\n",
		a[3],a[2],a[1],a[0]);
	printf("Root=        %lf\nIteration=  %d \n",x3,it);
}
