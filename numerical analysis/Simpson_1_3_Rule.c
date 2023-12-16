/*          Program 6-3				 */
/* Integration by Simpson's 1/3 Rule */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) pow((x), 4)

void main()
{
	double a, b, h, old = 0., area, sq, EPS = 1e-5;
	int i, j, it_max;

	printf("Enter [a], [b](a<b), [max_i] : \n");
	scanf("%lf%lf%d", &a, &b, &it_max);

	h = b - a;

	for (i = 1; i <= it_max; i++) {
		
		h = h / 2.;
		sq = pow(2, i) - 1;
		area = f(a) + f(b);

		for (j = 1; j <= sq; j++) {
			if ( j % 2 == 0 ) 
				area += 2. * f(a + j * h);
			else 
				area += 4. * f(a + j * h);
		}

		area *= h / 3.;
		printf("It = %d ,  Area = %lf\n", i, area);

		if ( fabs( (area - old) / area) < EPS ) {
			printf("Area = %lf\n", area);
			exit(0);
		}
		old = area;
	}
	printf(" Sorry, it_max exceeded !\n");
	printf(" The best approximation to the area is %lf\n", area);
}
