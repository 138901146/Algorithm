#include<stdio.h>
#include<malloc.h>

#define INF 10000000000000000000

int main(void)
{
	int N, M, *T=NULL;
	unsigned long long left=1, right=INF, mid, ans=INF, count;

	scanf("%d%d", &N, &M);
	T=(int *)malloc(N*sizeof(int));

	for(int k=0;k<N;++k)
		scanf("%d", &T[k]);

	while(left<=right)
	{
		count=0;
		mid=left+right>>1;

		for(int k=0;k<N;++k)
			count+=mid/T[k];

		if(M<=count)
		{
			ans=mid;
			right=mid-1;
		}
		else
			left=mid+1;
	}

	printf("%llu", ans);
	free(T);
	return 0;
}