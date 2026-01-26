#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(long long *)x<*(long long *)y?-1:1;
}

long long absll(long long x)
{
	return x<0?-x:x;
}

int main(void)
{
	long long N, Q, *P=NULL, *X=NULL, *sum=NULL, *score=NULL;

	scanf("%lld%lld", &N, &Q);
	P=(long long *)calloc(N+1,sizeof(long long));
	X=(long long *)malloc(Q*sizeof(long long));

	for(int i=1;i<=N;++i)
		scanf("%lld", &P[i]);
	for(int i=0;i<Q;++i)
		scanf("%lld", &X[i]);

	qsort((void *)P,(size_t)N+1,sizeof(long long),compare);
	sum=(long long *)calloc(N+1,sizeof(long long));
	score=(long long *)calloc(Q,sizeof(long long));

	for(int i=1;i<=N;++i)
		sum[i]=sum[i-1]+P[i];

	for(int i=0;i<Q;++i)
	{
		int left=1, right=N, center=1;

		while(left<=right)
		{
			int mid=left+right>>1;

			if(P[mid]<=X[i])
			{
				left=mid+1;
				center=mid;
			}
			else
				right=mid-1;
		}

		score[i]=(long long)absll(center*X[i]-sum[center])+absll(sum[N]-sum[center]-(N-center)*X[i]);
	}

	for(int i=0;i<Q;++i)
		printf("%lld\n", score[i]);
	free(P);
	free(X);
	free(sum);
	free(score);
	return 0;
}