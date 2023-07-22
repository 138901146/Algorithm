#include<stdio.h>
#include<malloc.h>

void init(int *A,long long *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=A[start];
	else
	{
		init(A,tree,node<<1,start,(start+end)>>1);
		init(A,tree,node<<1|1,((start+end)>>1)+1,end);
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
	int N, M, *A=NULL, operation, size=0;
	long long *tree=NULL, *lazy=NULL, calculation[3];

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	while((1<<size)<N)
		size++;
	size++;
	size=1<<size;

	for(int n=0;n<N;n++)
		scanf("%d", &A[n]);

	tree=(long long *)malloc(size*sizeof(long long));
	init(A,tree,1,0,N-1);
	free(A);
	lazy=(long long *)calloc(size,sizeof(long long));

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		scanf("%d", &operation);

		if(operation==1)
		{
			for(int i=0;i<3;i++)
				scanf("%lld", &calculation[i]);
			update_range(tree,lazy,1,0,N-1,calculation[0]-1,calculation[1]-1,calculation[2]);
		}
		else
		{
			scanf("%d", &operation);
			operation--;
			printf("%lld\n", get(tree,lazy,1,0,N-1,operation,operation));
		}
	}

	free(tree);
	free(lazy);
	return 0;
}