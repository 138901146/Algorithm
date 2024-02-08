#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, left=0, right=1000000000, mid, ans=0, *tree=NULL;

	scanf("%d%d", &N, &M);
	tree=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &tree[n]);

	while(left<=right)
	{
		long long sum=0;

		mid=left+right>>1;

		for(int n=0;n<N;++n)
			if(mid<tree[n])
				sum+=tree[n]-mid;

		if(M<=sum)
		{
			ans=mid;
			left=mid+1;
		}
		else
			right=mid-1;
	}

	printf("%d", ans);
	free(tree);
	return 0;
}