#include<stdio.h>
#include<malloc.h>

void init(int *arr,int *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=arr[start];
	else
	{
		init(arr,tree,node<<1,start,(start+end)>>1);
		init(arr,tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=tree[node<<1]^tree[node<<1|1];
	}
}

void update_lazy(int *tree,int *lazy,int node,int start,int end)
{
	if(lazy[node]!=0)
	{
		if(end-start+1&1)
			tree[node]^=lazy[node];
		if(start!=end)
		{
			lazy[node<<1]^=lazy[node];
			lazy[node<<1|1]^=lazy[node];
		}

		lazy[node]=0;
	}
}

int get(int *tree,int *lazy,int node,int start,int end,int left,int right)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return 0;
	if(left<=start && end<=right)
		return tree[node];

	return get(tree,lazy,node<<1,start,(start+end)>>1,left,right)^get(tree,lazy,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update_range(int *tree,int *lazy,int node,int start,int end,int left,int right,int k)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		if(end-start+1&1)
			tree[node]^=k;
		if(start!=end)
		{
			lazy[node<<1]^=k;
			lazy[node<<1|1]^=k;
		}

		return;
	}

	update_range(tree,lazy,node<<1,start,(start+end)>>1,left,right,k);
	update_range(tree,lazy,node<<1|1,((start+end)>>1)+1,end,left,right,k);
	tree[node]=tree[node<<1]^tree[node<<1|1];
}

int main(void)
{
	int N, M, *A=NULL, *tree=NULL, *lazy=NULL, operation[3], size=0, k;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	while((1<<size)<N)
		++size;
	size=1<<++size;

	for(int n=0;n<N;++n)
		scanf("%d", &A[n]);

	tree=(int *)malloc(size*sizeof(int));
	init(A,tree,1,0,N-1);
	free(A);
	lazy=(int *)calloc(size,sizeof(int));

	scanf("%d", &M);
	while(M--)
	{
		for(int i=0;i<3;++i)
			scanf("%d", &operation[i]);

		if(--operation[0])
			printf("%d\n", get(tree,lazy,1,0,N-1,operation[1],operation[2]));
		else
		{
			scanf("%d", &k);
			update_range(tree,lazy,1,0,N-1,operation[1],operation[2],k);
		}
	}

	free(tree);
	free(lazy);
	return 0;
}