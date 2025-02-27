#include<stdio.h>
#include<malloc.h>

void init(int *arr,long long *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=arr[start];
	else
	{
		init(arr,tree,node<<1,start,(start+end)>>1);
		init(arr,tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

void update_lazy(long long *tree,long long *lazy,int node,int start,int end)
{
	if(lazy[node]!=0)
	{
		tree[node]^=lazy[node];
		if(start!=end)
		{
			lazy[node<<1]^=lazy[node];
			lazy[node<<1|1]^=lazy[node];
		}
		lazy[node]=0;
	}
}

long long get(long long *tree,long long *lazy,int node,int start,int end,int left,int right)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return 0;
	if(left<=start && end<=right)
		return tree[node];

	return get(tree,lazy,node<<1,start,(start+end)>>1,left,right)+get(tree,lazy,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update_range(long long *tree,long long *lazy,int node,int start,int end,int left,int right,int c)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		tree[node]^=c;
		if(start!=end)
		{
			lazy[node<<1]^=c;
			lazy[node<<1|1]^=c;
		}

		return;
	}

	update_range(tree,lazy,node<<1,start,(start+end)>>1,left,right,c);
	update_range(tree,lazy,node<<1|1,((start+end)>>1)+1,end,left,right,c);
	tree[node]=tree[node<<1]+tree[node<<1|1];
}

int main(void)
{
	int N, M, *arr=NULL, operation, a, b, c, size=0;
	long long *tree=NULL, *lazy=NULL, calculation;

	scanf("%d", &N);
	arr=(int *)malloc(N*sizeof(int));
	while((1<<size)<N)
		++size;
	size=1<<++size;

	for(int n=0;n<N;++n)
		scanf("%d", &arr[n]);

	tree=(long long *)malloc(size*sizeof(long long));
	init(arr,tree,1,0,N-1);
	free(arr);
	lazy=(long long *)calloc(size,sizeof(long long));

	scanf("%d", &M);
	while(M--)
	{
		scanf("%d%d", &operation, &a);

		if(operation==1)
		{
			scanf("%d%d", &b, &c);
			update_range(tree,lazy,1,0,N-1,a,b,c);
		}
		else
			printf("%lld\n", get(tree,lazy,1,0,N-1,a,a));
	}

	free(tree);
	free(lazy);
	return 0;
}