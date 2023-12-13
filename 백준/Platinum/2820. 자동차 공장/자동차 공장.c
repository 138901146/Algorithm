#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int origin, descendant;
	long long fee;
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

long long get(long long *tree,long long *lazy,int node,int start,int end,int target)
{
	update_lazy(tree,lazy,node,start,end);

	if(target>end || target<start)
		return 0;
	if(target<=start && end<=target)
		return tree[node];

	return get(tree,lazy,node<<1,start,(start+end)>>1,target)+get(tree,lazy,node<<1|1,((start+end)>>1)+1,end,target);
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
	int N, M, *senior=NULL, employee;
	long long *fee=NULL, *tree=NULL, *lazy=NULL, x;
	char operation;

	scanf("%d%d", &N, &M);
	senior=(int *)malloc((N+1)*sizeof(int));
	junior=(int **)malloc((N+1)*sizeof(int *));
	junior_count=(int *)calloc(N+1,sizeof(int));
	arr=(node *)malloc((N+1)*sizeof(node));

	arr[1].origin=senior[1]=0;
	scanf("%lld", &arr[1].fee);
	for(int n=2;n<=N;++n)
	{
		scanf("%lld%d", &arr[n].fee, &senior[n]);
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

	make_tree_range(1);
	fee=(long long *)malloc(N*sizeof(long long));

	for(int n=1;n<=N;++n)
	{
		fee[arr[n].origin]=arr[n].fee;
		free(junior[n]);
	}
	free(junior_count);
	free(junior);

	size=0;
	while((1<<size)<N)
		++size;
	size=1<<++size;

	tree=(long long *)malloc(size*sizeof(long long));
	lazy=(long long *)calloc(size,sizeof(long long));
	init(fee,tree,1,0,N-1);
	free(fee);

	while(M--)
	{
		getchar();
		scanf("%c%d", &operation, &employee);

		if(operation=='p')
		{
			scanf("%lld", &x);
			update_range(tree,lazy,1,0,N-1,arr[employee].origin+1,arr[employee].descendant,x);
		}
		else
			printf("%lld\n", get(tree,lazy,1,0,N-1,arr[employee].origin));
	}

	free(tree);
	free(lazy);
	free(arr);
	return 0;
}