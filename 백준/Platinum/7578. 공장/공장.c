#include<stdio.h>
#include<malloc.h>

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
		tree[node]=1;
	else
	{
		update(tree,node<<1,start,(start+end)>>1,index);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, *A=NULL, *tree=NULL, size=0, *index=calloc(1000001,sizeof(int)), data;
	long long ans=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	while((1<<size)<N)
		size++;
	size++;
	size=1<<size;

	for(int n=0;n<N;n++)
	{
		scanf("%d", &data);
		index[data]=n;
	}
	for(int n=0;n<N;n++)
	{
		scanf("%d", &data);
		A[index[data]]=n;
	}
	free(index);

	tree=(int *)calloc(size,sizeof(int));

	for(int n=0;n<N;n++)
	{
		ans+=get(tree,1,0,N-1,A[n]+1,N-1);
		update(tree,1,0,N-1,A[n]);
	}

	printf("%lld\n", ans);
	free(A);
	free(tree);
	return 0;
}