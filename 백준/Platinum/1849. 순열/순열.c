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

int get(int *tree,int node,int start,int end,int target)
{
	if(start==end)
		return start;
	else if(target<tree[node<<1])
		return get(tree,node<<1,start,start+end>>1,target);
	else
		return get(tree,node<<1|1,(start+end>>1)+1,end,target-tree[node<<1]);
}

void update(int *tree,int node,int start,int end,int index)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]=0;
		return;
	}
	else
	{
		update(tree,node<<1,start,start+end>>1,index);
		update(tree,node<<1|1,(start+end>>1)+1,end,index);
		--tree[node];
	}
}

int main(void)
{
	int N, size=0, A, *arr=NULL, *tree=NULL;

	scanf("%d", &N);
	while((1<<size)<=N)
		++size;
	arr=(int *)malloc((N+1)*sizeof(int));
	tree=(int *)calloc(1<<++size,sizeof(int));

	init(tree,1,1,N);
	for(int n=1;n<=N;++n)
	{
		scanf("%d", &A);

		int index=get(tree,1,1,N,A);

		arr[index]=n;
		update(tree,1,1,N,index);
	}

	for(int n=1;n<=N;++n)
		printf("%d\n", arr[n]);

	free(arr);
	free(tree);
	return 0;
}