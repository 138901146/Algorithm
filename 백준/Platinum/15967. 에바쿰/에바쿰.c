#include<stdio.h>
#include<malloc.h>

void init(int *a,long long *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=a[start];
	else
	{
		init(a,tree,node<<1,start,(start+end)>>1);
		init(a,tree,node<<1|1,((start+end)>>1)+1,end);
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
	int N, M, *a=NULL, operation[4], size=0, Q1, Q2;
	long long *tree=NULL, *lazy=NULL;

	scanf("%d%d%d", &N, &Q1, &Q2);
	a=(int *)malloc(N*sizeof(int));
	while((1<<size)<N)
		size++;
	size++;
	size=1<<size;
	Q1+=Q2;

	for(int i=0;i<N;i++)
		scanf("%d", &a[i]);

	tree=(long long *)malloc(size*sizeof(long long));
	init(a,tree,1,0,N-1);
	free(a);
	lazy=(long long *)calloc(size,sizeof(long long));

	for(int q=0;q<Q1;q++)
	{
		for(int i=0;i<3;i++)
		{
			scanf("%d", &operation[i]);
			operation[i]--;
		}

		if(operation[0])
		{
			scanf("%d", &operation[3]);
			update_range(tree,lazy,1,0,N-1,operation[1],operation[2],operation[3]);
		}
		else
			printf("%lld\n", get(tree,lazy,1,0,N-1,operation[1],operation[2]));
	}

	free(tree);
	free(lazy);
	return 0;
}