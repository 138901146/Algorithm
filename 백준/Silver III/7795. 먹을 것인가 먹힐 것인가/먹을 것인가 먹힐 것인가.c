#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, M, *A=NULL, *B=NULL, b=0, count=0;

		scanf("%d%d", &N, &M);
		A=(int *)malloc(N*sizeof(int));
		B=(int *)malloc(M*sizeof(int));

		for(int n=0;n<N;++n)
			scanf("%d", &A[n]);
		for(int m=0;m<M;++m)
			scanf("%d", &B[m]);

		qsort((void *)A,(size_t)N,sizeof(int),compare);
		qsort((void *)B,(size_t)M,sizeof(int),compare);

		for(int a=0;a<N;++a)
		{
			while(b<M && B[b]<A[a])
				++b;
			count+=b;
		}

		printf("%d\n", count);
		free(A);
		free(B);
	}

	return 0;
}