#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?-1:1;
}

int main(void)
{
	int N, K, tall[2], *difference=NULL;
	long long total=0;

	scanf("%d%d", &N, &K);
	difference=(int *)malloc((N-1)*sizeof(int));

	scanf("%d", &tall[0]);
	for(int n=1;n<N;++n)
	{
		scanf("%d", &tall[n&1]);
		difference[n-1]=tall[n&1]-tall[n&1^1];
	}

	qsort((void *)difference,(size_t)--N,sizeof(int),compare);

	for(int n=K-1;n<N;++n)
		total+=difference[n];

	printf("%lld", total);
	free(difference);
	return 0;
}