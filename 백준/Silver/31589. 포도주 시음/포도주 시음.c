#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?1:-1;
}

int main(void)
{
	int N, K, *T=NULL, last=0;
	long long max=0;

	scanf("%d%d", &N, &K);
	T=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &T[i]);
	qsort((void *)T,(size_t)N,sizeof(int),compare);

	for(int k=0, left=0, right=N-1;k<K;k+=2)
	{
		max+=T[left++]-last;
		last=T[right--];
	}

	printf("%lld", max);
	free(T);
	return 0;
}