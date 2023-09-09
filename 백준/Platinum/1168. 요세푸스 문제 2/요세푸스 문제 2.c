#include<stdio.h>
#include<malloc.h>

void init(int *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=1;
	else
	{
		init(tree,node<<1,start,start+end>>1);
		init(tree,node<<1|1,(start+end>>1)+1,end);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int get(int *tree,int node,int start,int end,int index)
{
	if(start==end)
		return start;
	else if(index<=tree[node<<1])
		return get(tree,node<<1,start,start+end>>1,index);
	else
		return get(tree,node<<1|1,(start+end>>1)+1,end,index-tree[node<<1]);
}

void update(int *tree,int node,int start,int end,int index)
{
	if(index<start || index>end)
		return;
	else if(start==end)
		--tree[node];
	else
	{
		update(tree,node<<1,start,start+end>>1,index);
		update(tree,node<<1|1,(start+end>>1)+1,end,index);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, K, *tree=NULL, size=0, index=1;

	scanf("%d%d", &N, &K);
	while((1<<size)<N)
		++size;
	++size;
	tree=(int *)calloc(1<<size,sizeof(int));

	init(tree,1,1,N);

	printf("<");
	for(int n=0;n<N;++n)
	{
		index+=K-1;
		index%=N-n;
		if(!index)
			index=N-n;

		int next=get(tree,1,1,N,index);

		printf("%d%s", next, n==N-1?">":", ");
		update(tree,1,1,N,next);
	}

	free(tree);
	return 0;
}