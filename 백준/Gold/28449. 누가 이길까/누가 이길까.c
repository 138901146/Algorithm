#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, M, *a=NULL, *b=NULL;
	long long HI=0, ARC=0, draw=0, arc=0, previous[2];

	scanf("%d%d", &N, &M);
	a=(int *)malloc(N*sizeof(int));
	b=(int *)malloc(M*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &a[i]);
	for(int i=0;i<M;++i)
		scanf("%d", &b[i]);

	qsort((void *)a,(size_t)N,sizeof(int),compare);
	qsort((void *)b,(size_t)M,sizeof(int),compare);

	for(int hi=0;hi<N;++hi)
	{
		if(hi && a[hi]==a[hi-1])
		{
			HI+=previous[0];
			draw+=previous[1];
			ARC+=M-arc;
			continue;
		}

		while(arc<M && b[arc]<a[hi])
			++arc;

		HI+=arc;
		previous[0]=arc;

		previous[1]=0;
		while(arc<M && a[hi]==b[arc])
		{
			++previous[1];
			++arc;
		}
		draw+=previous[1];

		ARC+=M-arc;
	}

	printf("%lld %lld %lld", HI, ARC, draw);
	free(a);
	free(b);
	return 0;
}