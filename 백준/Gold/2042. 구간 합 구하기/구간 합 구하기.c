#include<stdio.h>
#include<malloc.h>

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

long long get(long long *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,(start+end)>>1,left,right)+get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update(long long *tree,int node,int start,int end,int index,long long value)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]=value;
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
	int N, M, K, size=0;
	long long *arr=NULL, *tree=NULL, operation[3];

	scanf("%d%d%d", &N, &M, &K);
	M+=K;
	while((1<<size)<N)
		size++;
	size++;
	arr=(long long *)malloc(N*sizeof(long long));
	tree=(long long *)malloc((1<<size)*sizeof(long long));

	for(int n=0;n<N;n++)
		scanf("%lld", &arr[n]);

	init(arr,tree,1,0,N-1);

	for(int m=0;m<M;m++)
	{
		for(int i=0;i<3;i++)
			scanf("%lld", &operation[i]);

		if(operation[0]==1)
			update(tree,1,0,N-1,(int)operation[1]-1,operation[2]);
		else
			printf("%lld\n", get(tree,1,0,N-1,(int)operation[1]-1,(int)operation[2]-1));
	}

	free(arr);
	free(tree);
	return 0;
}