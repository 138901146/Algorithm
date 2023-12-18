#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int origin, descendant;
}
node;

int size=0, *junior_count=NULL, **junior=NULL;
node *arr=NULL;

int make_tree_range(int current)
{
	for(int i=0;i<junior_count[current];++i)
	{
		arr[junior[current][i]].origin=++size;
		arr[junior[current][i]].descendant=make_tree_range(junior[current][i]);
	}

	return arr[current].descendant=size;
}

void init(int *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=1;
	else
	{
		init(tree,node<<1,start,(start+end)>>1);
		init(tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

void update_lazy(int *tree,int *lazy,int node,int start,int end)
{
	if(lazy[node]!=0)
	{
		tree[node]=lazy[node]==1?end-start+1:0;
		if(start!=end)
		{
			lazy[node<<1]=lazy[node];
			lazy[node<<1|1]=lazy[node];
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

	return get(tree,lazy,node<<1,start,(start+end)>>1,left,right)+get(tree,lazy,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update_range(int *tree,int *lazy,int node,int start,int end,int left,int right,int flag)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		tree[node]=flag==1?end-start+1:0;
		if(start!=end)
		{
			lazy[node<<1]=flag;
			lazy[node<<1|1]=flag;
		}

		return;
	}

	update_range(tree,lazy,node<<1,start,(start+end)>>1,left,right,flag);
	update_range(tree,lazy,node<<1|1,((start+end)>>1)+1,end,left,right,flag);
	tree[node]=tree[node<<1]+tree[node<<1|1];
}

int main(void)
{
	int N, M, *senior=NULL, *tree=NULL, *lazy=NULL, operation, employee;

	scanf("%d", &N);
	senior=(int *)malloc((N+1)*sizeof(int));
	junior=(int **)malloc((N+1)*sizeof(int *));
	junior_count=(int *)calloc(N+1,sizeof(int));

	scanf("%d", &senior[1]);
	for(int n=2;n<=N;++n)
	{
		scanf("%d", &senior[n]);
		++junior_count[senior[n]];
	}

	for(int n=1;n<=N;++n)
	{
		junior[n]=(int *)malloc(junior_count[n]*sizeof(int));
		junior_count[n]=0;
	}

	for(int n=2;n<=N;++n)
		junior[senior[n]][junior_count[senior[n]]++]=n;

	free(senior);
	arr=(node *)malloc((N+1)*sizeof(node));

	arr[1].origin=0;
	make_tree_range(1);

	for(int n=1;n<=N;++n)
		free(junior[n]);
	free(junior_count);
	free(junior);

	size=0;
	while((1<<size)<N)
		++size;
	size=1<<++size;

	tree=(int *)calloc(size,sizeof(int));
	lazy=(int *)calloc(size,sizeof(int));
	init(tree,1,0,N-1);

	scanf("%d", &M);
	while(M--)
	{
		scanf("%d%d", &operation, &employee);

		if(operation==1)
			update_range(tree,lazy,1,0,N-1,arr[employee].origin+1,arr[employee].descendant,1);
		else if(operation==2)
			update_range(tree,lazy,1,0,N-1,arr[employee].origin+1,arr[employee].descendant,-1);
		else
			printf("%d\n", get(tree,lazy,1,0,N-1,arr[employee].origin+1,arr[employee].descendant));
	}

	free(tree);
	free(lazy);
	return 0;
}