#include<stdio.h>
#include<malloc.h>

long long max[2];
int N, *A=NULL, *tree=NULL;

void init(int node,int start,int end)
{
	if(start==end)
		tree[node]=start;
	else
	{
		init(node<<1,start,(start+end)>>1);
		init(node<<1|1,((start+end)>>1)+1,end);
		tree[node]=A[tree[node<<1]]>A[tree[node<<1|1]]?tree[node<<1]:tree[node<<1|1];
	}
}

int get(int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 100000000;
	else if(left<=start && end<=right)
		return tree[node];
	else
	{
		int left_child=get(node<<1,start,(start+end)>>1,left,right), right_child=get(node<<1|1,((start+end)>>1)+1,end,left,right);

		if(left_child==100000000)
			return right_child;
		else if(right_child==100000000)
			return left_child;
		else
			return A[left_child]>A[right_child]?left_child:right_child;
	}
}

void update(int *tree,int node,int start,int end,int index)
{
	if(index<start || index>end)
		return;
	else if(start==end)
		return;
	else
	{
		update(tree,node<<1,start,(start+end)>>1,index);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index);
		tree[node]=A[tree[node<<1]]>A[tree[node<<1|1]]?tree[node<<1]:tree[node<<1|1];
	}
}

void find_max(int left,int right,int depth)
{
	if(depth>1)
		return;
	if(left>right)
		return;

	int index=get(1,0,N-1,left,right);
	max[depth]=max[depth]>A[index]?max[depth]:A[index];

	find_max(left,index-1,depth+1);
	find_max(index+1,right,depth+1);
}

int main(void)
{
	int size=0, M, operation[3];

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	while((1<<size)<N)
		size++;
	size++;
	tree=(int *)malloc((1<<size)*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &A[n]);

	init(1,0,N-1);

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		for(int i=0;i<3;i++)
			scanf("%d", &operation[i]);

		operation[1]--;
		if(operation[0]==1)
		{
			A[operation[1]]=operation[2];
			update(tree,1,0,N-1,operation[1]);
		}
		else
		{
			max[0]=max[1]=-2100000000;
			find_max(operation[1],operation[2]-1,0);
			printf("%lld\n", max[0]+max[1]);
		}
	}

	free(tree);
	free(A);
	return 0;
}