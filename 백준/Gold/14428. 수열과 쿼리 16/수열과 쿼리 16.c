#include<stdio.h>
#include<malloc.h>

void init(int *A,long long *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=(long long)start<<30|A[start];
	else
	{
		init(A,tree,node<<1,start,(start+end)>>1);
		init(A,tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=(tree[node<<1]&1073741823)<(tree[node<<1|1]&1073741823)||(tree[node<<1]&1073741823)==(tree[node<<1|1]&1073741823)&&(tree[node<<1]>>30)<(tree[node<<1|1]>>30)?tree[node<<1]:tree[node<<1|1];
	}
}

long long get(long long *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 1073741823;
	else if(left<=start && end<=right)
		return tree[node];
	else
	{
		long long left_child=get(tree,node<<1,start,(start+end)>>1,left,right), right_child=get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);

		if(left_child==1073741823)
			return right_child;
		else if(right_child==1073741823)
			return left_child;
		else
			return (left_child&1073741823)<(right_child&1073741823)||(left_child&1073741823)==(right_child&1073741823)&&(left_child>>30)<(right_child>>30)?left_child:right_child;
	}
}

void update(long long *tree,int node,int start,int end,int index,int value)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]=(long long)index<<30|value;
		return;
	}
	else
	{
		update(tree,node<<1,start,(start+end)>>1,index,value);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index,value);
		tree[node]=(tree[node<<1]&1073741823)<(tree[node<<1|1]&1073741823)||(tree[node<<1]&1073741823)==(tree[node<<1|1]&1073741823)&&(tree[node<<1]>>30)<(tree[node<<1|1]>>30)?tree[node<<1]:tree[node<<1|1];
	}
}

int main(void)
{
	int N, *A=NULL, M, size=0, operation[3];
	long long *tree=NULL;

	scanf("%d", &N);
	while((1<<size)<N)
		size++;
	size++;
	A=(int *)malloc(N*sizeof(int));
	tree=(long long *)malloc((1<<size)*sizeof(long long));

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
			printf("%lld\n", (get(tree,1,0,N-1,operation[1]-1,operation[2]-1)>>30)+1);
	}

	free(tree);
	free(A);
	return 0;
}