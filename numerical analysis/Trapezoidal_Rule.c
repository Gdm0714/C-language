/*	 Program 6-1		 */
/*	Trapezoidal Rule	 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

void main()
{
	double h, inter_A, boundary_A, area;
	int i, j, n;
	double x[10], fx[10];

	printf("Input Number of Data : ");
	scanf("%d", &n);
	printf("Input x & f(x) : \n");

	for (i = 0; i < n; i++) {
		scanf("%lf%lf", &x[i], &fx[i]);
	}

	h = (fx[n - 1] - x[0]) / (n - 1);
	boundary_A = fx[0] + fx[n - 1];
	inter_A = 0.;

	for (j = 1; j < n - 1; j++) {
		inter_A += 2. * fx[j];
	}

	area = h / 2 * (boundary_A + inter_A);
	printf("Number of parts = %d ,  Area = %lf\n", i - 1, area);
}



/*#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

#define f(x) ((x)*(x))

void main()
{
	double h, inter_A, boundary_A, area, old, sq, EPS = 1e-5;
	int i, j, it_max;
	
	printf("Enter [Maximum Iteration], [a], [b](a < b) : \n");
	scanf("%d%lf%lf", &it_max, &a, &b);

	h = b - a;
	boundary_A = f(a) + f(b);
	inter_A = 0.;
	old = h / 2 * boundary_A;

	for (i = 1; i <= it_max; i++) {
		h /= 2.0;
		sq = pow(2, i) - 1;

		for (j = 1; j <= sq; j = j + 2)
			inter_A += 2. * f(a + j * h);

		area = h / 2 * (boundary_A + inter_A);
		printf("It = %d ,  Area = %lf\n", i, area);

		if( fabs( (area - old) / area ) < EPS ) {
			printf("The area is %lf \n", area);
			exit(0);
		}
		old = area;
	}
	printf(" Sorry, it_max exceeded !\n");
	printf(" The best approximation to the area is %lf\n", area);
}
*/
