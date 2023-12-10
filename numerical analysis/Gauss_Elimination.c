/*       Program 2-1        */
/* Gauss-Elimination Method */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main()
{
	double A[11][12],X[11],sum,temp,D;
	int n, i, j, k;
	printf("Input the number of equations : ");
	scanf("%d",&n);
	printf("Input the augmented matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n+1;j++)
			scanf("%lf",&A[i][j]);
	/* Pivoting */
	for(k=1;k<=n-1;k++){
		j=k;
		for(i=k+1;i<=n;i++)
			if( fabs(A[j][k]) < fabs(A[i][k]) )j=i;
		if(j!=k){
			for(i=1;i<=n+1;i++){
				temp=A[k][i];
				A[k][i]=A[j][i];
				A[j][i]=temp;
				}
		}
	}

	for(k=1;k<=n-1;k++){
		for(i=k+1;i<=n;i++){
			D=A[i][k]/A[k][k];
			for(j=1;j<=n+1;j++)
				A[i][j] -= D*A[k][j];
		}
	}
	X[n]=A[n][n+1]/A[n][n];
	for(j=n-1;j>=1;j--){
		sum=0;
		for(k=j+1;k<=n;k++)
			sum += A[j][k]*X[k];
		X[j]=(A[j][n+1]-sum)/A[j][j];
	}
	printf("\n ***** Solution *****\n");
	for(i=1;i<=n;i++)
		printf(" X[%d]= %lf\n",i,X[i]);
}
