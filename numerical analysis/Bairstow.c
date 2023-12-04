/*		  program 1-6		*/
/*		Bairstow Method		*/
/*						    */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void root(double p, double q);

void main(void)
{
	double a[20], b[20], c[20];
	double p, q, EPS=1.0e-4, det;
	double xr, xi, delta_p, delta_q;
	int  j, k, n, m, it, it_max=10000;
	
	printf("Input p, q : ");
	scanf("%lf%lf", &p, &q);
	printf("Input n : ");
	scanf("%d", &n);
	printf("Input a1 ~ an : ");
	for (k = 1; k <= n + 1; k++)
		scanf("%lf", &a[k]);
	j = 0;
  lable1:
	m = n - 2*j;
	j++;
	if(m-2<0){
		xr = -1*a[2]/a[1];
		xi = 0;
		printf("%12.5lg     %12.5lg\n", xr, xi);
		exit(0);
	}
	if(m-2==0){
		p = a[2]/a[1];
		q = a[3]/a[1];
		root(p,q);
		exit(0);
	}
	it = 0;
  lable2:
	b[1] = a[1];
	b[2] = a[2] - p*b[1];
	for(k=3;k<=m+1;k++)
		b[k] = a[k]-p*b[k-1]-q*b[k-2];
	c[1] = b[1];
	c[2] = b[2] - p*c[1];
	for(k=3;k<=m;k++)
		c[k] = b[k] - p*c[k-1] - q*c[k-2];
	det = pow(c[m-1],2) - c[m-2]*(c[m]-b[m]);
	if(det==0){
		printf("Not converged, Check initial values of p and q\n");
		for(k=1;k<=m;k++)
			printf("a[%d] = %lg\n", k, a[k]);
		exit(0);
	}
	delta_p = ( b[m]*c[m-1] - b[m+1]*c[m-2])/det;
	delta_q = ( b[m+1]*c[m-1] - b[m]*(c[m]-b[m]))/det;
	p += delta_p;
	q += delta_q;
	it++;
	if( (fabs(delta_p)<EPS) && (fabs(delta_q)<EPS) ){
		printf("\n p = %lf , q = %lf \n", p, q);
		printf("\n   Real part     Imaginary part\n");
		root(p,q);
		for(k=1;k<=m+1;k++)
			a[k] = b[k];
		goto lable1;
	}
	if( it<= it_max )goto lable2;
	printf("Not converged, Check initial values of p and q\n");
	for(k=1;k<=m;k++)
		printf("a[%d] = %lg\n", k, a[k]);
}
		
		

void root(double p, double q)
{
	double d, xr1, xr2, xi1, xi2;
	d = pow(p,2) - 4.*q;
	if(d<0){
		xr1 = -1*p/2.;
		xi1 = sqrt(-1*d)/2.;
		xr2 = xr1;
		xi2 = -1*xi1;
	}
	else{
		xr1 = (-1*p + sqrt(d))/2.;
		xi1 = 0;
		xr2 = (-1*p - sqrt(d))/2.;
		xi2 = 0;
	}
	printf("%12.5lg    %12.5lg\n", xr1, xi1);
	printf("%12.5lg    %12.5lg\n", xr2, xi2);
}

