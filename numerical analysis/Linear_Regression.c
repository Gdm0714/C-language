/*           Program 5-1             */
/*    Linear Regression Analysis     */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void main()
{
	double x[100], f[100], xs, fs, xxs, xfs, a, b;
	int i, n;

	printf("Number of data : ");
	scanf("%d", &n);

	printf("Input x & f(x) :\n");
	for (i = 1; i <= n; i++) 
		scanf("%lf%lf", &x[i], &f[i]);

	xs = fs = xxs = xfs = 0.;
	for (i = 1; i<=n; i++) {
		xs  += x[i];
		fs  += f[i];
		xxs += x[i]*x[i];
		xfs += x[i]*f[i];
	}
	a = (n * xfs - xs * fs) / (n * xxs - xs * xs);
	b = (fs - a * xs) / n;

	printf("\n y = %8.5lfx + %8.5lf \n", a, b);
}
