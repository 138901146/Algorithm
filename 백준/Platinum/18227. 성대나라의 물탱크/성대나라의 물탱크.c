#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int origin, descendant, depth;
}
node;

int size=0, *child_count=NULL, **child=NULL;
node *arr=NULL;

int make_tree(int current)
{
	for(int i=0;i<child_count[current];++i)
		if(!arr[child[current][i]].depth)
		{
			arr[child[current][i]].origin=++size;
			arr[child[current][i]].depth=arr[current].depth+1;
			arr[child[current][i]].descendant=make_tree(child[current][i]);
		}

	return arr[current].descendant=size;
}

int get(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,(start+end)>>1,left,right)+get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update(int *tree,int node,int start,int end,int index)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		++tree[node];
		return;
	}
	else
	{
		update(tree,node<<1,start,(start+end)>>1,index);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, Q, C, *tree=NULL, operation, A, **edge=NULL;

	scanf("%d%d", &N, &C);
	child=(int **)malloc((N+1)*sizeof(int *));
	child_count=(int *)calloc(N+1,sizeof(int));
	edge=(int **)malloc(N*sizeof(int *));

	for(int n=1;n<N;++n)
	{
		edge[n]=(int *)malloc(2*sizeof(int));
		for(int i=0;i<2;++i)
		{
			scanf("%d", &edge[n][i]);
			++child_count[edge[n][i]];
		}
	}

	for(int n=1;n<=N;++n)
	{
		child[n]=(int *)malloc(child_count[n]*sizeof(int));
		child_count[n]=0;
	}

	for(int n=1;n<N;++n)
	{
		for(int i=0;i<2;++i)
			child[edge[n][i]][child_count[edge[n][i]]++]=edge[n][i^1];
		free(edge[n]);
	}
	free(edge);

	arr=(node *)calloc(N+1,sizeof(node));

	arr[C].depth=1;
	make_tree(C);

	for(int n=1;n<=N;++n)
		free(child[n]);
	free(child_count);
	free(child);

	size=0;
	while((1<<size)<N)
		++size;
	size=1<<++size;
	tree=(int *)calloc(size,sizeof(int));

	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d%d", &operation, &A);

		if(operation==1)
			update(tree,1,0,N-1,arr[A].origin);
		else
			printf("%lld\n", (long long)arr[A].depth*get(tree,1,0,N-1,arr[A].origin,arr[A].descendant));
	}

	free(tree);
	free(arr);
	return 0;
}