#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *A=NULL, *B=NULL;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	B=(int *)malloc(N*sizeof(int));

	scanf("%d", &B[0]);
	A[0]=B[0];
	for(int i=1;i<N;i++)
	{
		scanf("%d", &B[i]);
		A[i]=(i+1)*B[i]-i*B[i-1];
	}

	for(int i=0;i<N;i++)
		printf("%d ", A[i]);
	printf("\n");
	free(A);
	free(B);
	return 0;
}