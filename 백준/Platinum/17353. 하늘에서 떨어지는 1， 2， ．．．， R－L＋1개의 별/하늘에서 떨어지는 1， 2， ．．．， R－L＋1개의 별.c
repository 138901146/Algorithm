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
	int N, Q, operation, L, R, X, size=0, arr[2], *diff=NULL;
	long long *tree=NULL, *lazy=NULL;

	scanf("%d", &N);
	diff=(int *)malloc(N*sizeof(int));
	while((1<<size)<N)
		++size;
	size=1<<++size;

	scanf("%d", &arr[0]);
	diff[0]=arr[0];
	for(int n=1;n<N;++n)
	{
		scanf("%d", &arr[n&1]);
		diff[n]=arr[n&1]-arr[n&1^1];
	}

	tree=(long long *)malloc(size*sizeof(long long));
	init(diff,tree,1,0,N-1);
	free(diff);
	lazy=(long long *)calloc(size,sizeof(long long));

	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d", &operation);

		if(operation==1)
		{
			scanf("%d%d", &L, &R);
			update_range(tree,lazy,1,0,N-1,L-1,R-1,1);
			update_range(tree,lazy,1,0,N-1,R,R,-R+L-1);
		}
		else
		{
			scanf("%d", &X);
			printf("%lld\n", get(tree,lazy,1,0,N-1,0,X-1));
		}
	}

	free(tree);
	free(lazy);
	return 0;
}