#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int **A=NULL, **B=NULL, N, M, K, **C=NULL;

	scanf("%d %d", &N, &M);
	A=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		A[n]=(int *)malloc(M*sizeof(int));

	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			scanf("%d", &A[n][m]);

	scanf("%d %d", &M, &K);
	B=(int **)malloc(M*sizeof(int *));
	for(int m=0;m<M;m++)
		B[m]=(int *)malloc(K*sizeof(int));

	for(int m=0;m<M;m++)
		for(int k=0;k<K;k++)
			scanf("%d", &B[m][k]);

	C=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		C[n]=(int *)calloc(K,sizeof(int));

	for(int n=0;n<N;n++)
		for(int k=0;k<K;k++)
			for(int m=0;m<M;m++)
				C[n][k]+=A[n][m]*B[m][k];

	for(int n=0;n<N;n++)
	{
		for(int k=0;k<K;k++)
			printf("%d ", C[n][k]);
		printf("\n");
	}
	for(int n=0;n<N;n++)
		free(C[n]);
	free(C);
	for(int m=0;m<M;m++)
		free(B[m]);
	free(B);
	for(int n=0;n<N;n++)
		free(A[n]);
	free(A);
	return 0;
}