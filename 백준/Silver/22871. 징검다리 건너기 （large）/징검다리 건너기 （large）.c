#include<stdio.h>
#include<malloc.h>

#define INF 999999999999999

int abs(int x)
{
	return x<0?-x:x;
}

long long max(long long x,long long y)
{
	return x<y?y:x;
}

long long min(long long x,long long y)
{
	return x<y?x:y;
}

int main(void)
{
	int N, *A=NULL;
	long long *K=NULL;

	scanf("%d", &N);

	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	K=(long long *)calloc(N,sizeof(long long));

	for(int i=1;i<N;++i)
	{
		K[i]=INF;

		for(int j=0;j<i;++j)
			K[i]=min(K[i],max(K[j],(long long)(i-j)*(1+abs(A[i]-A[j]))));
	}

	printf("%lld", K[N-1]);
	free(A);
	free(K);
	return 0;
}