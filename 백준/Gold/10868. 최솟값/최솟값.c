#include<stdio.h>
#include<malloc.h>

void init(int *arr,int *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=arr[start];
	else
	{
		init(arr,tree,node<<1,start,(start+end)>>1);
		init(arr,tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=tree[node<<1]<tree[node<<1|1]?tree[node<<1]:tree[node<<1|1];
	}
}

int get(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 2000000000;
	else if(left<=start && end<=right)
		return tree[node];
	else
	{
		int left_child=get(tree,node<<1,start,(start+end)>>1,left,right), right_child=get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
		return left_child<right_child?left_child:right_child;
	}
}

int main(void)
{
	int N, M, size=0, *arr=NULL, *tree=NULL, a, b;

	scanf("%d%d", &N, &M);
	while((1<<size)<N)
		size++;
	size++;
	arr=(int *)malloc(N*sizeof(int));
	tree=(int *)malloc((1<<size)*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &arr[n]);

	init(arr,tree,1,0,N-1);

	for(int m=0;m<M;m++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", get(tree,1,0,N-1,a-1,b-1));
	}

	free(arr);
	free(tree);
	return 0;
}