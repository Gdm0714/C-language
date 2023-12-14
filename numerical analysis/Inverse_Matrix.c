#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main()
{
	int i, j, k, n, m;
	double A[11][21], x[11], b[11], pivot, sum;
	printf("Input the number of equations : ");
	scanf("%d", &n);
	m = 2 * n;
	printf("-- Input Matrix A --\n");
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) //b는 따로 받기
			scanf("%lf", &A[i][j]);

	printf("-- Input Vector b --\n");
	for (i = 1; i <= n; i++) scanf("%lf", &b[i]);

	for (i = 1; i <= n; i++)
		for (j = n + 1; j <= m; j++) {
			if (i == j - n)A[i][j] = 1.; //대각원소는 1
			else A[i][j] = 0.; //나머지는 0
		}
	for (k = 1; k <= n; k++) {
		pivot = A[k][k];
		for (j = k; j <= m; j++)
			A[k][j] /= pivot; //1로 만드는 과정
		for (i = 1; i <= n; i++) {
			if (i == k)continue;
			pivot = A[i][k];
			for (j = k; j <= m; j++)
				A[i][j] -= pivot * A[k][j]; //왼쪽은 I, 오른쪽은 역행렬
		}
	}
	printf("-- Inverse Matrix --\n");
	for (i = 1; i <= n; i++) {
		for (j = n + 1; j <= m; j++)
			printf(" %9.4lf", A[i][j]); //A 가지고 b를 구하는 것이 과제
		printf("\n");
	}
	printf("***** Solution *****\n");
	for (i = 1; i <= n; i++) {
		sum = 0;
		for (j = n + 1; j <= m; j++)
			sum += A[i][j] * b[j - n];
		printf("x[%d] : %lf \n", i, sum);
	}
}