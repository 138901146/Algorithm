#include<stdio.h>
#include<malloc.h>

void update_lazy(int *tree,int *lazy,int node,int start,int end)
{
	if(lazy[node]&1)
	{
		tree[node]=end-start+1-tree[node];
		if(start!=end)
		{
			++lazy[node<<1];
			++lazy[node<<1|1];
		}
	}
	lazy[node]=0;
}

int get(int *tree,int *lazy,int node,int start,int end,int left,int right)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return 0;
	if(left<=start && end<=right)
		return tree[node];

	return get(tree,lazy,node<<1,start,(start+end)>>1,left,right)+get(tree,lazy,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update_range(int *tree,int *lazy,int node,int start,int end,int left,int right)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		tree[node]=end-start+1-tree[node];
		if(start!=end)
		{
			++lazy[node<<1];
			++lazy[node<<1|1];
		}

		return;
	}

	update_range(tree,lazy,node<<1,start,(start+end)>>1,left,right);
	update_range(tree,lazy,node<<1|1,((start+end)>>1)+1,end,left,right);
	tree[node]=tree[node<<1]+tree[node<<1|1];
}

int main(void)
{
	int N, M, *tree=NULL, *lazy=NULL, size=0, operation, S, T;

	scanf("%d%d", &N, &M);
	while((1<<size)<=N)
		++size;
	size=1<<++size;

	tree=(int *)calloc(size,sizeof(int));
	lazy=(int *)calloc(size,sizeof(int));

	while(M--)
	{
		scanf("%d%d%d", &operation, &S, &T);

		if(operation)
			printf("%d\n", get(tree,lazy,1,1,N,S,T));
		else
			update_range(tree,lazy,1,1,N,S,T);
	}

	free(tree);
	free(lazy);
	return 0;
}