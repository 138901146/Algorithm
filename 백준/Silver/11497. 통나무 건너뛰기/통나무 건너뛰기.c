#include<stdio.h>
#include<stdlib.h>

int compare(const void *x, const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, *L=NULL, *sorted=NULL, max=0;

		scanf("%d", &N);
		L=(int *)malloc(N*sizeof(int));
		sorted=(int *)malloc(N*sizeof(int));

		for(int i=0;i<N;++i)
			scanf("%d", &L[i]);
		qsort((void *)L,(size_t)N,sizeof(int),compare);

		for(int i=0;i<N;++i)
			if(i&1)
				sorted[N-1-(i>>1)]=L[i];
			else
				sorted[i>>1]=L[i];

		for(int i=1;i<N;++i)
			max=abs(sorted[i]-sorted[i-1])<max?max:abs(sorted[i]-sorted[i-1]);
		max=abs(sorted[0]-sorted[N-1])<max?max:abs(sorted[0]-sorted[N-1]);

		printf("%d\n", max);
		free(L);
		free(sorted);
	}

	return 0;
}