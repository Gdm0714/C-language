/*    Program 2-2      */      		            
/* Gauss-Jordan Method */      

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>                               
#include<stdlib.h>                              
#include<math.h>                                
                                                
main()                                          
{                                               
	double A[11][12], sum, temp, pivot;         
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
                                                
	for(k=1;k<=n;k++){                          
		pivot = A[k][k];                        
		for(j=k;j<=n+1;j++)                     
			A[k][j] = A[k][j]/pivot;            
		for(i=1;i<=n;i++){                      
			if (i != k){
				pivot = A[i][k];
				for (j = k; j <= n + 1; j++)
					A[i][j] -= pivot*A[k][j];
			}
		}                                       
	}                                           
                                                
	for(i=1;i<=n;i++)                           
		if(A[i][i] == 0){                       
			printf("Check error!\n");           
			exit(1);                            
		}                                       
	printf("\n ***** Solution *****\n");        
	for(i=1;i<=n;i++)                           
		printf(" X[%d]= %lf\n",i,A[i][n+1]);    
}                                               
