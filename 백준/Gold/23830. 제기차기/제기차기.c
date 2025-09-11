#include<stdio.h>
#include<malloc.h>

int main(void)
{
	long long N, *A=NULL, p, q, r, S, left=1, right=99999999999, K=-1;

	scanf("%lld", &N);
	A=(long long *)malloc(N*sizeof(long long));
	for(int n=0;n<N;++n)
		scanf("%lld", &A[n]);
	scanf("%lld%lld%lld%lld", &p, &q, &r, &S);

	while(left<=right)
	{
		long long score=0, mid=left+right>>1;

		for(int n=0;n<N;++n)
			if(mid+r<A[n])
				score+=A[n]-p;
			else if(A[n]<mid)
				score+=A[n]+q;
			else
				score+=A[n];

		if(score<S)
			left=mid+1;
		else
		{
			K=mid;
			right=mid-1;
		}
	}

	printf("%lld", K);
	free(A);
	return 0;
}