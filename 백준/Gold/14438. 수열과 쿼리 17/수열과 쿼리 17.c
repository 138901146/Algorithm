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
		int l=get(tree,node<<1,start,(start+end)>>1,left,right), r=get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
		return l<r?l:r;
	}
}

void update(int *tree,int node,int start,int end,int index,int value)
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
		tree[node]=tree[node<<1]<tree[node<<1|1]?tree[node<<1]:tree[node<<1|1];
	}
}

int main(void)
{
	int N, *A=NULL, M, size=0, *tree=NULL, operation[3];

	scanf("%d", &N);
	while((1<<size)<N)
		size++;
	size++;
	A=(int *)malloc(N*sizeof(int));
	tree=(int *)calloc((1<<size),sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);

	init(A,tree,1,0,N-1);

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		for(int i=0;i<3;i++)
			scanf("%d", &operation[i]);

		if(operation[0]==1)
			update(tree,1,0,N-1,operation[1]-1,operation[2]);
		else
			printf("%d\n", get(tree,1,0,N-1,operation[1]-1,operation[2]-1));
	}

	free(A);
	free(tree);
	return 0;
}