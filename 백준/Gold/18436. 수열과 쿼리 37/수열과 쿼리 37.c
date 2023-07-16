#include<stdio.h>
#include<malloc.h>

void init(int *A,int *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=A[start]&1;
	else
	{
		init(A,tree,node<<1,start,(start+end)>>1);
		init(A,tree,node<<1|1,((start+end)>>1)+1,end);
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
		tree[node]=value;
	else
	{
		update(tree,node<<1,start,(start+end)>>1,index,value);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index,value);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, *A=NULL, *tree=NULL, M, size=0, operation[3];

	scanf("%d", &N);
	while((1<<size)<N)
		size++;
	size++;
	A=(int *)malloc(N*sizeof(int));
	tree=(int *)malloc((1<<size)*sizeof(int));

	for(int i=0;i<N;i++)
	{
		scanf("%d", &A[i]);
		A[i]&=1;
	}
	init(A,tree,1,0,N-1);

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		for(int i=0;i<3;i++)
			scanf("%d", &operation[i]);

		if(operation[0]==1)
			update(tree,1,0,N-1,operation[1]-1,operation[2]&1);
		else if(operation[0]==2)
			printf("%d\n", operation[2]-operation[1]+1-get(tree,1,0,N-1,operation[1]-1,operation[2]-1));
		else
			printf("%d\n", get(tree,1,0,N-1,operation[1]-1,operation[2]-1));
	}

	free(tree);
	free(A);
	return 0;
}