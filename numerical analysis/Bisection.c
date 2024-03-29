/*      Program 1-2     */
/* The Bisection Method */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) (a[3]*pow((x),3)+a[2]*pow((x),2)+a[1]*(x)+a[0])

main()
{
	double a[4];
	double low_x, high_x, mid_x, low_y, high_y, mid_y, eps=1.0e-4;
	int it_max, it=0;
	printf("Input a[3-0] : ");
	scanf("%lf%lf%lf%lf", &a[3], &a[2], &a[1], &a[0]);
	do{
		printf("Lower, Upper x Guess : ");
		scanf("%lf%lf", &low_x, &high_x);
	}while( f(low_x) * f(high_x) >= 0 );
	printf("Input Max Iteration : ");
	scanf("%d", &it_max);
	while(1){
		it++;
		mid_x=(low_x+high_x)/2.0;
		low_y=f(low_x);
		high_y=f(high_x);
		mid_y=f(mid_x);
		if( it>it_max ){
			printf("Iteration= %d    Check Error!!!!",it);
			exit(1);
		}
		if( low_y*mid_y>0 )low_x=mid_x;
		if( low_y*mid_y<0 )
			if( fabs(high_x-low_x)<eps )break;
			else high_x=mid_x;
		if( low_y*mid_y==0. )break;
	};
	printf("nf(x) = %lfx^3 + %lfx^2 + %lfx + %lf\n",a[3],a[2],a[1],a[0]);
	printf("Root= %lf \n Iteration= %d \n",mid_x,it);
}

