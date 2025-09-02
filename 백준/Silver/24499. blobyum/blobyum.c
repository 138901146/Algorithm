#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, K, *A=NULL, total=0, max;

	scanf("%d%d", &N, &K);
	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<K;++i)
	{
		scanf("%d", &A[i]);
		total+=A[i];
	}
	max=total;
	for(int i=K;i<N;++i)
	{
		scanf("%d", &A[i]);
		total+=A[i]-A[i-K];
		max=total<max?max:total;
	}
	for(int i=0;i<N;++i)
	{
		total+=A[i]-A[(i+N-K)%N];
		max=total<max?max:total;
	}

	printf("%d", max);
	free(A);
	return 0;
}