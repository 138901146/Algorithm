#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:-1;
}

int main(void)
{
	int N, Q, *A=NULL, L, R;

	scanf("%d%d", &N, &Q);
	A=(int *)malloc((N+1)*sizeof(int));

	A[0]=0;
	for(int i=1;i<=N;++i)
		scanf("%d", &A[i]);
	qsort((void *)A,(size_t)(N+1),sizeof(int),compare);

	for(int i=2;i<=N;++i)
		A[i]+=A[i-1];

	while(Q--)
	{
		scanf("%d%d", &L, &R);
		printf("%d\n", A[R]-A[L-1]);
	}

	free(A);
	return 0;
}