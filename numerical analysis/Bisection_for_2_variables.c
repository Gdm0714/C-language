/*												*/
/*		Bisection Method for Two Variables		*/
/*												*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define g(x) (1/(x))
#define f(x,y) (pow((x),2)+pow((y),2)-2*(x)-3)
void main(void)
{
	int it_max, it=0;
	double x_low, x_up, x_mid, y_low, y_mid, f_low, f_mid, eps=1.0E-4;

	do {
		printf("Input [lower x], [upper x]:");
		scanf("%lf%lf", &x_low, &x_up);
	} while (f(x_low, g(x_low)) * f(x_up, g(x_up)) >= 0);

	printf("Input Max Iteration : ");
	scanf("%d", &it_max);
	
	do{
		y_low = g(x_low);
		f_low = f(x_low, y_low);
		x_mid = (x_low + x_up)/2.0;
		y_mid = g(x_mid);
		f_mid = f(x_mid, y_mid);

		it++;
		if(it>it_max){
		  printf("Iteration=%d Check Error!!!",it);
		  exit(1);
		}

		if( f_low * f_mid > 0 ) x_low = x_mid;
		if( f_low * f_mid < 0 ) x_up = x_mid;
	}while( fabs(x_up - x_low) > eps && f_low * f_mid != 0 );

	printf("The Answer is... \nx= %lf \ny= %lf \nIteration=%d", x_mid, y_mid, it);
	printf("\n f = %lf", f(x_mid, y_mid));
}