#include<stdio.h>
#include<malloc.h>

void init(int *arr,long long *tree,int node,int start,int end)
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

void update(long long *tree,int node,int start,int end,int index,int value)
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
	int N, Q, K, size=0, *arr=NULL, operation[4];
	long long *tree=NULL;

	scanf("%d%d", &N, &Q);
	while((1<<size)<N)
		size++;
	size++;
	arr=(int *)malloc(N*sizeof(int));
	tree=(long long *)malloc((1<<size)*sizeof(long long));

	for(int n=0;n<N;n++)
		scanf("%d", &arr[n]);
	init(arr,tree,1,0,N-1);

	for(int q=0;q<Q;q++)
	{
		for(int i=0;i<4;i++)
			scanf("%d", &operation[i]);

		if(operation[0]>operation[1])
		{
			int temp=operation[0];
			operation[0]=operation[1];
			operation[1]=temp;
		}
		printf("%lld\n", get(tree,1,0,N-1,operation[0]-1,operation[1]-1));
		update(tree,1,0,N-1,operation[2]-1,operation[3]);
	}

	free(arr);
	free(tree);
	return 0;
}