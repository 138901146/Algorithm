#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, M, *A=NULL, *B=NULL, *C=NULL, n=0, m=0;

	scanf("%d%d", &N, &M);
	A=(int *)malloc(N*sizeof(int));
	B=(int *)malloc(M*sizeof(int));
	C=(int *)malloc((N+M)*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);
	for(int i=0;i<M;i++)
		scanf("%d", &B[i]);

	qsort((void *)A,(size_t)N,sizeof(int),compare);
	qsort((void *)B,(size_t)M,sizeof(int),compare);

	for(int i=0;i<N+M;i++)
		if(n==N)
			C[i]=B[m++];
		else if(m==M)
			C[i]=A[n++];
		else if(A[n]<B[m])
			C[i]=A[n++];
		else
			C[i]=B[m++];

	for(int i=0;i<N+M;i++)
		printf("%d ", C[i]);
	printf("\n");
	free(A);
	free(B);
	free(C);
	return 0;
}