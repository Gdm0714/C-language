/*				               */
/*   LU-decomposition Method   */
/*				               */

#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

LU_decomposition(double A[][17], int n);
Substitution(double A[][17], double x[], int n);
Determinant(double A[][17], int n);
Inverse_matrix(double A[][17], int n);

main()
{
	double A[16][17], x[16], temp;
	int n, i, j, k;

	printf("Input the number of equations : ");
	scanf("%d", &n);
	printf("Input the augmented matrix :\n");
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n /*+ 1*/; j++)
			scanf("%lf", &A[i][j]);

	/* Pivoting 积帆*/
	/*for ( k = 1; k <= n - 1; k++) {
		j = k;
		for (i = k + 1; i <= n; i++)
			if( fabs(A[j][k]) < fabs(A[i][k]) ) j = i;
		if( j != k ) {
			for ( i = 1; i <= n + 1; i++) {
				temp = A[k][i];
				A[k][i] = A[j][i];
				A[j][i] = temp;
			}
		}
	}
	printf("\n After Pivoting :\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n + 1; j++)
			printf("%lf ", A[i][j]);
		printf("\n");
	}*/

	LU_decomposition(A, n);
	for (i = 1; i <= n; i++)
		if (A[i][i] == 0) {
			printf("Check error!\n");
			exit(1);
		}
	Substitution(A, x, n);
	/*printf("\n ***** Solution *****\n");
	for (i = 1; i <= n; i++)
		printf(" x[%d]= %lf\n",i,x[i]);*/

	Determinant(A, n);
	Inverse_matrix(A, n);

}

LU_decomposition(double A[][17], int n)
{
	int i, j, k;
	double factor;

	for (k = 1; k <= n - 1; k++) {
		for (i = k + 1; i <= n; i++) {
			factor = A[i][k] / A[k][k];
			A[i][k] = factor;
			for (j = k + 1; j <= n; j++)
				A[i][j] = A[i][j] - factor * A[k][j];
		}
	}
	printf("\n After Decomposing :\n");
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%lf ", A[i][j]);
		printf("\n");
	}
}

Substitution(double A[][17], double x[], int n)
{
	int i, j;
	double sum;

	/* Forward Substitution */
	for (i = 2; i <= n; i++) {
		sum = A[i][n + 1];
		for (j = 1; j <= i - 1; j++)
			sum -= (A[i][j] * A[j][n + 1]);
		A[i][n + 1] = sum;
	}
	/*printf("\n ~~~ Vector y ~~~\n");
	for (i = 1; i <= n; i++)
		printf("y[%d]= %lf\n", i, A[i][n + 1]);*/

		/* Back Substitution */
	x[n] = A[n][n + 1] / A[n][n];
	for (i = n - 1; i >= 1; i--) {
		sum = 0.0;
		for (j = i + 1; j <= n; j++)
			sum += (A[i][j] * x[j]);
		x[i] = (A[i][n + 1] - sum) / A[i][i];
	}
}

Determinant(double A[][17], int n) { //青纺侥
	double det = 1.0;
	for (int i = 1; i <= n; i++) {
		det *= A[i][i];
	}
	printf("\n Determinant =  %lf \n", det);
}

Inverse_matrix(double A[][17], int n) { //开青纺
	double B[16][17];
	double x[16];
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			A[k][n + 1] = 0;
		}
		A[i][n + 1] = 1;
		Substitution(A, B[i], n);
	}

	printf("\n ***** The transpose of the inverse matrix ***** \n");
	for (int i = 1; i <= n; i++) {
		printf("Column %d  :    ", i);
		for (int j = 1; j <= n; j++) {
			printf(" %lf ", B[i][j]);
		}
		printf("\n");
	}
}