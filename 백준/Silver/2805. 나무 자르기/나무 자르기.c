#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool able(long long *tree,long long N,long long M,long long mid)
{
	long long sum=0;

	for(long long n=0;n<N;n++)
		sum+=tree[n]-mid>0?tree[n]-mid:0;

	return sum>=M;
}

int main(void)
{
	long long N, M, *tree=NULL, low=0, high=1000000000;

	scanf("%lld%lld", &N, &M);
	tree=(long long *)malloc(N*sizeof(long long));

	for(long long n=0;n<N;n++)
		scanf("%lld", &tree[n]);

	while(low<=high)
	{
		long long mid=(low+high)/2;

		if(able(tree,N,M,mid))
			low=mid+1;
		else
			high=mid-1;
	}

	printf("%lld\n", high);
	free(tree);
	return 0;
}