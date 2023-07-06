#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *tree=NULL, left=0, right=0, mid, ans;
	long long sum;

	scanf("%d%d", &N, &M);
	tree=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &tree[n]);
		right=tree[n]>right?tree[n]:right;
	}

	while(left<=right)
	{
		sum=0;
		mid=(left+right)>>1;

		for(int n=0;n<N;n++)
			if(tree[n]>mid)
				sum+=tree[n]-mid;

		if(sum<M)
			right=mid-1;
		else
		{
			ans=mid;
			left=mid+1;
		}
	}

	printf("%d\n", ans);
	free(tree);
	return 0;
}