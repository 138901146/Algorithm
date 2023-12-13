#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int origin, descendant;
}
node;

int size=0, *child_count=NULL, **child=NULL;
node *arr=NULL;

int make_tree_range(int current)
{
	for(int i=0;i<child_count[current];++i)
	{
		arr[child[current][i]].origin=++size;
		arr[child[current][i]].descendant=make_tree_range(child[current][i]);
	}

	return arr[current].descendant=size;
}

void update_lazy(int *tree,int *lazy,int node,int start,int end)
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

int get(int *tree,int *lazy,int node,int start,int end,int target)
{
	update_lazy(tree,lazy,node,start,end);

	if(target>end || target<start)
		return 0;
	if(target<=start && end<=target)
		return tree[node];

	return get(tree,lazy,node<<1,start,(start+end)>>1,target)+get(tree,lazy,node<<1|1,((start+end)>>1)+1,end,target);
}

void update_range(int *tree,int *lazy,int node,int start,int end,int left,int right,int diff)
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
	int N, M, *parent=NULL, *tree=NULL, *lazy=NULL, operation, employee, w;

	scanf("%d%d", &N, &M);
	parent=(int *)malloc((N+1)*sizeof(int));
	child=(int **)malloc((N+1)*sizeof(int *));
	child_count=(int *)calloc(N+1,sizeof(int));

	scanf("%d", &parent[1]);
	for(int n=2;n<=N;++n)
	{
		scanf("%d", &parent[n]);
		++child_count[parent[n]];
	}

	for(int n=1;n<=N;++n)
	{
		child[n]=(int *)malloc(child_count[n]*sizeof(int));
		child_count[n]=0;
	}

	for(int n=2;n<=N;++n)
		child[parent[n]][child_count[parent[n]]++]=n;

	free(parent);
	arr=(node *)malloc((N+1)*sizeof(node));

	arr[1].origin=0;
	make_tree_range(1);

	for(int n=1;n<=N;++n)
		free(child[n]);
	free(child_count);
	free(child);

	size=0;
	while((1<<size)<N)
		++size;
	size=1<<++size;

	tree=(int *)calloc(size,sizeof(int));
	lazy=(int *)calloc(size,sizeof(int));

	while(M--)
	{
		scanf("%d%d", &operation, &employee);

		if(operation==1)
		{
			scanf("%d", &w);
			update_range(tree,lazy,1,0,N-1,arr[employee].origin,arr[employee].descendant,w);
		}
		else
			printf("%d\n", get(tree,lazy,1,0,N-1,arr[employee].origin));
	}

	free(tree);
	free(lazy);
	free(arr);
	return 0;
}