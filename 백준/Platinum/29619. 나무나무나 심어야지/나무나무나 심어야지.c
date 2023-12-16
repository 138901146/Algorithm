#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int origin, descendant;
}
node;

int size=0, *child_count=NULL, **child=NULL;
node *arr=NULL;

int make_tree(int current)
{
	for(int i=0;i<child_count[current];++i)
	{
		arr[child[current][i]].origin=++size;
		arr[child[current][i]].descendant=make_tree(child[current][i]);
	}

	return arr[current].descendant=size;
}

void init(int *fruit,int *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=fruit[start];
	else
	{
		init(fruit,tree,node<<1,start,(start+end)>>1);
		init(fruit,tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
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

void update(int *tree,int node,int start,int end,int index,int value)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]+=value;
		return;
	}
	else
	{
		update(tree,node<<1,start,(start+end)>>1,index,value);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index,value);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, M, *parent=NULL, *w=NULL, *copy=NULL, *tree=NULL, tree_size=0, operation, **operation_list=NULL;

	scanf("%d%d", &N, &M);
	parent=(int *)malloc((N+M+1)*sizeof(int));
	child=(int **)malloc((N+M+1)*sizeof(int *));
	child_count=(int *)calloc(N+M+1,sizeof(int));
	w=(int *)calloc(N+M+1,sizeof(int));
	copy=(int *)malloc((N+1)*sizeof(int));
	operation_list=(int **)malloc(M*sizeof(int *));

	scanf("%d", &parent[1]);
	for(int n=2;n<=N;++n)
	{
		scanf("%d", &parent[n]);
		++child_count[parent[n]];
	}

	for(int n=1;n<=N;++n)
	{
		scanf("%d", &w[n]);
		copy[n]=w[n];
	}

	for(int m=0;m<M;++m)
	{
		scanf("%d", &operation);

		if(operation==1)
		{
			operation_list[m]=(int *)malloc(4*sizeof(int));
			for(int i=1;i<4;++i)
				scanf("%d", &operation_list[m][i]);
			++child_count[operation_list[m][1]];
		}
		else
		{
			operation_list[m]=(int *)malloc(2*sizeof(int));
			scanf("%d", &operation_list[m][1]);
		}
		operation_list[m][0]=operation;
	}

	for(int i=1;i<=N+M;++i)
	{
		child[i]=(int *)malloc(child_count[i]*sizeof(int));
		child_count[i]=0;
	}

	for(int n=2;n<=N;++n)
		child[parent[n]][child_count[parent[n]]++]=n;
	for(int m=0;m<M;++m)
		if(operation_list[m][0]==1)
			child[operation_list[m][1]][child_count[operation_list[m][1]]++]=operation_list[m][2];

	free(parent);
	arr=(node *)malloc((N+M+1)*sizeof(node));

	arr[1].origin=0;
	make_tree(1);

	for(int n=1;n<=N;++n)
		w[n]=0;

	for(int n=1;n<=N;++n)
	{
		w[arr[n].origin]=copy[n];
		free(child[n]);
	}
	free(child_count);
	free(child);
	free(copy);

	while((1<<tree_size)<size)
		++tree_size;
	tree_size=1<<++tree_size;
	tree=(int *)malloc(tree_size*sizeof(int));
	init(w,tree,1,0,size);
	free(w);

	for(int m=0;m<M;++m)
	{
		if(operation_list[m][0]==1)
			update(tree,1,0,size,arr[operation_list[m][2]].origin,operation_list[m][3]);
		else
		{
			int power=get(tree,1,0,size,arr[operation_list[m][1]].origin,arr[operation_list[m][1]].descendant);
			printf("%d\n", power?power:-1);
		}

		free(operation_list[m]);
	}

	free(operation_list);
	free(tree);
	free(arr);
	return 0;
}