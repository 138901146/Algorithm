#include<stdio.h>
#include<malloc.h>

#define INF 4000000000

int main(void)
{
	int N, *X=NULL;
	long long K, left=INF, right=INF, T;

	scanf("%d%lld", &N, &K);
	X=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &X[i]);

	for(int i=0;i<N;++i)
		left=X[i]<left?X[i]:left;

	T=left;
	while(left<=right)
	{
		long long mid=left+right>>1, count=0;

		for(int i=0;i<N;++i)
			if((long long)X[i]<mid)
				count+=mid-X[i];

		if(count<=K)
		{
			T=mid;
			left=mid+1;
		}
		else
			right=mid-1;
	}

	printf("%lld", T);
	free(X);
	return 0;
}