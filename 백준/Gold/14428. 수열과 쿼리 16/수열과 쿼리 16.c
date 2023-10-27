#include<stdio.h>
#include<malloc.h>

int *A=NULL, *tree=NULL;

void init(int node,int start,int end)
{
	if(start==end)
		tree[node]=start;
	else
	{
		init(node<<1,start,(start+end)>>1);
		init(node<<1|1,((start+end)>>1)+1,end);
		tree[node]=A[tree[node<<1]]>A[tree[node<<1|1]]?tree[node<<1|1]:tree[node<<1];
	}
}

int get(int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return -1;
	else if(left<=start && end<=right)
		return tree[node];
	else
	{
		int left_child=get(node<<1,start,(start+end)>>1,left,right), right_child=get(node<<1|1,((start+end)>>1)+1,end,left,right);

		if(left_child==-1)
			return right_child;
		else if(right_child==-1)
			return left_child;
		else
			return A[left_child]>A[right_child]?right_child:left_child;
	}
}

void update(int node,int start,int end,int index,int value)
{
	if(index<start || index>end || start==end)
		return;
	else
	{
		update(node<<1,start,(start+end)>>1,index,value);
		update(node<<1|1,((start+end)>>1)+1,end,index,value);
		tree[node]=A[tree[node<<1]]>A[tree[node<<1|1]]?tree[node<<1|1]:tree[node<<1];
	}
}

int main(void)
{
	int N, M, size=0, operation[3];

	scanf("%d", &N);
	while((1<<size)<N)
		++size;
	++size;
	A=(int *)malloc(N*sizeof(int));
	tree=(int *)malloc((1<<size)*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);
	init(1,0,N-1);

	scanf("%d", &M);
	for(int m=0;m<M;++m)
	{
		for(int i=0;i<3;i++)
			scanf("%d", &operation[i]);

		if(operation[0]==1)
		{
			A[--operation[1]]=operation[2];
			update(1,0,N-1,operation[1],operation[2]);
		}
		else
			printf("%d\n", get(1,0,N-1,operation[1]-1,operation[2]-1)+1);
	}

	free(tree);
	free(A);
	return 0;
}