#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(long long *)x<*(long long *)y?-1:1;
}

int main(void)
{
	int N;
	long long *A=NULL;

	scanf("%d", &N);

	A=(long long *)malloc(N*sizeof(long long));

	for(int i=0;i<N;++i)
		scanf("%lld", &A[i]);

	qsort((void *)(A+1),(size_t)N-1,sizeof(long long),compare);

	for(int i=1;i<N;++i)
		if(A[0]<=A[i])
		{
			printf("No");
			free(A);
			return 0;
		}
		else
			A[0]+=A[i];

	printf("Yes");
	free(A);
	return 0;
}