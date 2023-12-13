/*    Program 2-5     */
/* Gauss-Seidel Method */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	int i, j, n, it=0;
	double a[4][4], b[4], x[4];
	double a_norm, x_norm, sum, w, EPS=1e-5;
	printf("Input the number of equations : ");
	scanf("%d",&n);
	printf("Input the augmented matrix\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			scanf("%lf",&a[i][j]);
		scanf("%lf",&b[i]);
	}
	for(i=1;i<=n;i++){
		sum = 0.0;
		for(j=1;j<=n;j++)
			if(j!=i) sum += fabs(a[i][j]);
		if( fabs(a[i][i]) < sum ){
			printf("Ill condition,  i=%d",i);
			exit(0);
		}
	}
	for(i=1;i<=n;i++)
		x[i] = 10.;
	printf("Iteration");
	for(i=1;i<=n;i++)
		printf("    x%d    ",i);
	printf("\n");
	do{
		it++;
		a_norm = 0.0;
		x_norm = 0.0;
		for(i=1;i<=n;i++){
			w = b[i];
			for(j=1;j<=n;j++)
				if(j!=i) w -= a[i][j]*x[j];
			w /= a[i][i];
			a_norm += fabs(x[i]-w);
			x_norm += fabs(w);
			x[i] = w;
		}
		printf("    %-2d ",it);
		for(i=1;i<=n;i++)
			printf(" %9.5lf", x[i]);
		printf("\n");
	}while(a_norm/x_norm > EPS);
}
