#include<stdio.h>
#include<malloc.h>

void init(long long *arr,long long *tree,int node,int start,int end)
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
		tree[node]+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[node<<1]+=lazy[node];
			lazy[node<<1|1]+=lazy[node];
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

void update_range(long long *tree,long long *lazy,int node,int start,int end,int left,int right,long long diff)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		tree[node]+=(end-start+1)*diff;
		if(start!=end)
		{
			lazy[node<<1]+=diff;
			lazy[node<<1|1]+=diff;
		}

		return;
	}

	update_range(tree,lazy,node<<1,start,(start+end)>>1,left,right,diff);
	update_range(tree,lazy,node<<1|1,((start+end)>>1)+1,end,left,right,diff);
	tree[node]=tree[node<<1]+tree[node<<1|1];
}

int main(void)
{
	int N, M, K, operation[3], size=0;
	long long *arr=NULL, *tree=NULL, *lazy=NULL, calculation;

	scanf("%d%d%d", &N, &M, &K);
	arr=(long long *)malloc(N*sizeof(long long));
	M+=K;
	while((1<<size)<N)
		size++;
	size++;
	size=1<<size;

	for(int n=0;n<N;n++)
		scanf("%lld", &arr[n]);

	tree=(long long *)malloc(size*sizeof(long long));
	init(arr,tree,1,0,N-1);
	free(arr);
	lazy=(long long *)calloc(size,sizeof(long long));

	for(int m=0;m<M;m++)
	{
		for(int i=0;i<3;i++)
		{
			scanf("%d", &operation[i]);
			operation[i]--;
		}

		if(operation[0])
			printf("%lld\n", get(tree,lazy,1,0,N-1,operation[1],operation[2]));
		else
		{
			scanf("%lld", &calculation);
			update_range(tree,lazy,1,0,N-1,operation[1],operation[2],calculation);
		}
	}

	free(tree);
	free(lazy);
	return 0;
}