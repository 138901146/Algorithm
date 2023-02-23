#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int main(void)
{
	int N, *B=NULL, M, *C=NULL, count=0;
	bool *A=NULL;

	scanf("%d", &N);
	A=(bool *)malloc(N*sizeof(bool));
	B=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &A[n]);
	for(int n=0;n<N;n++)
		scanf("%d", &B[n]);

	scanf("%d", &M);
	C=(int *)malloc(M*sizeof(int));
	for(int m=0;m<M;m++)
		scanf("%d", &C[m]);

	for(int n=N-1;n>=0&&count<M;n--)
		if(!A[n])
		{
			count++;
			printf("%d ", B[n]);
		}
	for(int m=0;m<M&&count<M;m++)
	{
		count++;
		printf("%d ", C[m]);
	}
	printf("\n");

	return 0;
}