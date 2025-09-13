#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, K, M, *L=NULL;
	long long left=1, right=9999999999999999, P=-1;

	scanf("%d%d%d", &N, &K, &M);
	L=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &L[n]);

	while(left<=right)
	{
		long long count=0, mid=left+right>>1;

		for(int n=0;n<N;++n)
		{
			int cut=(K<<1)<=L[n]?L[n]-(K<<1):K<L[n]?L[n]-K:0;
			count+=cut/mid;
		}

		if(count<M)
			right=mid-1;
		else
		{
			left=mid+1;
			P=mid;
		}
	}

	printf("%lld", P);
	free(L);
	return 0;
}